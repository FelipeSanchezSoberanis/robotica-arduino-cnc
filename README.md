# Controlador de Máquina CNC 3D con Arduino

![Logo del proyecto](./images/logo.png)

Este proyecto es un controlador basado en Arduino para una máquina CNC 3D. Utiliza motores paso a paso para un movimiento y control precisos. La máquina CNC es capaz de realizar diversas tareas, como fresado, tallado y grabado en una amplia gama de materiales.

## Tabla de contenidos
- [Características](#características)
- [Requisitos](#requisitos)
- [Configuración del hardware](#configuración-del-hardware)
- [Configuración del software](#configuración-del-software)
- [Uso](#uso)
- [Contribuciones](#contribuciones)
- [Licencia](#licencia)

## Características
- Control de hasta cuatro motores paso a paso para un movimiento preciso en tres dimensiones.
- Soporte para diferentes cabezales de herramientas CNC, incluyendo fresas, cabezales de tallado y cabezales de grabado.
- Ajuste de la velocidad y aceleración para un control preciso.
- Compatibilidad con G-code para ejecutar instrucciones de mecanizado complejas.
- Funcionalidad de parada de emergencia para un apagado inmediato de la máquina.
- Opciones de calibración para un posicionamiento preciso y ajuste a cero.

## Requisitos
Para utilizar este controlador de máquina CNC, necesitarás los siguientes componentes de hardware:

- Placa Arduino (por ejemplo, Arduino Uno, Arduino Mega)
- Controladores de motor paso a paso (por ejemplo, A4988, DRV8825)
- Motores paso a paso
- Fuente de alimentación
- Estructura y marco de la máquina CNC
- Interruptores de fin de carrera (opcionales pero recomendados para el homing)
- Cabezales de herramientas CNC (por ejemplo, fresas, cabezales de grabado)
- Cable USB para conectar Arduino a tu computadora

## Configuración del hardware
1. Conecta la placa Arduino a tu computadora mediante el cable USB.
2. Conecta los controladores de motor paso a paso a la placa Arduino según la configuración de pines especificada.
3. Conecta los motores paso a paso a los controladores de motor correspondientes.
4. Conecta la fuente de alimentación a la placa Arduino y los controladores de motor paso a paso.
5. Si usas interruptores de fin de carrera, conéctalos a la placa Arduino según la configuración de pines especificada.
6. Monta el cabezal de herramienta CNC en la estructura de la máquina CNC.

## Configuración del software
1. Instala el Arduino IDE desde el sitio web oficial de Arduino (https://www.arduino.cc/en/software).
2. Clona o descarga este repositorio en tu máquina local.
3. Abre el Arduino IDE y ve a **Archivo -> Abrir**. Navega hasta el repositorio descargado y abre el archivo principal del sketch de Arduino (.ino).
4. Selecciona la placa Arduino y el puerto adecuados desde el menú **Herramientas** en el Arduino IDE.
5. Haz clic en el botón **Subir** para cargar el sketch en la placa Arduino.
6. El controlador de la máquina CNC está listo para usar.

## Uso
1. Conecta la placa Arduino a tu computadora mediante el cable USB.
2. Abre el Arduino IDE y ve a **Herramientas -> Monitor Serie**.
3. El Monitor Serie mostrará el estado y las instrucciones para el controlador de la máquina CNC.
4. Sigue las instrucciones en pantalla para inicializar y controlar la máquina CNC.
5. Utiliza instrucciones en formato G-code para realizar tareas de mecanizado complejas. Consulta la documentación proporcionada para conocer los comandos G-code compatibles.

## Contribuciones
Las contribuciones a este proyecto son bienvenidas. Para contribuir, sigue estos pasos:

1. Haz un "fork" del repositorio.
2. Crea una nueva rama para tu función o corrección de errores.
3. Realiza los cambios y realiza pruebas exhaustivas.
4. Haz "commit" de tus cambios y súbelos a tu "fork".
5. Envía una solicitud de extracción ("pull request") al repositorio principal.

Asegúrate de que tus contribuciones se alineen con el estilo de codificación y las convenciones del proyecto.

## Licencia
Este proyecto se distribuye bajo la [Licencia MIT](LICENSE). Siéntete libre de utilizar, modificar y distribuir el código según los términos de la licencia. Asegúrate de incluir el archivo de licencia original en cualquier distribución.
