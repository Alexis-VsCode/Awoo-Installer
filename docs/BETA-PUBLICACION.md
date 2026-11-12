# Awoo Installer Community v1.3.6-community.1-beta.1

**BETA PÚBLICA — PROYECTO COMUNITARIO NO OFICIAL**

Esta versión se ofrece a personas voluntarias para recibir informes de errores y recopilar evidencias de compatibilidad. **No está certificada ni ha sido validada en hardware real por el mantenedor. No es una versión estable.**

## Base técnica incorporada

- Fork de Awoo Installer con el historial original, licencia GPL-3.0 y reconocimientos a Huntereb, HookedBehemoth y demás colaboradores.
- Validaciones de tamaños USB y correcciones en manejo de errores de red.
- Restablecimiento de verificación TLS en componentes revisados.
- Extracción ZIP con límites y rechazo de rutas peligrosas, incluyendo enlaces simbólicos preexistentes.
- Mensajes comunitarios en español e inglés, con respaldo de traducción.
- Compilación con devkitPro y Plutonium fijado, pruebas de seguridad y empaquetado NRO, ZIP y SHA-256.

## Compatibilidad experimental

**Objetivo de pruebas, no certificación:** Horizon OS 23.0.1 · Atmosphère 1.12.1 · Kefir 927 · emuMMC (E).

No se garantiza compatibilidad con otros firmwares, distribuciones, hardware o modos de arranque. No se recomienda actualizar la consola para utilizar esta beta.

## Riesgos y funciones pendientes

- La revisión de procesamiento NCA/NCZ y seguridad de memoria continúa en [#3](https://github.com/Alexis-VsCode/Awoo-Installer/issues/3).
- La concurrencia, cancelación de transferencias USB/HTTP y confianza en certificados en consola siguen bajo revisión en [#4](https://github.com/Alexis-VsCode/Awoo-Installer/issues/4).
- Los flujos de instalación no cuentan aún con resultados funcionales registrados en hardware real, según [#2](https://github.com/Alexis-VsCode/Awoo-Installer/issues/2).
- La actualización ZIP automática y las descargas externas de parches continúan deshabilitadas provisionalmente.
- Pueden producirse errores de inicio, bloqueos, fallos de instalación o corrupción de datos. Realiza respaldos y evita operaciones de riesgo sobre datos importantes.

## Archivos de esta beta

- `Awoo-Installer.nro`: compilación experimental para Homebrew Menu.
- `Awoo-Installer.zip`: NRO, README y licencia.
- `SHA256SUMS`: suma SHA-256 para comprobar integridad de los archivos publicados.

Compara la suma SHA-256 después de descargar el paquete. No compartas copias alteradas como si fueran una versión oficial.

## Cómo colaborar y reportar errores

1. Conserva una copia funcional del NRO anterior y los respaldos necesarios. Utiliza **emuMMC** si corresponde a tu entorno de pruebas.
2. Anota la versión de HOS, Atmosphère, Kefir, modelo de consola, forma de ejecutar Homebrew Menu y versión exacta de esta beta.
3. Prueba **primero** apertura, español, navegación SD, lectura de ajustes, cierre y reconexión; deja las operaciones de instalación para un entorno controlado con archivos autorizados.
4. Reporta en [GitHub Issues](https://github.com/Alexis-VsCode/Awoo-Installer/issues/new/choose), con pasos de reproducción, comportamiento esperado, comportamiento observado y registros anonimizados.
5. Para confirmar funcionamiento en Kefir 927, deja los resultados en [la matriz de compatibilidad #2](https://github.com/Alexis-VsCode/Awoo-Installer/issues/2).
6. Si ocurre un fallo, restaura el NRO anterior. **No cambies sysMMC ni firmware para solucionar una incidencia de esta beta.**

No incluyas claves, certificados privados, material protegido ni información personal en los reportes. Para vulnerabilidades utiliza [SECURITY.md](https://github.com/Alexis-VsCode/Awoo-Installer/blob/master/SECURITY.md).

## Créditos

Awoo Installer original: [Huntereb](https://github.com/Huntereb/Awoo-Installer), HookedBehemoth y la comunidad. Incluye componentes derivados o relacionados con Tinfoil (Adubbz) y Plutonium (XorTroll) conforme a sus licencias. El fork y sus mejoras de mantenimiento son gestionados por [Alexis-VsCode](https://github.com/Alexis-VsCode). Todos los créditos del proyecto original se conservan.
