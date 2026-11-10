# Guía para contribuir

Awoo Installer Community mantiene el código heredado de Awoo Installer con un flujo de cambios pequeño, comprobable y respetuoso con sus autores.

## Antes de empezar

1. Consulta [la hoja de ruta](docs/HOJA-DE-RUTA.md), los [issues](https://github.com/Alexis-VsCode/Awoo-Installer/issues) y los [pull requests](https://github.com/Alexis-VsCode/Awoo-Installer/pulls) para evitar trabajo duplicado.
2. Describe el defecto con pasos reproducibles y adjunta registros pertinentes **sin claves, identificadores sensibles ni contenido protegido**.
3. Para cambios de arquitectura o dependencias, plantea primero el problema que resuelven y los riesgos de compatibilidad.

## Flujo de desarrollo

- Crea una rama descriptiva, por ejemplo `fix/usb-transfer-bounds`, `fix/zip-path-validation` o `docs/guia-es`.
- Respeta C++17, el estilo existente y el funcionamiento del proyecto original. Prefiere modificaciones acotadas, funciones claras y recursos gestionados por RAII donde sea viable.
- No introduzcas patrones o capas nuevos sin una necesidad demostrable. Evita cambios masivos de formato mezclados con correcciones funcionales.
- Añade o actualiza pruebas para cada corrección. Documenta casos límite, errores y comportamiento de recuperación.
- Si modificas mensajes visibles, utiliza `romfs/lang` y completa las claves nuevas en español e inglés, con respaldo razonable para otros idiomas.
- Ejecuta las verificaciones locales posibles y comprueba el resultado de GitHub Actions antes de solicitar revisión.

## Commits y pull requests

Utiliza mensajes claros: `fix(usb): validate response length`, `docs: completar guía de instalación`, `test(zip): reject traversal paths`.

Cada pull request debe contener: descripción, causa, cambios, impacto en compatibilidad, pruebas realizadas, riesgos residuales y rollback. Usa la [plantilla de PR](.github/pull_request_template.md).

**No se fusionan cambios con CI fallido ni se publican versiones estables sin validación en hardware.** Mantén el PR en borrador cuando haya verificaciones pendientes.

## Seguridad y calidad

Nunca incorpores claves, tokens, contraseñas, firmware, paquetes comerciales, material sin licencia o descargas externas sin procedencia y verificación. Las vulnerabilidades deben notificarse según [SECURITY.md](SECURITY.md), evitando exponer detalles explotables en público.

## Reconocimiento

Las contribuciones se atribuyen por el historial de commits y PRs. Se conserva el crédito de los autores originales y el cumplimiento de las licencias heredadas. Contribuir no implica transferir la autoría del proyecto original.
