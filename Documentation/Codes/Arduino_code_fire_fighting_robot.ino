/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/
#include<SoftwareSerial.h>
#include <AFMotor.h>
#include <Servo.h>
SoftwareSerial esp8266(9,10);

#define SSID "NUU A4L"     // "SSID-WiFiname" 
#define PASS "buet177buet136"       // "password"
#define IP "184.106.153.149"// thingspeak.com ip
String msg = "GET /update?key=S8NGVSFAE3O9FVAJ"; //change it with your api key like "GET /update?key=Your Api Key"

Servo myservo;  // create servo object to control a servo
Servo myservo2;
AF_DCMotor motor3(3, MOTOR12_1KHZ); 
AF_DCMotor motor4(4, MOTOR12_1KHZ); 

int sensorPin = A0; // select the input pin for the LDR
int sensorValue = 1024;
int minimum;
int angle = 0;
int flag = 0;
int pos = 0;    // variable to store the servo position
int pos1 = 0;
int error;

void setup() {
  Serial.begin(115200);
  esp8266.begin(115200);
  myservo.attach(17);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(16);
  motor3.setSpeed(158); 
  motor4.setSpeed(190);
  pinMode(19,INPUT);
  pinMode(18,OUTPUT);
  if(esp8266.find("OK")){
    connectWiFi();
  }
   
}

void forward() {                     // This function moves all the wheels forward 
  motor3.run(FORWARD); 
  motor4.run(FORWARD); 
}

void backward()                    // This function moves all the wheels backwards 
{     
motor3.run(BACKWARD); 
motor4.run(BACKWARD); 
}

void haltMotors()                   // This function stops all the motors (It is better to stop the motors before changing direction) 
{ 
motor3.run(RELEASE); 
motor4.run(RELEASE);
} 

void turnLeft()                    // This function turns the robot right
{
motor3.run(FORWARD); 
motor4.run(BACKWARD); 
} 

void turnRight()                    // This function turns the robot right
{
motor3.run(BACKWARD); 
motor4.run(FORWARD); 
}

void fire_detection() {
  haltMotors();
      for (pos = 0; pos <= 180; pos += 5) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
      //Serial.println(sensorValue);
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(100);                       // waits 15ms for the servo to reach the position
      minimum = analogRead(sensorPin);
      if (minimum < sensorValue) {
        sensorValue = minimum;
        angle = pos;
      }  
    }
    if (sensorValue < 800) {
        tone(18,1000,2000);
        start: //label 
        error=0;
        delay(1000);
        updatebeat(5);
        if (error==1){
          goto start; //go to label "start"
        }
        myservo.write(angle);
        Serial.println(angle);
        flag = 1;
          if (angle>90) {
            turnLeft();
            delay(7*(angle-90));
            haltMotors();
          }
          if (angle<90) {
            turnRight();
            delay(9*(90-angle));
            haltMotors();
          }
          myservo.write(90);
      }
}

void updatebeat(int x) {
  error=0;
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += IP;
  cmd += "\",80";
  Serial.println(cmd);
  esp8266.println(cmd);
  delay(2000);
  if(esp8266.find("Error")){
    return;
  }
  cmd = msg ;
  cmd += "&field3=";   
  cmd += x;
  cmd += "\r\n";
  Serial.print("AT+CIPSEND=");
  esp8266.print("AT+CIPSEND=");
  Serial.println(cmd.length());
  esp8266.println(cmd.length());
  if(esp8266.find(">")){
    Serial.print(cmd);
    esp8266.print(cmd);
  }
  else{
   Serial.println("AT+CIPCLOSE");
   esp8266.println("AT+CIPCLOSE");
    //Resend...
    error=1;
  }
}

boolean connectWiFi(){
  Serial.println("AT+CWMODE=1");
  esp8266.println("AT+CWMODE=1");
  delay(2000);
  String cmd="AT+CWJAP=\"";
  cmd+=SSID;
  cmd+="\",\"";
  cmd+=PASS;
  cmd+="\"";
  Serial.println(cmd);
  esp8266.println(cmd);
  delay(5000);
  if(esp8266.find("OK")){
    Serial.println("OK");
    return true;    
  }else{
    return false;
  }
}

void loop() {
  myservo2.write(35);
  //Serial.println(sensorValue);
  if (flag == 0) {
    fire_detection();
  }
  delay(1000);
  if (flag == 1) {
    if (digitalRead(19) == 1) {
      forward();
      delay(2000);
      haltMotors();
      delay(900);
      fire_detection();
      tone(18,1000,50);
    }
    else {
      haltMotors();
      delay(1000);
        for (pos1 = 35; pos1 <= 120; pos1 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo2.write(pos1);              // tell servo to go to position in variable 'pos'
    tone(18,1000,50);                     // waits 15ms for the servo to reach the position
  }
  delay(1500);
  for (pos1 = 120; pos1 >=35; pos1 -= 1) { // goes from 180 degrees to 0 degrees
    myservo2.write(pos1);              // tell servo to go to position in variable 'pos'
    
  }
  delay(1500);    
      flag = 2;
        zeros: //label 
        error=0;
        delay(6000);
        updatebeat(0);
        if (error==1){
          goto zeros; //go to label "start"
        }
    }
  }
  delay(1000);
}

