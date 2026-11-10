# Hoja de ruta y estado de Awoo Installer Community

Revisión: 10 de noviembre de 2026. Este registro describe **evidencias verificadas**, no una estimación de compatibilidad.

| Fase | Alcance | Estado |
| --- | --- | --- |
| F0 | Fork, atribuciones, README y sitio web | Completado |
| F1 | Correcciones iniciales TLS, USB, configuración y ZIP | Implementadas en PR #1 |
| F1 | Tests estáticos, ZIP y compilación devkitPro | Aprobados en CI |
| F2 | Revisión NCA/NCZ, memoria, almacenamiento y concurrencia | Pendiente |
| F2 | Inicio, interfaz, SD, USB y red en HOS 23.0.1 / AMS 1.12.1 / Kefir 927 | Pendiente |
| F3 | Release candidate con NRO, ZIP, SHA-256, notas y guía | Pendiente |
| F4 | Versión estable tras validación y rollback | Pendiente |

## Bloqueantes antes de publicar estable

- PR [#1](https://github.com/Alexis-VsCode/Awoo-Installer/pull/1) aún en **borrador**.
- Pendiente revisión del procesamiento NCA/NCZ y bucles de transferencia/cancelación.
- Pendientes pruebas reales en emuMMC.
- Pendiente mecanismo definitivo de publicación con integridad de artefactos.

## Política de compatibilidad

Se declara soporte únicamente para combinaciones probadas, identificando firmware, Atmosphère, Kefir y modo de arranque. El entorno de referencia **no equivale** a compatibilidad certificada. Cualquier versión posterior de Horizon OS se trata como **no validada** hasta disponer de pruebas.

## Próxima intervención

1. Cerrar revisión de memoria y NCA/NCZ.
2. Ejecutar matriz en emuMMC 23.0.1.
3. Publicar una candidata de prueba y comprobar el procedimiento de descarga/rollback.
4. Revisión comunitaria y etiquetado estable cuando se cumplan los criterios.

[Estado del CI](https://github.com/Alexis-VsCode/Awoo-Installer/actions) · [Pull Request #1](https://github.com/Alexis-VsCode/Awoo-Installer/pull/1) · [Inicio](../README.md)
