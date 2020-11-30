/*
Author: Tejas Wilkhoo
Date: 5/29/19
Description: Making a green LED stay on for five seconds,
yellow for two seconds, and red for the rest of the time until that side becomes
green once again, all while sensing cars (The light won't become red if there aren't
any cars on the other side), and the front side is towards the tree
*/

int greenLR = 2; //Set the Green Left and Right LEDs to digital port 2
int yellowLR = 3; //Set the Yellow Left and Right LEDs to digital port 3
int redLR = 4; //Set the Green Left and Right LEDs to digital port 4
int greenFB = 5; //Set the Green Front and Back LEDs to digital port 5
int yellowFB = 6; //Set the Yellow Front and Back LEDs to digital port 6
int redFB = 7; //Set the Red Front and Back LEDs to digital port 7
int sensorF = A0; //Set the Front Car sensor to analog port A0
int sensorR = A1; //Set the Right Car sensor to analog port A1
int sensorL = A2; //Set the Left Car sensor to analog port A2
int sensorB = A3; //Set the Back Car sensor to analog port A3

void setup()
{
Serial.begin(9600); //Open the serial monitor (if we need to track any values)
pinMode(redFB, OUTPUT); //Set the Red Front and Back LED as an output
pinMode(yellowFB, OUTPUT); //Set the Yellow Front and Back LED as an output
pinMode(greenFB, OUTPUT); //Set the Green Front and Back LED as an output
pinMode(redLR, OUTPUT); //Set the Red Left and Right LED as an output
pinMode(yellowLR, OUTPUT); //Set the Yellow Left and Right LED as an output
pinMode(greenLR, OUTPUT); //Set the Green Left and Right LED as an output
}
void loop()
{
digitalWrite(redFB, HIGH); //Make the Red Front and Back LEDS on
digitalWrite(greenLR, HIGH); //Make the Green Left and Right LEDS on
delay(5000); //Stay like this for five seconds before proceding
while((analogRead(sensorF)>=300) && (analogRead(sensorB)>=300)) //If the sensors don't sense cars on the other side, stay green
{
delay(1); //Stay green
} //Continue with the code only when there is a car on the other side
digitalWrite(greenLR, LOW); //Make the Green Left and Right LEDS off
digitalWrite(yellowLR, HIGH); //Make the Yellow Left and Right LEDS on
delay(2000); //Stay like this for two seconds before proceding
digitalWrite(yellowLR, LOW); //Make the Yellow Left and Right LEDS off
digitalWrite(redLR, HIGH); //Make the Red Left and Right LEDS on
delay(2000); //Stay like this for two seconds before proceding
digitalWrite(redFB, LOW); //Make the Red Front and Back LEDS off
digitalWrite(greenFB, HIGH); //Make the Green Front and Back LEDS on
delay(5000); //Stay like this for five seconds before proceding

while((analogRead(sensorL)>=300) && (analogRead(sensorR)>=300)) //If the sensors don't sense cars on the other side, stay green
{
delay(1); //Stay green
} //Continue with the code only when there is a car on the other side
digitalWrite(greenFB, LOW); //Make the Green Front and Back LEDS off
digitalWrite(yellowFB, HIGH); //Make the Yellow Front and Back LEDS on
delay(2000); //Stay like this for two seconds before proceding
digitalWrite(yellowFB, LOW); //Make the Yellow Front and Back LEDS off
digitalWrite(redFB, HIGH); //Make the Red Front and Back LEDS on
delay(2000); //Stay like this for two seconds before proceding
digitalWrite(redLR, LOW); //Make the Red Left and Right LEDS off (if they are on at the end of the loop)
} //Repeat Forever
