#!/usr/bin/env python3
"""Pruebas de integración del extractor ZIP (binario C++ nativo)."""
import os
from pathlib import Path
import stat
import subprocess
import sys
import tempfile
import zipfile

exe = Path(sys.argv[1]).resolve()
checks = 0

def scenario(items, expected, existing=None):
    global checks
    with tempfile.TemporaryDirectory() as d:
        root = Path(d)
        dest = root / "destination"
        dest.mkdir()
        if existing:
            for name, content in existing.items():
                f = dest / name
                f.parent.mkdir(exist_ok=True, parents=True)
                f.write_text(content)
        archive = root / "input.zip"
        with zipfile.ZipFile(archive, "w") as z:
            for name, content in items:
                z.writestr(name, content)
        result = subprocess.run([str(exe), str(archive), str(dest) + os.sep], capture_output=True, text=True)
        assert (result.returncode == 0) == expected, (items, result.stdout, result.stderr)
        if not expected and any('..' in n or n.startswith('/') for n, _ in items):
            assert not (root / 'evil').exists()
        if existing:
            for name, content in existing.items():
                assert (dest / name).read_text() == content
        checks += 1

scenario([('a.txt', 'ok')], True)
scenario([('dir/', ''), ('dir/lang.txt', 'español')], True)
scenario([('a/b/file.txt', 'nested')], True)
scenario([('../evil', 'attack')], False)
scenario([('ok.txt', 'fine'), ('../evil', 'attack')], False)
scenario([('/abs', 'attack')], False)
scenario([('a/../../evil', 'attack')], False)
scenario([('C:/windows/file', 'attack')], False)
scenario([('a\\evil.txt', 'attack')], False)
scenario([('folder/./file.txt', 'attack')], False)
scenario([('a//b', 'attack')], False)
scenario([('ok.txt', 'new')], False, {'ok.txt': 'preserve me'})
scenario([('same.txt', 'old'), ('same.txt', 'new')], False)

with tempfile.TemporaryDirectory() as d:
    root = Path(d)
    archive = root / 'link.zip'
    dest = root / 'target'
    dest.mkdir()
    sym = zipfile.ZipInfo('shortcut')
    sym.create_system = 3
    sym.external_attr = (stat.S_IFLNK | 0o777) << 16
    with zipfile.ZipFile(archive, 'w') as z:
        z.writestr(sym, '../outside')
    result = subprocess.run([str(exe), str(archive), str(dest) + os.sep])
    assert result.returncode != 0
    checks += 1

with tempfile.TemporaryDirectory() as d:
    root = Path(d)
    archive = root / 'empty.zip'
    dest = root / 'target'
    dest.mkdir()
    with zipfile.ZipFile(archive, 'w'): pass
    result = subprocess.run([str(exe), str(archive), str(dest) + os.sep])
    assert result.returncode != 0
    checks += 1

print(f"ZIP scenarios validated: {checks}")
