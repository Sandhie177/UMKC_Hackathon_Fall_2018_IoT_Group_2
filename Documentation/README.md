# UMKC_Hackathon_Fall_2018_IoT_Group_2

# Smart Home Application with Fire Fighting Robot  
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

## Platform Used:  
* Raspberry PI (for Node-red and App inventor)
* Arduino Uno (Fire Fighting Robot)

## Methodology:  
* To extract the sensor data (Humadity, Pressure and Temperature) from the sensor.
* Use node red to upload the data to firebase.
* View those data remotely via a mobile app.  
* Control the AC, Fan and Light through the app remotely via node-red.  
* If any of the weather condition goes above safety limit, send a mobile notification and also send an email.  
* If there is a fire at home, the fire robot will sense the fire and put-out the fire.  
* A buzzer will make sound if there is any fire.  
* And a text message and an email will be sent about the fire.  

## Feature:  
* Visualization and control of the temperature, pressure and humidity of the home from a remote place.
* Sending of an email if the temperature, pressure or humidity goes above a certain set value
* Sensing a fire if there is one and sending a text message via twilio to the home owner.
* Putting out the fire by splashing water to the fire affected areas in the given proximity.
* Making a high pitched sound in case of fire which can warn the nearby people.  
* Controlling the AC, fans, lights via one button build in MIT app inventor application.
* Economic and cost effective design for a safe environment at home.


## Limitations:
### **Fire Fighting Robot:**
* The sensing of the fire is a bit tedious due to the limited number of Infra-Red (IR) flame sensors. As we used only one sensor to detect the fire, we had to use a servo motor which can rotate the sensor 180 degree and detect the fire.  
* The range of the flame sensor is about 3 feet, so it cannot detect the fire which is far away.  
* As we weren't given any water pump, we had to use servo motor to pour water over fire.  
* Due to the lightness of the whole structure, water weight disrupts the motion of the robot. 

**Solution:**  
Using a good number of flame sensors and using more powerful motors and wheels can minimize the above mentioned limitations.  
### **Mobile Application:**  
* We were able to turn on and off few LEDs which represents the home appliances like Air Conditioner, Light and Fan. Testing was not done with original devices.  
* Also we only turned on and off the devices, but we did not control the levels on those devices, e.g. controlling the temperature on the AC.  

**Solution:**  
With proper controlling circuitry, it will be possible to control real devices. And also the parameters on those device can also be changed.


## Links:    
[Link for Video](https://www.youtube.com/watch?v=0Ki5mee7J8k&feature=youtu.be)    
[Link for Android App](https://github.com/Sandhie177/UMKC_Hackathon_Fall_2018_IoT_Group_2/blob/master/apk/IoTUMKCHackaroo.apk)    
[Link for Power point slide](https://github.com/Sandhie177/UMKC_Hackathon_Fall_2018_IoT_Group_2/blob/master/Documentation/IOT-SMART-HOME-Firebot-and-Device-Automation.pptx)  
[Link for Arduino Source code](https://github.com/Sandhie177/UMKC_Hackathon_Fall_2018_IoT_Group_2/blob/master/Documentation/Codes/Arduino/Arduino_code_fire_fighting_robot.ino)  
[Link for Node red Flow](https://github.com/Sandhie177/UMKC_Hackathon_Fall_2018_IoT_Group_2/blob/master/Documentation/Codes/Node%20red/Node_red_flow.txt)   
[Link for App inventor code](https://github.com/Sandhie177/UMKC_Hackathon_Fall_2018_IoT_Group_2/blob/master/Documentation/Codes/App_inventor_weather/IoTUMKCHackaroo.aia)  
[Links for mobile/Email/Text snippets](https://github.com/Sandhie177/UMKC_Hackathon_Fall_2018_IoT_Group_2/tree/master/Visualization/Mobile_email_text_notification_snippets) 

