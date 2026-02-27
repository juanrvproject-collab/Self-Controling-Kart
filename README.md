# Self-Controling-Kart
Building a low budget Radio-Control Kart!
First things first we will have to get our chasis. (Model chasis done in SolidWorks)


Then in stead of motors we will recycle 2 old Hoverboard Wheels of 10" each, that can be found online very cheap, with its own battery.


Then for the direct control two ESCs are going to be use (one for each wheel), the main goal is to achive the direct control with an accelerometer.
<img width="686" height="914" alt="image" src="https://github.com/user-attachments/assets/1dc932c9-7c30-4098-9de1-155c4bc94885" />


Now for the REMOTE we are going to use an ESP-32-Wroom, that is equiped with a bluetooth module and are found in Aliexpress for a ver low price, it will be used as a Digital-Analogic & Analogic-Digital Converter between the accelerometer and the ESC. When the control of the PS4 use as a remote is clicked the ESP32 will create a proportional sign Digital transformed into Analogic; while the pedal is pressed, the digital signal enters into the microconroller, tranform de analogical into digital and then outputs it transforming the digital into analogical to be recived by the ESC.



