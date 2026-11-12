# Línea base de mantenimiento comunitario

**Entorno objetivo:** Horizon OS 23.0.1 · Atmosphère 1.12.1 · Kefir 927 · emuMMC (E).

## Estado al 12 de noviembre de 2026

El [PR #1](https://github.com/Alexis-VsCode/Awoo-Installer/pull/1) fue fusionado en `master` con pruebas automatizadas aprobadas. Incluye verificación TLS en componentes revisados, validaciones de tamaño USB, configuración conservadora, mensajes traducidos y endurecimiento de extracción ZIP con pruebas.

Las funciones de actualización ZIP interna y descarga externa de parches continúan deshabilitadas. La protección ZIP incluye validación de rutas y rechazo de enlaces simbólicos preexistentes; no constituye una garantía de transacción integral ni elimina los riesgos de almacenamiento en consola.

## Condiciones para una versión estable

1. Revisiones adicionales de NCA/NCZ, memoria, sincronización y gestión de errores.
2. Validación funcional en emuMMC de referencia.
3. Verificación de certificados reales en el entorno Switch.
4. Pipeline de empaquetado NRO, ZIP y SHA-256 verificado con una ejecución representativa.
5. Notas de cambios, riesgos, respaldo y rollback disponibles.
6. Aprobación explícita del responsable del mantenimiento.

## Documentación canónica

- [Arquitectura y riesgos](ARQUITECTURA.md)
- [Compilación y pruebas](COMPILACION.md)
- [Pruebas para Kefir 927](PRUEBAS-KEFIR-927.md)
- [Política de releases](RELEASES.md)
- [Hoja de ruta y issues](HOJA-DE-RUTA.md)

Se conservan la licencia y créditos originales de Huntereb, HookedBehemoth y demás contribuidores. Esta edición es mantenida por [Alexis-VsCode](https://github.com/Alexis-VsCode).
