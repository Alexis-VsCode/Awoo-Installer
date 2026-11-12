# Política de entregables y releases

La compilación del NRO, la publicación de archivos en GitHub y la **validación de funcionamiento real** son actividades distintas.

## Entregables

Una futura release comunitaria contendrá:
- Awoo-Installer.nro: aplicación para Homebrew Menu.
- Awoo-Installer.zip: binario, README y licencia en un único paquete.
- SHA256SUMS: huellas de integridad de ambos archivos.

La página [GitHub Pages](https://alexis-vscode.github.io/Awoo-Installer/) detectará nuevas releases **públicas** mediante la API de GitHub. No muestra borradores ni presenta artefactos de CI como versiones estables.

## Workflow de publicación

El workflow [Preparar release comunitaria](https://github.com/Alexis-VsCode/Awoo-Installer/actions) ya está integrado en `master` y se prepara para etiquetas nuevas que comiencen por `v`. Ejecuta validación estática, pruebas ZIP, compilación cruzada, empaquetado y hashes SHA-256.

Cuando se activa por etiqueta, crea una release **en estado borrador**. Se requiere revisión manual antes de hacerla pública. Este flujo evita anunciar compatibilidad por el simple hecho de haber compilado.

**Importante:** hasta que este workflow se ejecute con una etiqueta real y termine en verde, el flujo de publicación se considera **implementado, no verificado de extremo a extremo**.

## Criterios para publicar

1. Código revisado y pull request integrado.
2. Compilación y pruebas automatizadas correctas sobre el commit publicado.
3. Pruebas en consola registradas para la combinación de firmware declarada.
4. Análisis de errores, capacidad de recuperación y riesgos residuales.
5. Notas de cambios precisas y checksum disponible.
6. Confirmación manual del responsable del mantenimiento.

Para corregir la aplicación no es necesario actualizar el firmware de la consola. Nunca se publicarán juegos, claves, firmware ni parches de terceros desde este repositorio.

[Documentación de compilación](COMPILACION.md) · [Pruebas Kefir 927](PRUEBAS-KEFIR-927.md)

## Preparación de etiquetas

**No crear una etiqueta pública hasta aprobar la fase de pruebas en consola.** Tras registrar la evidencia y revisar el commit de distribución, desde una copia local actualizada:

```bash
git fetch origin
git switch master
git pull --ff-only origin master
git tag -a v1.3.6-community.1 -m "Candidata comunitaria: validación documentada"
git push origin v1.3.6-community.1
```

Ese nombre es un **ejemplo reservado para el futuro**, no una versión creada. El workflow construirá los artefactos y abrirá un borrador de GitHub Release que deberá revisarse antes de publicar. Para una compilación experimental sin crear una etiqueta, utiliza **Actions → Preparar release comunitaria → Run workflow**; en ese caso solo genera artefactos y no publica una release.

## Comprobación automática del paquete

El workflow de CI ahora ensaya el empaquetado en cada ejecución con pruebas unitarias y un job que ensambla el ZIP a partir del NRO compilado. El mismo script se utiliza en el workflow de releases para evitar duplicaciones. La prueba verifica también que las sumas SHA-256 coinciden con los archivos realmente entregados.

Los artefactos de CI no se muestran como descargas oficiales de GitHub Pages hasta que exista una release pública aprobada.

## Primera beta pública

El [12 de noviembre de 2026 se publicó v1.3.6-community.1-beta.1](https://github.com/Alexis-VsCode/Awoo-Installer/releases/tag/v1.3.6-community.1-beta.1) como **pre-release**, sin pruebas acreditadas en hardware real. El workflow de publicación completo terminó correctamente: verificaciones de seguridad, traducciones y ZIP, compilación cruzada, empaquetado, SHA-256 y publicación.

Los usuarios pueden dejar sus resultados en el [Issue #8](https://github.com/Alexis-VsCode/Awoo-Installer/issues/8). Una beta no equivale a una release estable ni certifica soporte para Kefir 927.
