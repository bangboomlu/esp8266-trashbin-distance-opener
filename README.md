# Trashbin opener

A Sketch to open a trashbin whenever you put your hand in front of a distance sensor

## Used Parts

* [Servo] (<https://www.addicore.com/FS90R-Servo-p/ad314.htm>)
* [Sensor] (<https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf>)
![Sensor] (<https://core-electronics.com.au/media/catalog/product/d/e/device6_1000.jpg>)
* [NodeMcu] (<https://github.com/nodemcu/nodemcu-devkit-v1.0>)
* [Iris-Thingiverse] (<https://www.thingiverse.com/thing:3563742/files>)
![Iris] (<https://cdn.thingiverse.com/renders/17/5a/8b/a4/fa/f6a91f06dcc71411450aeee302e43947_preview_featured.jpg>)

To get the servo to work make sure the potentiometer is adjusted properly as shown below

![Servo position](Documents/right_position.jpg)

The servo interprets the time you set the control pin high to find out in which direction to turn. A pulse of 1500 Microsecunds should make not turn at all, 700ms should let him turn full speed clockwise and 2300 full speed conterclockwise.
You can test if your potentiometer is adjusted properly, you just have to use writeMicroseconds(1500). If he does not do anything at all you're good to go otherwise you have to adjust the screw at the bottom.
