# ROS-ControlPS4
Sony PlayStation 4 DualShock®4 node joy_msg to twist_msg

ROS package para integrar el control de PS4 y manejar robots en simulación o en prototipo físico

# Installation

1. Install **ds4drv**: `$ sudo pip install ds4drv `.
2. Instalar **ros-joy**: `$ sudo apt-get install ros-noetic-joy`, More info: http://wiki.ros.org/joy .
3. Activar bluettoth del ordenador y emparentar el mando PS4: Apretar boton PS4 + boton share.
4. Ejecutar `$ sudo ds4drv` desde una terminal.
5. Esto genera una conexion del mando al ordenador y por lo general el dispositivo se lista como */dev/input/jsX*
6. `$ sudo chmod a+rw /dev/input/jsX`


# More about

En este paquete se encuentra configurado para mandar datos a dos tópicos del proyecto AutoMiny v4.0, los cuales son la dirección del vehículo y la velocidad lineal del mismo.

> $ /control/command/normalized_wanted_steering

> $ /control/command/normalized_wanted_speed

En el archivo control.cpp basta con cambiar el topico al que vamos a publicar los datos.
