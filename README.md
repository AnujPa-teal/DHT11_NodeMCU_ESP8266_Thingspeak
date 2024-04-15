# DHT11_NodeMCU_ESP8266_Thingspeak
Repository deals with using DHT11 sensor and NodeMCU ESP8266 to measure Temperature, Humdity Readings and pushing the obtained data on Thingspeak cloud server.

Libraries used :- 


1) WifiClient.h -  https://www.arduinolibraries.info/libraries/wi-fi

2) dht11 library - https://github.com/adafruit/DHT-sensor-library

3) ESP8266 library - https://github.com/Hieromon/ESP8266

4) Thingspeak library - https://github.com/mathworks/thingspeak-arduino
   


Connections :-
          
 1. "+"  or  Vcc   -->    3.3v
   
 2.   Output   -->    D2
    
 3. "-"  or GND   -->   GND

    

1) First download the zip files of all libraries provided above  :- 

    ![dnld_zip](https://github.com/AnujPa-teal/DHT11_NodeMCU_ESP8266_Thingspeak/assets/138184585/e1ea3384-7921-43e7-98f3-8bdc9d8ce552)
   


2) Then add the downloaded libraries in Arduino IDE as given below :-
   
   ![programino-ide-for-arduino-libraries-an001](https://github.com/AnujPa-teal/DHT11_NodeMCU_ESP8266_Thingspeak/assets/138184585/5dced0f8-38d9-40db-9b6c-a8dc70b96a22)



3) Compile the program and upload.
   
(Try to use the libraries provided in this repository only in order to avoid facing errors.)
