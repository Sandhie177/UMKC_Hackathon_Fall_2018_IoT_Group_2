# UMKC_Hackathon_Fall_2018_IoT_Group_2

## Materials Required:  
* Robot Chasis  
* DC motor (2)  
* Servo Motot (2)  
* Flame Sensor  
* Arduino Motor Shield  
* ESP 8266 WIFI module  
* Wheels  
* Sensor Tag
* Water container 
* LEDs
* Breadboard   
* Connectors  
* Resistors  
* Arduino Board   
* Raspberry Pi  

## Project Flow:  
* To extract the sensor data (Humadity, Pressure and Temperature) from the sensor.
* Use node red to upload the data to firebase.
* View those data remotely via a mobile app.  
* Control the AC, Fan and Light through the app remotely.  
* If any of the weather condition goes above safety limit, send a mobile notification and also send an email.  
* If there is a fire at home, the fire robot will sense the fire and put-out the fire.  
* A buzzer will make sound if there is any fire.  
* And a mobile notification and an email will be sent about the fire.  

## Limitations:
### **Fire Fighting Robot:**
* The sensing of the fire is a bit tedious due to the limited number of Infra-Red (IR) flame sensors. As we used only one sensor to detect the fire, we had to use a servo motor which can rotate the sensor 180 degree and detect the fire.  
* The range of the flame sensor is about 3 feet, so it cannot detect the fire which is far away.  
* Due to the lightness of the whole structure, water weight disrupts the motion of the robot.   
**Solution:**  
Using a good number of flame sensors and using more powerful motors and wheels can minimize the above mentioned limitations.  
### **Mobile Application:**  
* We were able to turn on and off few LEDs which represents the home appliances like Air Conditioner, Light and Fan. Testing was not done with original devices.  
* Also we only turned on and off the devices, but we did not control the levels on those devices, e.g. controlling the temperature on the AC.  
**Solution:**  
* With proper controlling circuitry, it will be possible to control real devices. And also the parameters on those device can also be changed.


## Links:    
[Link for Video]()  
[Link for Arduino source code]()  
[Link for powerpoint slide](https://github.com/Sandhie177/UMKC_Hackathon_Fall_2018_IoT_Group_2/blob/master/Documentation/IOT-SMART-HOME-Firebot-and-light-automation.pptx/)  
[Link for android app]()  
