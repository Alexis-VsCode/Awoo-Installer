# Compilación y CI

## Herramientas

Awoo Installer Community utiliza C++17, devkitPro/devkitA64, libnx, Plutonium (submódulo fijado), SDL2 y bibliotecas de red y compresión.

**Requisito:** usar versiones compatibles con el Makefile original; no actualizar Plutonium al último commit de forma automática. Su revisión fijada contiene `Plutonium/Makefile` y genera `Plutonium/Output/lib/libpu.a`.

## Compilación automatizada

Abre [GitHub Actions](https://github.com/Alexis-VsCode/Awoo-Installer/actions), selecciona **CI - seguridad, compilación y distribución** y consulta una ejecución satisfactoria de la rama `master`.

El workflow comprueba seguridad y recursos de idioma, compila y prueba el extractor ZIP en entorno nativo, prepara Plutonium y genera `Awoo-Installer.nro`.

En la ejecución selecciona **Artifacts** y descarga `Awoo-Installer-ci-<sha>`. Es un **binario de desarrollo**, no una release certificada.

## Descargar el código

```bash
git clone --recurse-submodules https://github.com/Alexis-VsCode/Awoo-Installer.git
cd Awoo-Installer
git switch master
git submodule update --init --recursive
```

## Compilar localmente

Con el entorno devkitPro, libnx y todas las bibliotecas del proyecto correctamente instaladas:

```bash
make -j2
```

La compilación debe generar el archivo `Awoo-Installer.nro` en la raíz del proyecto. Si falla, compara versiones y dependencias contra el workflow: [`.github/workflows/ci.yml`](https://github.com/Alexis-VsCode/Awoo-Installer/blob/master/.github/workflows/ci.yml).

En Windows 11 se puede trabajar con Git y un contenedor devkitPro (Docker Desktop/WSL2), comprobando previamente que el volumen esté montado y que la imagen incluya las dependencias requeridas. No se recomienda instalar paquetes aleatorios para resolver errores de compilación.

## Integridad

```powershell
Get-FileHash .\Awoo-Installer.nro -Algorithm SHA256
```

En Linux:

```bash
sha256sum Awoo-Installer.nro
```

Conserva la suma junto al commit de origen. Las releases futuras deberán incluir un manifiesto `SHA256SUMS` para sus archivos publicados.

## Criterios para publicar

- CI satisfactorio y revisión del PR.
- Artefactos asociados a un commit/tag conocido.
- Notas de cambios que separen correcciones verificadas de riesgos conocidos.
- Validación en consola real y procedimiento de reversión.
- Una versión de prueba no debe etiquetarse como estable por haber compilado.

[Pruebas en Kefir 927](PRUEBAS-KEFIR-927.md) · [Hoja de ruta](HOJA-DE-RUTA.md)

## Artefactos automáticos de CI

Cuando el job **Integridad NRO ZIP y SHA-256** termina correctamente, la ejecución de `master` ofrece el artefacto `Awoo-Installer-distribution-<sha>` con el binario, ZIP y manifiesto `SHA256SUMS`. Es un entregable experimental de integración continua; no una release publicada ni una certificación de compatibilidad.

El empaquetado utiliza `scripts/package_release.py`, compartido con el workflow de releases y comprobado con `scripts/test_release_package.py`.
