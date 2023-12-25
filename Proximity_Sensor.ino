#include <hcsr04.h>                                       //Library for ultrasonic sensor
#include <LiquidCrystal.h>                                //Library for LCD screen

//Pins for the ultrasonic sensor
#define trigpin 2                                         
#define echopin 3

//Pins for the RGB LED
#define blue 6
#define green 5
#define red 4

//Variable for the buzzer
int buzzer = 1;

//initializing the utrasonic sensor and LCD
HCSR04 hcsr04(trigpin, echopin, 20, 4000);
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

//variables for the time and distance
long duration;
int distanceCm, distanceInch;

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
}

void loop() 
{
  //green light is always on
  digitalWrite(green, HIGH);

  //buzzer is always at low frequency
  digitalWrite(buzzer, LOW);

  digitalWrite(trigpin, LOW);
  delay(2);
  digitalWrite(trigpin, HIGH);
  delay(10);
  digitalWrite(trigpin, LOW);

  duration = pulseIn(echopin, HIGH);
  distanceCm = duration * 0.034 / 2;
  distanceInch = duration * 0.0133 / 2;

  //printing the distance in cm
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  lcd.print(distanceCm);
  lcd.print("cm");

  //printing the distance in in
  lcd.setCursor(0, 2);
  lcd.print("Distance:");
  lcd.print(distanceInch);
  lcd.print("inch");


  if (distanceCm <= 5)
  {
  //turns the rgb LED red when distance is less than 5cm
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  
  //displays warning message when distance is less than 5cm
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  lcd.print(distanceCm);
  lcd.print("cm");
  lcd.setCursor(3,2);
  lcd.print("WATCH OUT");
  }
  
  delay(100);
}
