
#include <CapacitiveSensor.h>
CapacitiveSensor Sensor1 = CapacitiveSensor(4, 5);//use four sensor to detect four fruits
CapacitiveSensor Sensor2 = CapacitiveSensor(6, 7);
CapacitiveSensor Sensor3 = CapacitiveSensor(8, 9);
CapacitiveSensor Sensor4 = CapacitiveSensor(10, 11);

long val1;//initialize 4 values from 4 sensors
long val2;
long val3;
long val4;
int pos;
#define led 13
void setup()
{
Serial.begin(9600);
pinMode(led, OUTPUT);
}
void
loop()
{
val1 = Sensor1.capacitiveSensor(30);
val2 = Sensor2.capacitiveSensor(30);
val3 = Sensor3.capacitiveSensor(30);
val4 = Sensor4.capacitiveSensor(30);

Serial.print(val1);//value1
Serial.print(" ");
Serial.print("\t");
Serial.print(val2);//value2
Serial.print(" ");
Serial.print("\t");
Serial.print(val3);//value3
Serial.print(" ");
Serial.print("\t");
Serial.print(val4);//value4
Serial.print(" ");
Serial.print("\t");

Serial.println();
delay(2);

//val1
if (val1 >= 100 && pos == 0)
{
digitalWrite(led, HIGH);
pos = 1;
delay(500);
}
else if (val1 >= 100 && pos == 1)
{
digitalWrite(led, LOW);
pos = 0;
delay(500);
}
//val2
if (val2 >= 100 && pos == 0)
{
digitalWrite(led, HIGH);
pos = 1;
delay(500);
}
else if (val2 >= 100 && pos == 1)
{
digitalWrite(led, LOW);
pos = 0;
delay(500);
}

//val3
if (val3 >= 100 && pos == 0)
{
digitalWrite(led, HIGH);
pos = 1;
delay(500);
}
else if (val3 >= 100 && pos == 1)
{
digitalWrite(led, LOW);
pos = 0;
delay(500);
}
//val4
if (val4 >= 100 && pos == 0)
{
digitalWrite(led, HIGH);
pos = 1;
delay(500);
}
else if (val4 >= 100 && pos == 1)
{
digitalWrite(led, LOW);
pos = 0;
delay(500);
}
delay(10);
}
