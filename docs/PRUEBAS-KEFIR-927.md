# Plan de pruebas: Kefir 927

**Entorno objetivo:** Horizon OS **23.0.1** · Atmosphère **1.12.1** · Kefir **927** · **emuMMC (E)**.

**Estado:** compilación y pruebas automáticas satisfactorias en la rama de trabajo. No se ha registrado una prueba completa en la consola.

## Preparación

1. Confirma exactamente `23.0.1 | AMS 1.12.1 | E` en la consola.
2. Conserva una copia de la SD, una copia anterior de Awoo y tus respaldos existentes de emuMMC.
3. Descarga el artefacto de una ejecución [GitHub Actions](https://github.com/Alexis-VsCode/Awoo-Installer/actions) satisfactoria de la rama de modernización.
4. Extrae `Awoo-Installer.nro`; resguarda el binario anterior y sitúa el nuevo en `sdmc:/switch/Awoo-Installer/Awoo-Installer.nro`.
5. Prueba primero sin conexión y sin instalar contenido, mediante Homebrew Menu con los permisos de memoria adecuados.

**No modifiques sysMMC ni actualices el firmware para realizar estas pruebas.**

## Matriz de pruebas

| Caso | Verificación | Estado |
| --- | --- | --- |
| Inicio | Abre sin error y muestra la interfaz | Pendiente |
| Idioma | Español, cambio de idioma y mensajes nuevos | Pendiente |
| Navegación SD | Muestra archivos y carpetas sin bloquearse | Pendiente |
| Configuración | Persiste y migra valores existentes | Pendiente |
| Salida repetida | Tres ciclos de inicio/cierre | Pendiente |
| USB | Detección, conexión/desconexión y manejo de errores | Pendiente |
| Red | Inicio, errores de conectividad y certificados | Pendiente |
| Archivos de prueba | Rechaza rutas inválidas y datos malformados | Pendiente |
| Instalación autorizada | Comportamiento correcto, espacio, errores | Pendiente |
| Recuperación | Restaurar binario y ajustes anteriores | Pendiente |

## Evidencia de fallo

Abre un [issue](https://github.com/Alexis-VsCode/Awoo-Installer/issues) e indica: versión exacta del NRO y commit, HOS/AMS/Kefir, E/S, forma de inicio, pasos para reproducir, resultado esperado y obtenido, y errores visibles. Evita archivos privados, claves, tickets y material protegido.

## Rollback

Si el programa se bloquea, retira únicamente el NRO de pruebas, restaura la copia anterior y revierte cualquier cambio de configuración respaldado. No sustituyas Atmosphère, Kefir, Hekate ni firmware como respuesta a un error de la aplicación.

La compatibilidad solo se documentará como confirmada cuando existan evidencias repetibles y no queden fallos críticos.

[Compilación](COMPILACION.md) · [Hoja de ruta](HOJA-DE-RUTA.md)
