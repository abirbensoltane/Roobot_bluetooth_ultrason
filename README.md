# Roobot_bluetooth_ultrason
 A robot that can be controlled with this Android application https://play.google.com/store/apps/details?id=com.giumig.apps.bluetoothserialmonitor via bluetooth and can stop automatically when there is an obstacle and a  buzzer is triggered with a LED lights up

materials: Arduino Uno , Pont H L298N ,Ultrason ,Bluetooth HC-05, led , buzzer

Wiring:


| Bluetooth  |    Arduino    |
| ---------- | ------------- |
| TX         |   10          |
| RX         |   11          |



| Pont H     |    Arduino    |
| ---------- | ------------- |
| ENA        |    9          |
| ENB        |    3          |
| IN4        |    4          |
| IN3        |    5          |  
| IN2        |    6          |  
| IN1        |    7          |
  
   
  
  
 | Ultrason      |            Arduino |
| ---------- | ------------- |
| Trigger    |                 12   |
| Echo                    |    13   |
