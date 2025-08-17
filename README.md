# Pygmalion_line_follower
An Arduino code developped for a regional robotic competition in Medellin Colombia (2016).
# Line Follower Robot (2016 Project) Test video https://youtu.be/T5wZ0_q7W9Y

## ​ Project Overview

This project implements a **Line Follower Robot** — an autonomous robot designed to **follow a predefined path**, typically a high-contrast line (e.g., black on white), using onboard sensors and logic.

---

##  What Is a Line Follower?

A **line follower robot** is an autonomous mobile device that tracks and follows a line drawn on the ground. It relies on sensors to detect the line and uses a microcontroller to control the motors, correcting its course in real time based on sensor feedback. It is a classic robotics platform, widely used for learning automation and embedded systems.  
:contentReference[oaicite:0]{index=0}

---

##  Sensors Used

### Infrared (IR) Sensors / Line Detection

- **Infrared (IR) sensors** are the core components that detect the line's contrast. Each sensor typically includes:
  - An **IR LED**, which emits infrared light.
  - A **photodiode or phototransistor**, which reads reflected IR light from the surface.
- **How it works**:
  - On a **white surface**, IR light reflects strongly and is detected by the photodiode → interpreted as “line not present.”
  - On a **black line**, IR light is absorbed, resulting in low/no reflection → interpreted as “line detected.”  
:contentReference[oaicite:1]{index=1}
### Ultrasonic Sensors

- **Ultrasonic sensors** 
  - **How it works**, uses ultrasonic frequences that humains can't hear (above 20kHz). This sensor is capable of detecting objetcs by sending the ultrasonic son in front of it and measuring the stregth of the signal received. 

### Feedback Mechanism

Two IR sensors are typically positioned side by side at the front of the robot. Based on their input:
- **Both sensors on line** → Go straight
- **Left sensor off line, right sensor on line** → Steer left
- **Right sensor off line, left sensor on line** → Steer right  
:contentReference[oaicite:2]{index=2}

---

