# Política de seguridad

## Ámbito y soporte

Awoo Installer Community es un fork en proceso de modernización. La rama de desarrollo contiene controles nuevos, pero **no hay todavía una versión estable validada en Horizon OS 23.0.1**.

| Rama o versión | Soporte |
| --- | --- |
| `feat/kefir-927-modernization` | Desarrollo y revisión; no se recomienda como versión estable |
| `master` | Base del fork y documentación pública |
| Releases comunitarias | No publicadas todavía |

## Cómo notificar un fallo

Para fallos funcionales sin impacto de seguridad utiliza [Issues](https://github.com/Alexis-VsCode/Awoo-Installer/issues), incluyendo versión, pasos y resultado esperado.

Para vulnerabilidades, prioriza la opción **Report a vulnerability** dentro de la pestaña *Security* del repositorio si está habilitada. Si no aparece, solicita un canal privado al mantenedor **sin adjuntar públicamente un exploit, claves ni información sensible**.

## Política de correcciones

Los avisos se analizan considerando impacto, posibilidad de reproducción, versiones afectadas y riesgo de regresión. Los parches deben acompañarse de pruebas y notas de impacto. No se dan garantías de plazo ni se anuncia una corrección como validada hasta verificarla.

## Medidas conocidas en desarrollo

- Verificación de certificados TLS en funciones revisadas.
- Validación de longitud y límites de transferencias USB.
- Protección de rutas ZIP y límites de extracción.
- Suspensión provisional de actualización automática y descarga externa de parches.
- Revisión pendiente de memoria, concurrencia y compatibilidad de los servicios de almacenamiento.

**Precaución:** no compartas copias de NAND, claves, tickets, datos de usuario ni archivos de terceros protegidos por derechos de autor.
