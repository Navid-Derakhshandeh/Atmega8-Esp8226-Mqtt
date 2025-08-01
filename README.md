# Atmega8 Esp8266 Mqtt
In this repository, I have uploaded code for communication between an Atmega8a microcontroller and an ESP8266 development module. The ESP8266 connects to an MQTT broker and listens to a topic for example receives a sensor values. When the sensor value exceeds 50, the ESP8266 sets GPIO5 (pin D1) to HIGH. When the Atmega port D2 (DDRD.2) is set to HIGH, the connected LED  to port D3 starts blinking every 5 seconds. If the sensor value drops below 50, the ESP8266 sets GPIO5 to LOW, and the LED connected to the Atmega8a's DDRD.3 port (PORTD.3) stops blinking.

<img width="357" height="253" alt="Screenshot (579)" src="https://github.com/user-attachments/assets/016ef361-c4e9-4018-a4ee-abcc380e90ef" />

![1-1](https://github.com/user-attachments/assets/58a44bc6-823f-42d6-a2eb-9dfdb8642a12)

<img width="359" height="250" alt="Screenshot (580)" src="https://github.com/user-attachments/assets/823c957c-5cc7-403c-bc98-26728c8040ef" />

![2-2](https://github.com/user-attachments/assets/7941e6a6-876d-4f51-a489-26cc20172b0b)

