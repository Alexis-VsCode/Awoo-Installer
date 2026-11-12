# Community maintenance baseline

Target test device: Horizon OS **23.0.1**, Atmosphère **1.12.1**, Kefir **927**, emuMMC (E).

This community fork retains upstream authorship and GPL-3.0 licensing. The first branch isolates a conservative security baseline, including TLS verification, USB payload bounds, and safer defaults. The historical ZIP self-updater and external patch downloader are temporarily disabled. **Legacy ZIP extraction remains a known issue** and must be hardened before either pathway is restored.

## Release quality gates
1. Static analysis and host-side tests.
2. libnx/devkitPro cross compilation including the Plutonium submodule.
3. Human review of security-sensitive diffs.
4. Hardware launch, exit and transfer tests on emuMMC.
5. Only then label a release compatible; never infer hardware support from a successful build.

## Known remaining risks
- CFW storage/IPC compatibility is unverified for HOS 23.0.1.
- ZIP extraction and package handling require structural validation and regression tests.
- USB/HTTP transfer loops need thread synchronization, cancellation and error-propagation review.
- TLS must be tested with the certificate store provided by the Switch runtime.
- libnx 4.12.0 build compatibility is a target, not a verified fact.
- Settings persisted by older Awoo installations can retain unsafe prior options.

## Attribution
Awoo Installer by Huntereb, with significant contributions from HookedBehemoth and others. Components derived from Adubbz Tinfoil and XorTroll Plutonium retain applicable notices.
