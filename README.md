# Awoo Installer Community

**Continuidad comunitaria de Awoo Installer para Nintendo Switch.**

[Portal del proyecto](https://alexis-vscode.github.io/Awoo-Installer/) · [Código fuente](https://github.com/Alexis-VsCode/Awoo-Installer) · [Descargas](https://github.com/Alexis-VsCode/Awoo-Installer/releases) · [Incidencias](https://github.com/Alexis-VsCode/Awoo-Installer/issues) · [Contribuir](CONTRIBUTING.md)

> **Estado del proyecto:** línea base de modernización integrada en `master` mediante el [PR #1](https://github.com/Alexis-VsCode/Awoo-Installer/pull/1). Las pruebas automatizadas del PR y la compilación del NRO fueron aprobadas. El soporte en consola real sigue pendiente de verificación; todavía no hay una release comunitaria estable.

## Presentación

Este repositorio es un **fork de [Awoo Installer](https://github.com/Huntereb/Awoo-Installer)**. Conserva su historial y su licencia y busca mantener el proyecto utilizable mediante correcciones verificables, revisión de dependencias, mejoras de seguridad y documentación accesible.

La prioridad es una evolución **incremental**, respetuosa con el código original y centrada en la estabilidad. Cada cambio debe poder revisarse, probarse y revertirse.

**Responsable del fork:** [Alexis-VsCode](https://github.com/Alexis-VsCode), mantenedor de esta edición comunitaria y promotor de las correcciones y mejoras desarrolladas en ella. La autoría del programa original pertenece a sus creadores; las contribuciones posteriores quedan diferenciadas en los commits y pull requests.

## Compatibilidad: referencia de validación

| Componente | Entorno de referencia | Estado |
| --- | --- | --- |
| Horizon OS | 23.0.1 | Pendiente de pruebas en consola |
| Atmosphère | 1.12.1 | Pendiente de pruebas en consola |
| Distribución | Kefir 927 | Pendiente de pruebas en consola |
| Arranque | emuMMC (E) | Confirmado como entorno previsto |
| Compilación C++ / devkitPro | GitHub Actions | Aprobada en el PR #1 (integrado en master) |
| Pruebas de rutas ZIP y seguridad | GitHub Actions | Aprobadas en el PR #1 (integrado en master) |

**Importante:** la compilación satisfactoria no demuestra compatibilidad funcional ni autoriza actualizar el firmware de la consola. No se ha certificado Horizon OS 23.5.0.

[Guía de pruebas en Kefir 927](docs/PRUEBAS-KEFIR-927.md) · [Hoja de ruta y estado](docs/HOJA-DE-RUTA.md)

## Funcionalidad del proyecto original

El código heredado de Awoo contempla exploración de archivos en la tarjeta SD, transferencias por USB y LAN, descargas remotas y procesamiento de paquetes NSP, NSZ, XCI y XCZ. Esta relación es descriptiva; **no supone que todas esas funciones hayan sido verificadas en el fork ni en el firmware de referencia**.

Se recomienda utilizar únicamente software y contenido para el que se disponga de autorización. Esta edición no distribuye juegos, firmware, claves ni componentes de terceros para eludir medidas de seguridad.

## Aportes de mantenimiento

La rama principal [`master`](https://github.com/Alexis-VsCode/Awoo-Installer/tree/master) incluye las siguientes mejoras integradas mediante el [PR #1](https://github.com/Alexis-VsCode/Awoo-Installer/pull/1):

- Restablecimiento de validación TLS en las rutas de red revisadas.
- Controles de tamaño de transferencia por USB y correcciones de errores de conexión.
- Revisión del extractor ZIP, comprobación de rutas y pruebas de regresión.
- Tratamiento conservador de opciones automáticas, configuración heredada y avisos localizados.
- Compilación automatizada de Plutonium y Awoo mediante devkitPro, con publicación de artefactos de CI.
- Validación automatizada de mensajes en español e inglés.

Algunas funciones de actualización y descarga externa de parches permanecen **deshabilitadas temporalmente** durante el endurecimiento. Quedan pendientes revisiones adicionales de memoria, concurrencia, almacenamiento y compatibilidad de las API utilizadas por el instalador.

El [**Pull Request #1**](https://github.com/Alexis-VsCode/Awoo-Installer/pull/1) quedó **fusionado**, con revisión técnica en español y CI aprobado. Los bloqueos para una release estable se siguen mediante los [Issues #2–#7](https://github.com/Alexis-VsCode/Awoo-Installer/issues).

## Documentación

| Documento | Contenido |
| --- | --- |
| [Compilación y CI](docs/COMPILACION.md) | Entorno de herramientas, submódulos, comandos y artefactos |
| [Pruebas de compatibilidad](docs/PRUEBAS-KEFIR-927.md) | Casos de prueba, evidencias y rollback |
| [Arquitectura y criterios técnicos](docs/ARQUITECTURA.md) | Stack, responsabilidades, riesgos y criterios de diseño |
| [Hoja de ruta](docs/HOJA-DE-RUTA.md) | Fases, pendientes y condiciones para publicar |
| [Historial de cambios](CHANGELOG.md) | Cambios propuestos y versiones publicadas |
| [Guía de contribución](CONTRIBUTING.md) | Flujo de trabajo, calidad y revisión |
| [Política de seguridad](SECURITY.md) | Reportes de vulnerabilidades y soporte |

## Créditos y agradecimientos

**Awoo Installer existe gracias al trabajo de sus autores y colaboradores originales.** Este fork reconoce expresamente:

- **[Huntereb](https://github.com/Huntereb/Awoo-Installer):** autor del proyecto y repositorio original.
- **[HookedBehemoth](https://github.com/HookedBehemoth):** contribuciones relevantes al desarrollo y mantenimiento de Awoo Installer.
- **[Adubbz](https://github.com/Adubbz/Tinfoil)** y colaboradores de **Tinfoil:** componentes y código de referencia reutilizados por el proyecto original.
- **[XorTroll](https://github.com/XorTroll/Plutonium)** y colaboradores de **Plutonium:** biblioteca de interfaz gráfica.
- **blawar**, **nicoboss** y colaboradores de **NSZ:** aportes reconocidos por el proyecto original.
- **[PabloPerezRodriguez](https://github.com/PabloPerezRodriguez):** contribución histórica a la traducción española, reconocida en las notas de la versión 1.3.4.
- Comunidades **AtlasNX**, **RetroNX**, traductores, personas que reportaron errores y demás colaboradores documentados en el historial.
- **[namako8982](https://www.pixiv.net/member.php?id=14235616):** recurso gráfico histórico acreditado en el README original. Esta edición usa una identidad visual diferente en su sitio web.

La lista es un reconocimiento resumido y **no sustituye el historial de contribuciones ni el README histórico**; ambos pueden consultarse en [el repositorio de origen](https://github.com/Huntereb/Awoo-Installer) y sus publicaciones. Agradecemos a todas las personas que hicieron posible el proyecto.

### Mantenimiento de esta edición

**[Alexis-VsCode](https://github.com/Alexis-VsCode)** — responsable del fork, su dirección técnica, documentación, revisiones y continuidad. Los aportes nuevos se identifican por archivo, commit y pull request. Otros desarrolladores que contribuyan serán acreditados mediante el historial de GitHub.

## Licencias y transparencia

Este repositorio conserva la licencia original [**GNU GPL-3.0**](LICENSE), así como los avisos aplicables a componentes heredados, incluido [Tinfoil.LICENSE](Tinfoil.LICENSE). El proyecto es independiente, sin fines de lucro y no está afiliado con Nintendo, Atmosphère, Kefir ni sus equipos.

**Estado de distribución:** hasta que la revisión y las pruebas de hardware se completen, los archivos generados por CI son **artefactos experimentales**, no una release estable.
