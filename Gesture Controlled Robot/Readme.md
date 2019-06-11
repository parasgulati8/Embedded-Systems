# Gesture Controlled Robot

![image](https://user-images.githubusercontent.com/43897597/59242966-c0c8e200-8bdb-11e9-84e6-0969136021c7.png)

# Gestures 
![image](https://user-images.githubusercontent.com/43897597/59243002-ef46bd00-8bdb-11e9-850e-308dd8b5c6f4.png)

# Sensors and equipment used: 
<ul>
<li>2 Atmega 16 IC with board </li> 
<li>Accelerometer  </li> 
<li>RF module ( receiver and transmitter along with module )  </li> 
<li>LCD for displaying the motion </li> 
<li>2 DC motors  </li> 
<li>Wires (female to female) </li> 
<li>Chassis  ( for designing it like a robo car)</li> 
</ul>

# Description 
 
A Gesture Controlled robot is a kind of robot which can be controlled by your hand gestures not by old buttons. On tilting your hand leftward the robot will move in left direction, similarly on tilting rightward the robot will move in right direction. You can stop the robot by tilting your wrist upward. If you keep your wrist in upward direction then the robot will start moving in reverse direction. To accelerate the robot in forward direction you need to bend your wrist in downward direction.  
 
You just need to wear a small transmitting device in your hand which included an accelerometer. This will transmit an appropriate command to the robot so that it can do whatever you want.  
 
The transmitting device included a ADC for analog to digital conversion and an encoder IC(HT12E) which is use to encode the four bit data and then it will transmit by an RF Transmitter module. 
 
At the receiving end an RF Receiver module receive's the encoded data and decode it by and decoder IC(HT12D). This data is then  processed by a microcontroller  and finally our motor driver to control the motor's.  
This project is divided into two different part transmitter and receiver. 

# RF Communication Module
The RF module, as the name suggests, operates at Radio Frequency. The corresponding frequency range varies between 30 kHz & 300 GHz. In this RF system, the digital data is represented as variations in the amplitude of carrier wave. This kind of modulation is known as Amplitude Shift Keying (ASK).

![image](https://user-images.githubusercontent.com/43897597/59243164-94619580-8bdc-11e9-8940-272ba2ba1eb3.png)

![image](https://user-images.githubusercontent.com/43897597/59243176-9e839400-8bdc-11e9-8246-6424195d5acb.png)

Transmission through RF is better than IR (infrared) because of many reasons. Firstly, signals through RF can travel through larger distances making it suitable for long range applications. Also, while IR mostly operates in line-of-sight mode, RF signals can travel even when there is an obstruction between transmitter & receiver. Next, RF transmission is more strong and reliable than IR transmission. RF communication uses a specific frequency unlike IR signals which are affected by other IR emitting sources.
This RF module comprises of an RF Transmitter and an RF Receiver. The transmitter/receiver (Tx/Rx) pair operates at a frequency of 434 MHz. An RF transmitter receives serial data and transmits it wirelessly through RF through its antenna connected at pin4. The transmission occurs at the rate of 1Kbps - 10Kbps.The transmitted data is received by an RF receiver operating at the same frequency as that of the transmitter.
The RF module is often used alongwith a pair of encoder/decoder. The encoder is used for encoding parallel data for transmission feed while reception is decoded by a decoder.  HT12E- HT12D, HT640-HT648, etc. are some commonly used encoder/decoder pair ICs.
![image](https://user-images.githubusercontent.com/43897597/59243202-b4915480-8bdc-11e9-8282-b556db35e9d0.png)

# Transmitter block 
![image](https://user-images.githubusercontent.com/43897597/59242890-75aecf00-8bdb-11e9-8b7a-8b146cf0e120.png)

Accelerometer gives analog values corresponding to three axis - X, Y and Z axis. 
Using a comparator, analog values are converted into digital form and passed to Atmega 16 IC. The values from the accelerometer is also displayed on the LCD screen which is used for calibration purposes. 
The signals from IC are then sent to encoder IC where parallel to serial conversion takes place and the data is ready to be sent to transmitter.  
Transmitter receives the data from the encoder and transmits to the receiver at predefined frequency channel.  

# Receiver Block 
![image](https://user-images.githubusercontent.com/43897597/59242925-99721500-8bdb-11e9-8803-8dde3f2d99a3.png)

The receiver catches the signals transmitted by the transmitter of RF module and transfers it to serial to parallel decoder IC (HT12D).  
Now the data is received by the Atmega 16 IC and it drives the motor. Calibrated values are stored in Atmega 16 IC which are matched with the received data and that decides the direction of rotation of both the motors.  
For different set of values received by the receiver, motors rotates in differently in accordance with the predefined(calibrated) set of values.  

# Code of the program 

The following C code represents the accelerometer controlled robotic car using RF communication.

•	The accelerometer controlled robot car requires two development boards:

 One that acts as the transmitter and the other that acts as the receiver and is placed within the car. 

•	Hence given below are the two coding required for (a) the transmitter, and (b) the receiver. 
