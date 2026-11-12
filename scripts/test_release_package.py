#!/usr/bin/env python3
"""Prueba del empaquetador con un binario de prueba, sin Nintendo Switch."""
import hashlib
import subprocess
import sys
import tempfile
from pathlib import Path
from zipfile import ZipFile

root = Path(__file__).resolve().parents[1]
with tempfile.TemporaryDirectory() as directory:
    work = Path(directory)
    source = work / "input.nro"
    source.write_bytes(b"NRO0" + bytes(range(256)) * 5)
    target = work / "entrega"
    subprocess.run(
        [sys.executable, str(root / "scripts" / "package_release.py"), str(source), str(target)],
        check=True,
    )
    files = {"Awoo-Installer.nro", "Awoo-Installer.zip", "SHA256SUMS"}
    assert files <= {p.name for p in target.iterdir()}
    with ZipFile(target / "Awoo-Installer.zip") as archive:
        assert set(archive.namelist()) == {"Awoo-Installer.nro", "README.md", "LICENSE"}
        assert archive.read("Awoo-Installer.nro") == source.read_bytes()

    manifest = (target / "SHA256SUMS").read_text(encoding="utf-8").strip().splitlines()
    assert len(manifest) == 2
    for line in manifest:
        digest, filename = line.split(maxsplit=1)
        assert digest == hashlib.sha256((target / filename).read_bytes()).hexdigest()
print("Prueba de empaquetado NRO/ZIP/SHA-256 superada")
