# Arquitectura y criterios de mantenimiento

## Inventario técnico

| Área | Tecnología o módulo | Consideraciones |
| --- | --- | --- |
| Núcleo de aplicación | C++17, libnx, devkitA64 | Requiere APIs compatibles con Horizon OS |
| Interfaz | Plutonium y SDL2 | Submódulo fijado a una revisión concreta |
| Almacenamiento | `source/install`, `source/nx` | Escrituras y metadatos: mayor sensibilidad |
| Transferencias | USB, HTTP, LAN, libcurl | Límites, autenticidad, cancelación, errores |
| Archivos comprimidos | minizip, zstd y NCZ | Rutas, tamaño, integridad, memoria |
| Configuración / idiomas | JSON en SD y `romfs/lang` | Migración segura y traducciones |
| Automatización | GitHub Actions | Compilación cruzada y pruebas nativas |

## Criterios de arquitectura

**Evolución incremental, no reescritura.** No se fuerza una arquitectura hexagonal completa sobre la base C++ heredada. Primero se aíslan funciones comprobables: validación de rutas, reglas de tamaño, comprobaciones de integridad y gestión de configuraciones. Se mejora la separación de responsabilidades cuando reduzca acoplamiento o facilite pruebas.

Se aplican prácticas de código mantenible:
- RAII para manejar memoria y recursos cuando sea posible.
- Validación explícita de datos externos antes de reservar memoria o escribir archivos.
- Errores visibles, propagación coherente y cancelación sin bucles de espera indefinidos.
- Funciones pequeñas con responsabilidades claras; eliminación de duplicación real.
- Sin cambios globales de estilo que oculten parches de seguridad.
- Pinning de dependencias, licencias preservadas y compilación reproducible.

## Riesgos conocidos

| Prioridad | Riesgo | Tratamiento previsto |
| --- | --- | --- |
| Crítica | Tramas USB y tamaños no confiables | Validar entradas, pruebas y simulación de errores |
| Alta | Datos NCA/NCZ malformados | Revisar cabeceras y límites antes de reservar/copiar |
| Alta | Certificados TLS y descargas | Validar cadena de confianza real en Switch |
| Alta | Escrituras parcialmente completadas | Uso de staging, control de espacio y rollback |
| Alta | APIs IPC/NCM del firmware 23.0.1 | Pruebas en emuMMC y revisión de código de resultados |
| Media | Hilos y condiciones de carrera | Sincronización, cancelación y limpieza |
| Media | Configuración persistida heredada | Migración y pruebas con archivos antiguos |

## Criterios de aceptación

1. Pruebas estáticas y de regresión en verde.
2. Compilación del NRO y publicación de artefacto en CI.
3. Revisión humana del diff y atribuciones.
4. Pruebas funcionales en emuMMC; sin modificación de sysMMC.
5. Evidencias de errores y recuperación, versión exacta, SHA-256 y notas de cambios.
6. Release candidata antes de declarar estabilidad.

[Volver al README](../README.md) · [Hoja de ruta](HOJA-DE-RUTA.md)
