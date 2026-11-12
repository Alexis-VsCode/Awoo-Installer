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
