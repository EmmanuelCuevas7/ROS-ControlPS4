# ROS-ControlPS4
ROS package para integrar el control de PS4 y manejar robots en simulación o en prototipo físico

En este paquete se encuentra configurado para mandar datos a dos tópicos del proyecto AutoMiny v4.0, los cuales son la dirección del vehículo y la velocidad lineal del mismo.

> $ /control/command/normalized_wanted_steering

> $ /control/command/normalized_wanted_speed

En el archivo control.cpp basta con cambiar el topico al que vamos a publicar los datos.
