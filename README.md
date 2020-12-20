# YAWS: Yet Another Watering System
I started growing carnivore plants indoor and the require daily watering .. so here we go!
## electronics
* Arduino
* Power supply: 12V DC
* relay 1-module
* ultrasonic distance sensor
* peristaltic pump

![](wiring.png "wiring diagram")

Use a 12V DC peristaltic pump from aliexpress like this one. Ensure the power needed by the pump is the same you're using in the arduino (you'll power the pump using Vin/GND).
(peristaltic_pump.png)

## casing
We're going to use a standard 75mm PVC water pipe, with a plug where the ultrasonic sensor will be installed pointing downwards.
The upper chamber is 3d printed and it will fit all the electronic components while keeping them safe from the water.

("full casing" projection.png)

("3d printed" 3d view.png)

## software
Just an infinite loop which will turn on the pump for 2 minutes only if the water level is low enought. Then it will wait for 1 day and re-check.