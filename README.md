# Self-Controling-Kart
Building a low budget Radio-Control Kart!
First things first we will have to get our chasis. (Model chasis done in SolidWorks)
<img width="279" height="180" alt="image" src="https://github.com/user-attachments/assets/044bc36e-5dba-472b-965f-074c47af3ebe" />

<img width="380" height="230" alt="image" src="https://github.com/user-attachments/assets/4a7fd51b-0e3c-4b28-95ae-3c9c3f585936" />


Then in stead of motors we will recycle 2 old Hoverboard Wheels of 10" each, that can be found online very cheap, with its own battery.


Then for the direct control two ESCs are going to be use (one for each wheel), the main goal is to achive the direct control with an accelerometer.
<img width="488" height="496" alt="image" src="https://github.com/user-attachments/assets/444b8d98-7591-45c4-8c05-84225eab05ed" />


Now for the REMOTE we are going to use an ESP-32-Wroom, that is equiped with a bluetooth module and are found in Aliexpress for a ver low price, it will be used as a Digital-Analogic & Analogic-Digital Converter between the accelerometer and the ESC. When the control of the PS4 use as a remote is clicked the ESP32 will create a proportional sign Digital transformed into Analogic; while the pedal is pressed, the digital signal enters into the microconroller, tranform de analogical into digital and then outputs it transforming the digital into analogical to be recived by the ESC.


https://github.com/user-attachments/assets/32c44cc3-60c4-41d8-bb7d-4f29f2161fdf

WHAT NOW??
The next step is to replace the ESP32-WROOM with an ESP32-CAM that can be programmed to recognize faces (vaguely).
<img width="250" height="192" alt="image" src="https://github.com/user-attachments/assets/11e1fe04-3bcc-4703-ac86-bfe853a42664" />


