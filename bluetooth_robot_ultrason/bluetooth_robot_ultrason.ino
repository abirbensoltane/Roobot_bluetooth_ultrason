#include <SoftwareSerial.h>
SoftwareSerial EEBlue(10, 11); // RX | TX
int ENA =9;
int ENB = 3;
int IN4 = 4;
int IN3 = 5;
int IN2 = 2;
int IN1 = 7;
int led =1;
int buzz=6;
int trigPin = 12;    // Trigger
int echoPin = 13;    // Echo
long duration, cm;
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  analogWrite(ENA,85);
  analogWrite(ENB,85);

  
   EEBlue.begin(9600);  
  Serial.println("The bluetooth gates are open.\n Connect to HC-05 from any other bluetooth device with 1234 as pairing key!.");
}
String p;
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH);
    cm = (duration/2) / 29.1;     
    Serial.println(cm);

    
  if(cm > 10){ 
  if (EEBlue.available()) { 
    p = EEBlue.read();
    Serial.print(p);
if (p=="50"){
Serial.print("hello");
Fwd(); 
  }  
  if (p=="51"){
Serial.print("hello");
Right(); 
  }  

if (p=="52"){
Serial.print("hello");
Back(); 
  }  
if (p=="49"){
Serial.print("hello");
Left(); 
  }  
  
  }
 
 }else if(cm<10){
    Stop();
    digitalWrite(led,HIGH);
    
    tone(buzz, 450);
    delay(100);
   noTone(buzz);
   digitalWrite(led, LOW);
  }

}
void Fwd(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void Back(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void Right(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void Left(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void Stop(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
