# Trashbin opener

A Sketch to open a trashbin whenever you put your hand in front of a distance sensor

## Used Parts

* [Servo] (<https://www.addicore.com/FS90R-Servo-p/ad314.htm>)
* [Sensor] (<https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf>)
* [NodeMcu] (<https://github.com/nodemcu/nodemcu-devkit-v1.0>)
* [Iris-Thingiverse] (<https://www.thingiverse.com/thing:3563742/files>)

To get the servo to work make sure the potentiometer is adjusted properly as shown below

![Servo position](Documents/right_position.jpg)

The servo interprets the time you set the control pin high to find out in which direction to turn. A pulse of 1500 Microsecunds should make not turn at all, 700ms should let him turn full speed clockwise and 2300 full speed conterclockwise.
You can test if your potentiometer is adjusted properly, you just have to use writeMicroseconds(1500). If he does not do anything at all you're good to go otherwise you have to adjust the screw at the bottom.

Do what you wish with this - if you find bugs or dont like my code feel free to edit or send me a pm