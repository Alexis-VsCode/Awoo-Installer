# Awoo Installer Community

**Fork comunitario de [Awoo Installer](https://github.com/Huntereb/Awoo-Installer), mantenido por [Alexis-VsCode](https://github.com/Alexis-VsCode).** Proyecto abierto, gratuito y sin fines de lucro.

[**Página web y descargas**](https://alexis-vscode.github.io/Awoo-Installer/) · [**Releases**](https://github.com/Alexis-VsCode/Awoo-Installer/releases) · [**Incidencias**](https://github.com/Alexis-VsCode/Awoo-Installer/issues)

> **Estado: desarrollo.** No hay todavía un binario comunitario certificado para Nintendo Switch. El fork conserva código heredado, pero una compilación correcta no garantiza compatibilidad con firmware reciente.

## Propósito

Dar continuidad a Awoo Installer mediante correcciones de seguridad, compatibilidad, estabilidad, documentación y compilaciones verificables. Nuestro aporte consiste en mantenimiento y mejoras propias registradas mediante commits y pull requests. **No afirmamos haber creado el software original.**

## Referencia de compatibilidad

- Horizon OS: **23.0.1**
- Atmosphère: **1.12.1**
- Kefir: **927**
- Entorno de pruebas: **emuMMC (E)**

Estas versiones son el objetivo de validación; **todavía no se ha confirmado funcionamiento del fork en una consola real**. No distribuimos Atmosphère, Kefir ni firmware de la consola.

## Funcionalidad heredada

El instalador original incluye exploración de microSD, transferencia por USB y red local, así como procesamiento de archivos NSP/NSZ/XCI/XCZ. Son funcionalidades existentes en el código, no una certificación de este fork. Todo su comportamiento debe evaluarse antes de etiquetar una versión como estable.

## Mejoras en desarrollo

- Verificación de certificados TLS para conexiones HTTP seguras.
- Validación de límites y tamaños de los paquetes transferidos por USB.
- Correcciones en gestión de errores de red y valores predeterminados conservadores.
- Revisión de memoria, lectura de archivos y escritura en almacenamiento.
- Actualizador ZIP y descargas externas de parches temporalmente deshabilitados mientras se implementan verificaciones de integridad y recuperación.
- Automatización con GitHub Actions, devkitPro/libnx y Plutonium.
- Documentación y sitio web en español, con compatibilidad declarada según pruebas.

Consulta el [pull request de modernización](https://github.com/Alexis-VsCode/Awoo-Installer/pull/1) para revisar los cambios. Por seguridad, sigue en **borrador** hasta completar la compilación y las pruebas funcionales.

## Compilación y publicación

El proyecto utiliza C++17, devkitPro/devkitA64, libnx, SDL2 y Plutonium. El objetivo del flujo de integración es construir el `.nro` y comprobar su integridad. Para publicar una versión estable exigimos controles estáticos, compilación completa, revisión de código y validación en emuMMC real. Las futuras releases contendrán, según corresponda, `.nro`, `.zip`, hashes SHA-256 y notas de cambios.

## Reportar un problema

Incluye firmware, Atmosphère, distribución CFW, emuMMC o sysMMC, método de apertura, pasos para reproducirlo y mensaje de error. No publiques secretos, claves ni contenido protegido.

## Créditos y agradecimientos

Este proyecto **parte del trabajo de la comunidad original**. Queremos reconocer expresamente:

- **[Huntereb](https://github.com/Huntereb)**, autor del repositorio y proyecto Awoo Installer.
- **[HookedBehemoth](https://github.com/HookedBehemoth)**, responsable de numerosas contribuciones a Awoo Installer y componentes asociados.
- **[Adubbz](https://github.com/Adubbz)** y colaboradores de [Tinfoil](https://github.com/Adubbz/Tinfoil), por la base técnica reutilizada.
- **[XorTroll](https://github.com/XorTroll)** y colaboradores de [Plutonium](https://github.com/XorTroll/Plutonium), por la biblioteca de interfaz.
- **nicoboss**, **blawar** y colaboradores del proyecto [NSZ](https://github.com/nicoboss/nsz).
- Las comunidades **AtlasNX** y **RetroNX**, traductores y colaboradores que aportaron correcciones y reportes.
- **namako8982**, acreditado en el proyecto original por sus recursos gráficos históricos.

Agradecemos a todas las personas que construyeron y mantuvieron Awoo Installer. Los créditos aquí mencionados son un resumen; **el historial completo y los avisos originales de licencia permanecen en el repositorio**.

**Responsable del mantenimiento de este fork:** [Alexis-VsCode](https://github.com/Alexis-VsCode). Sus aportes quedan registrados y diferenciados de la autoría original.

## Licencia y alcance

[GNU GPL v3.0](LICENSE). Proyecto comunitario independiente, sin fines de lucro ni afiliación con Nintendo, Kefir, Atmosphère o los desarrolladores originales. No distribuimos juegos, claves, firmware ni parches de terceros. Utiliza el software únicamente con contenido cuyo uso esté autorizado.
