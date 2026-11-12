# Hoja de ruta y estado de Awoo Installer Community

Revisión: 12 de noviembre de 2026. Este registro describe **evidencias verificadas**, no una estimación de compatibilidad.

| Fase | Alcance | Estado |
| --- | --- | --- |
| F0 | Fork, atribuciones, README y sitio web | Completado |
| F1 | Correcciones iniciales TLS, USB, configuración y ZIP | Integradas en master mediante PR #1 fusionado |
| F1 | Tests estáticos, ZIP y compilación devkitPro | Aprobados en PR #1; CI de master bajo seguimiento |
| F2 | Revisión NCA/NCZ, memoria, almacenamiento y concurrencia | Pendiente |
| F2 | Inicio, interfaz, SD, USB y red en HOS 23.0.1 / AMS 1.12.1 / Kefir 927 | Pendiente |
| F3 | Primera beta pública con NRO, ZIP, SHA-256 y advertencias | Publicada; pruebas comunitarias abiertas (#8) |
| F4 | Versión estable tras validación y rollback | Pendiente |

## Bloqueantes antes de publicar estable

- PR [#1](https://github.com/Alexis-VsCode/Awoo-Installer/pull/1) **fusionado**. No quedan bloqueos de integración de la primera línea base.
- Pendiente revisión del procesamiento NCA/NCZ y bucles de transferencia/cancelación.
- Pendientes pruebas reales en emuMMC.
- Workflow de beta pública ejecutado correctamente y comprobados NRO, ZIP y SHA-256. **La publicación de una release estable sigue bloqueada** hasta finalizar las pruebas de consola y las revisiones de seguridad.

## Política de compatibilidad

Se declara soporte únicamente para combinaciones probadas, identificando firmware, Atmosphère, Kefir y modo de arranque. El entorno de referencia **no equivale** a compatibilidad certificada. Cualquier versión posterior de Horizon OS se trata como **no validada** hasta disponer de pruebas.

## Próxima intervención

1. [Revisar NCA/NCZ y memoria](https://github.com/Alexis-VsCode/Awoo-Installer/issues/3) y [USB/HTTP](https://github.com/Alexis-VsCode/Awoo-Installer/issues/4).
2. [Ejecutar matriz en emuMMC 23.0.1](https://github.com/Alexis-VsCode/Awoo-Installer/issues/2).
3. [Recopilar resultados en la beta pública](https://github.com/Alexis-VsCode/Awoo-Installer/issues/8) y [validar el proceso hacia una versión estable](https://github.com/Alexis-VsCode/Awoo-Installer/issues/5).
4. Revisión comunitaria y etiquetado estable cuando se cumplan los criterios.

[Estado del CI](https://github.com/Alexis-VsCode/Awoo-Installer/actions) · [Pull Request #1](https://github.com/Alexis-VsCode/Awoo-Installer/pull/1) · [Inicio](../README.md)
