# Line-Follower-robot-with-obstacle-avoidance
An intelligent line follower robot with integrated obstacle detection and avoidance for smooth autonomous navigation

Project Overview :This project focuses on designing and implementing an autonomous line following robot that can navigate a predefined path while detecting and avoiding obstacles in real time. The robot uses IR sensors to follow a line and an ultrasonic sensor to identify obstacles ahead. An Arduino microcontroller processes sensor inputs and controls motor movements accordingly. The system combines line tracking and obstacle avoidance to achieve safe and efficient autonomous navigation.
Problem Statement : Traditional line-following robots fail when unexpected obstacles appear on their path. There is a need for a smart robotic system that can not only follow a predefined line but also detect and avoid obstacles autonomously without human intervention.
Hardware Components : Arduino Uno
L298N / L293D Motor Driver Module
DC Geared Motors (2)
IR Line Sensors (2)
Ultrasonic Sensor
Robot Chassis
Wheels and Caster Wheel
Battery and Battery Holder
Jumper Wires
Software and Technologies: Arduino IDE – for code development and uploading
Working Principle : IR sensors continuously detect the line path.
Ultrasonic sensor measures distance to obstacles.
Arduino processes sensor data and decides movement.
If no obstacle is detected, the robot follows the line.
When an obstacle is detected within a threshold distance:
The robot stops
Moves backward
Turns to avoid the obstacle
After avoidance, the robot resumes line following. 
How to Run the Project : 
Assemble the hardware as per the circuit diagram.
Connect the Arduino to the computer using a USB cable.
Open the Arduino IDE and load the .ino file.
Select the correct board and COM port.
Upload the code to the Arduino.
Power the robot and place it on a line track.
