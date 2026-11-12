#!/usr/bin/env python3
"""Verifica los recursos de traducción incluidos en la aplicación."""
import json
from pathlib import Path

root = Path(__file__).resolve().parents[1]
lang_dir = root / "romfs" / "lang"
languages = sorted(lang_dir.glob("*.json"))
assert languages, "No se encontraron idiomas"
resources = {p.name: json.loads(p.read_text(encoding="utf-8")) for p in languages}
base = resources["en.json"]
spanish = resources["es-419.json"]

def keys(value, prefix=""):
    result = set()
    for key, item in value.items():
        path = f"{prefix}.{key}" if prefix else key
        if isinstance(item, dict):
            result.update(keys(item, path))
        else:
            result.add(path)
    return result

required = {"community.title", "community.update_disabled", "community.patches_disabled"}
assert required <= keys(base), "Mensajes nuevos no disponibles en inglés"
assert required <= keys(spanish), "Mensajes nuevos no disponibles en español"
for name, data in resources.items():
    assert isinstance(data, dict), f"Formato inválido: {name}"
missing = keys(base) - keys(spanish)
if missing:
    raise SystemExit(f"El español tiene {len(missing)} claves pendientes: {sorted(missing)[:15]}")
print(f"Traducciones válidas: {len(resources)} idiomas; español sin claves faltantes.")
