# Historial de cambios

Este documento registra cambios de **Awoo Installer Community**. El proyecto original conserva su propio historial: [Huntereb/Awoo-Installer](https://github.com/Huntereb/Awoo-Installer).

Las entradas bajo **Sin publicar** corresponden a trabajos en revisión y **no** indican que exista una versión estable ni que las pruebas de consola hayan concluido.

## Sin publicar — cambios integrados en `master` (12 de noviembre de 2026)

### Seguridad
- Restablecimiento de controles TLS en componentes de red revisados.
- Comprobaciones del tamaño comunicado por USB antes de escribir en memoria.
- Validación de rutas ZIP, prevención de traversal y límites de extracción.
- Suspensión temporal del actualizador ZIP y de la obtención externa de parches.

### Estabilidad y calidad
- Corrección de la comprobación de creación de sockets.
- Valores de configuración iniciales conservadores y migración tolerante de opciones heredadas.
- Pruebas de seguridad y extracción ZIP en host.
- Compilación automatizada de Awoo y Plutonium con devkitPro.
- Prueba automática del empaquetador compartido y manifest SHA-256 en CI.

### Idioma y documentación
- Traducción de los mensajes comunitarios a español e inglés.
- Respaldo de mensajes cuando falta una clave traducida.
- Portal GitHub Pages, guía de contribución, compatibilidad y procedimientos de validación.

### Pendiente antes de una release
- Validación completa en hardware: Horizon OS 23.0.1, AMS 1.12.1, Kefir 927, emuMMC.
- Inspección de rutas sensibles de NCA/NCZ, memoria y transferencias concurrentes.
- PR #1 fusionado; pendiente validación de hardware, revisión de memoria y comprobación de extremo a extremo del workflow de releases.

Consulta la [discusión técnica del PR #1](https://github.com/Alexis-VsCode/Awoo-Installer/pull/1).

## Versiones publicadas

**Aún no hay una release comunitaria publicada.** No se reutilizan las versiones originales como si fueran versiones nuevas del fork.

## Pre-release comunitaria v1.3.6-community.1-beta.1 — 12 de noviembre de 2026

Primera beta **pública y experimental** de este fork, compilada desde `master` con pruebas automatizadas. Incluye NRO, ZIP y sumas SHA-256. No cuenta con certificación en hardware real; se distribuye para obtener comentarios y reportes de los usuarios.

- [Archivos y advertencias de la beta](https://github.com/Alexis-VsCode/Awoo-Installer/releases/tag/v1.3.6-community.1-beta.1)
- [Hilo comunitario de resultados](https://github.com/Alexis-VsCode/Awoo-Installer/issues/8)
- [Ejecución de publicación automatizada](https://github.com/Alexis-VsCode/Awoo-Installer/actions/runs/43307730382)

No se declara como estable ni se cierra la validación de compatibilidad pendiente.
