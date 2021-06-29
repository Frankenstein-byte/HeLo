# HeLo
Live Location and Health Monitoring 

**Remote Patient Monitoring (RPM)** works on the principles of having access to the patient’s dynamic information with regards to their health. This work presents a health monitoring system to keep periodical checks as well as an alert system to execute an impulsive response to critical conditions using an **8051 microcontroller, NodeMCU, and IoT implementation** and also Serial communication plays a key role for the transfer of data.
We also have a **IP based monitoring Web Portal** to constantly check the vitals of patient. 

## Circuit Diagram
We are using AT89S52 because its slightly different from the AT89C51 uC as it has ISP(In System Programming) feature.
It has SPI pins MOSI, MISO and SCK which will be used to upload the hex file to the uC.

![Screenshot](https://github.com/Frankenstein-byte/HeLo/blob/main/Pictures/ca0885a8-cbce-4917-8772-0ab84e44110f.jpg 250*250)



## Output
![Screenshot2](https://github.com/Frankenstein-byte/HeLo/blob/main/Pictures/1.jpg)
![Screenshot3](https://github.com/Frankenstein-byte/HeLo/blob/main/Pictures/4.jpg)
![Screenshot4](https://github.com/Frankenstein-byte/HeLo/blob/main/Pictures/3.jpg)

## 89S52 Programmer Using Arduino Uno
Refer the below mentioned link to upload code using arduino as ISP Programmer.This will be helpful for those who are willing to
start with the 89S52 uC and don't want to invest on an additional programmer for the 89S52 uC.

<https://www.instructables.com/89S52-Programmer-Using-Arduino-Uno/>
