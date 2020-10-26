# Trabajo Práctico 1 - Taller de Programación - Crypto Sockets

Alumno: Robinson Fang

Padrón: 97009

Repositorio: https://github.com/fangrobinson/taller-de-programacion-1-veiga-tp1-crypto-sockets


La tarea consistía en desarrollar dos programas: uno emisor (o cliente), y otro receptor (o servidor) de un mensaje cifrado.

El programa emisor lee mensajes por entrada estándar y los envía cifrados, mientras que el receptor debe descifrarlos y mostrarlos por salida estándar.

![Diagrama de clases](img/class_diagram_release_05.png)

El diagrama muestra la relación que existe entre las estructuras y sus funciones en la solución propuesta.

## Completitud del trabajo:

Se desarrollaron los 3 cifradores cada uno en una tda correctamente encapsulada. El uso de estos debe ser mediante acceso a un Controlador de Cifradores que se encarga de inicializar y utilizar el cifrador que corresponde para cada ejecución de cliente y servidor.

Así mismo también se implementó un tda tanto para el cliente como para el servidor. Ninguno de estos se encarga del parseo de la entrada estándar utilizada para instanciarlos e invocarlos. 

También se desarrolló un socket tda, incapaz de mandar o recibir mensajes. Por lo que la incapacidad de cumplir las funciones mínimas pedidas se radica en esto.