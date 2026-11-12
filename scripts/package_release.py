#!/usr/bin/env python3
"""Genera un paquete comunitario reproducible y su manifiesto SHA-256."""
from __future__ import annotations

import argparse
import hashlib
import shutil
from pathlib import Path
from zipfile import ZIP_DEFLATED, ZipFile

ROOT = Path(__file__).resolve().parents[1]
FILES = ("Awoo-Installer.nro", "README.md", "LICENSE")


def sha256_file(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as source:
        for block in iter(lambda: source.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def package(nro: Path, destination: Path) -> None:
    if not nro.is_file() or nro.stat().st_size == 0:
        raise ValueError("El archivo NRO no existe o está vacío")
    destination.mkdir(parents=True, exist_ok=True)
    target = destination / FILES[0]
    if nro.resolve() != target.resolve():
        shutil.copyfile(nro, target)
    for filename in FILES[1:]:
        source = ROOT / filename
        if not source.is_file():
            raise FileNotFoundError(source)
        shutil.copyfile(source, destination / filename)

    zip_path = destination / "Awoo-Installer.zip"
    with ZipFile(zip_path, "w", compression=ZIP_DEFLATED, compresslevel=6) as archive:
        for filename in FILES:
            archive.write(destination / filename, arcname=filename)
    with (destination / "SHA256SUMS").open("w", encoding="utf-8", newline="\n") as manifest:
        for filename in (FILES[0], zip_path.name):
            manifest.write(f"{sha256_file(destination / filename)}  {filename}\n")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Prepara NRO, ZIP y SHA-256")
    parser.add_argument("nro", type=Path, help="Binario compilado del instalador")
    parser.add_argument("destination", type=Path, help="Carpeta de entrega")
    arguments = parser.parse_args()
    package(arguments.nro, arguments.destination)
    print("NRO, ZIP y SHA256SUMS generados correctamente")
