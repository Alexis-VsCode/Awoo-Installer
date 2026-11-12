# Política de entregables y releases

La compilación del NRO, la publicación de archivos en GitHub y la **validación de funcionamiento real** son actividades distintas.

## Entregables

Una futura release comunitaria contendrá:
- Awoo-Installer.nro: aplicación para Homebrew Menu.
- Awoo-Installer.zip: binario, README y licencia en un único paquete.
- SHA256SUMS: huellas de integridad de ambos archivos.

La página [GitHub Pages](https://alexis-vscode.github.io/Awoo-Installer/) detectará nuevas releases **públicas** mediante la API de GitHub. No muestra borradores ni presenta artefactos de CI como versiones estables.

## Workflow de publicación

El workflow [Preparar release comunitaria](https://github.com/Alexis-VsCode/Awoo-Installer/actions) está definido en la rama de modernización y se prepara para futuras etiquetas que comiencen por v. Ejecuta validación estática, pruebas ZIP, compilación cruzada, empaquetado y hashes SHA-256.

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
