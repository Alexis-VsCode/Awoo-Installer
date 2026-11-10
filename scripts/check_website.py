#!/usr/bin/env python3
"""Comprobaciones estáticas del portal GitHub Pages (sin dependencias Python)."""
from html.parser import HTMLParser
from pathlib import Path
import re
import subprocess
import tempfile

repo = Path(__file__).resolve().parents[1]
site = repo / "docs" / "index.html"
html = site.read_text(encoding="utf-8")

class Inspect(HTMLParser):
    def __init__(self):
        super().__init__(convert_charrefs=True)
        self.ids = set()
        self.duplicates = []
        self.local_links = []
        self.external_links = []
        self.images = []
    def handle_starttag(self, tag, attrs):
        values = dict(attrs)
        ident = values.get("id")
        if ident:
            if ident in self.ids:
                self.duplicates.append(ident)
            self.ids.add(ident)
        if tag == "a":
            url = values.get("href", "")
            if url.startswith("#"):
                self.local_links.append(url[1:])
            elif url.startswith("https://"):
                self.external_links.append(url)
        elif tag == "img":
            self.images.append(values)

parser = Inspect()
parser.feed(html)
assert not parser.duplicates, f"IDs duplicados: {parser.duplicates}"
missing = sorted(set(parser.local_links) - parser.ids)
assert not missing, f"Anclas internas sin destino: {missing}"
required_ids = {"descargar", "capturas", "compatibilidad", "mejoras", "documentacion", "actividad", "creditos"}
assert required_ids <= parser.ids, f"Faltan secciones: {required_ids-parser.ids}"
assert len(parser.images) >= 2, "Faltan las capturas de pantalla"
for entry in parser.images:
    assert entry.get("alt"), "Todas las imágenes deben tener descripción alternativa"
    assert entry.get("src", "").startswith("https://"), "La imagen debe usar HTTPS"
assert not re.search(r"https?://(localhost|127\.0\.0\.1)", html), "Enlace local no apto para Pages"
assert "innerHTML" not in html, "No interpolar datos externos mediante innerHTML"
assert "releases?per_page" in html and "issues/comments?" in html and "commits?sha=" in html
for link in re.findall(r'href="https://github.com/Alexis-VsCode/Awoo-Installer/blob/master/(docs/[^"]+\.md|CONTRIBUTING\.md|CHANGELOG\.md)"', html):
    assert (repo / link).is_file(), f"Documento enlazado no existe: {link}"
scripts = re.findall(r"<script[^>]*>([\s\S]*?)</script>", html)
assert len(scripts) == 1, "Se espera un script JavaScript propio"
with tempfile.TemporaryDirectory() as temp:
    code = Path(temp) / "pages.js"
    code.write_text(scripts[0], encoding="utf-8")
    subprocess.run(["node", "--check", str(code)], check=True)
print(f"Portal verificado: {len(parser.ids)} IDs, {len(parser.images)} capturas, JavaScript válido.")
