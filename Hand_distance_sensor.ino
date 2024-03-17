/*************************************************************************************************

    Author : Hak Se Engineer 
    Date : 17/03/2024
    Description: This program can be used to help blind person to detect object around them,
                 It takes input from ultrasonic sensor, and based on object range buzzer beeps with different delay.
                 Which helps blind person to undertand object distance.

************************************************************************************************/

int trigPin = 11;    // TRIG pin
int echoPin = 12;    // ECHO pin
int buzzer =  3;//the pin of the active buzzer
float duration_us, distance_cm;

void setup() {
  // configure the trigger pin to output mode
  pinMode(trigPin, OUTPUT);
  // configure the echo pin to input mode
  pinMode(echoPin, INPUT);
  pinMode(buzzer,OUTPUT);//initialize the buzzer pin as an output
}

void loop() {

  unsigned int region;
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(echoPin, HIGH);

  // calculate the distance
  distance_cm = 0.017 * duration_us;

  delay(50);

  if( distance_cm > 90)
  {
      digitalWrite(buzzer,LOW);
      delay(2);//wait for 2ms
  }
  else if (distance_cm >50)
  {
      digitalWrite(buzzer,HIGH);
      delay(70);//wait for 2ms
      digitalWrite(buzzer,LOW);
      delay(70);//wait for 2ms
  }
  else if (distance_cm > 25)
  {
      digitalWrite(buzzer,HIGH);
      delay(40);//wait for 2ms
      digitalWrite(buzzer,LOW);
      delay(40);//wait for 2ms
  }
  else 
  {
      digitalWrite(buzzer,HIGH);
      delay(2);//wait for 2ms
  }
}