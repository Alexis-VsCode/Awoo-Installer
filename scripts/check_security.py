#!/usr/bin/env python3
"""Reviewable, deterministic source guards. Not a replacement for hardware tests."""
from pathlib import Path
import re

root = Path(__file__).resolve().parents[1]
for file in ("source/util/curl.cpp", "source/util/network_util.cpp"):
    src = (root / file).read_text()
    assert not re.search(r"CURLOPT_SSL_VERIFYPEER\s*,\s*(?:0L|false|0)\s*\)", src), file
    assert "CURLOPT_SSL_VERIFYHOST, 2L" in src, file
for file in ("source/install/usb_nsp.cpp", "source/install/usb_xci.cpp"):
    src = (root / file).read_text()
    assert "header.dataSize != size" in src, file
    assert "header.dataSize != args->ncaSize" in src, file
config = (root / "source/util/config.cpp").read_text()
assert "autoUpdate = false" in config
assert "ignoreReqVers = false" in config
assert "gAuthKey.clear();" in config
assert "m_serverSocket < 0" in (root / "source/netInstall.cpp").read_text()
print("Source guards passed. Switch compilation and hardware validation remain required.")
