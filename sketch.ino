//testet with NodeMCU, HC-SR04 distance sensor, FS90R continuous servo

#include <Servo.h>

int state = 0;
const int trigPin = D0; // <-|trigger and echo pin
const int echoPin = D1; // <-|HC distance sensor
const int servoPin = D2;// <-|drive pin of servo


int pulselength_oneRotation_left = 1280;// <-|these two values are depending on your servo. For me 1000 Microseconds is not turning ar all
int pulselength_oneRotation_right = 760;// <-|less than 1000 turns the servo right and more is turning left. The further the value away from 1000 the faster it turns.
long duration=0;
long distance;
int i;
Servo myservo;
void setup() {
    
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    myservo.attach(servoPin);
    state=1;
    Serial.begin(115200); //start serial with baud rate 115200
}   

void loop() 

{     
    for (i=1; i<11 ;i++) //10x measuring distance
    {
        digitalWrite(servoPin, LOW);
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);
        duration += pulseIn(echoPin, HIGH);
        delay(15);
        
    }
    distance= (duration/10)*0.027; //not the correct formula but 0.027 gave better results
    duration=0;
    Serial.print(distance); //print distance to Serial Port
    if (distance >= 20 && state!=1) // if distance >= 20cm turn servo one rotation left
        {
            myservo.writeMicroseconds(pulselength_oneRotation_left);// this value is depending on your servo
            delay(1000);
            state=1;
        }
    else if (distance <= 21 && state!=2)
        {
            myservo.writeMicroseconds(pulselength_oneRotation_right);
            delay(1000);
            state=2;
        }

    else
        {    
        delay(100);
        Serial.println("no change");
        }

}