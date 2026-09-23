# Smart Parking System

An Arduino-based smart parking system designed to monitor the availability of three parking slots using ultrasonic sensors and display the parking status on a 16x2 LCD.

## Project Overview

The system detects whether each parking slot is occupied or available by measuring the distance using ultrasonic sensors.

The number of available parking slots is calculated continuously and displayed on the LCD.

## Features

- Monitors 3 parking slots
- Detects slot occupancy using ultrasonic sensors
- Displays the number of available slots
- Displays individual slot status
- Shows "Parking Full" when all slots are occupied
- Uses a 16x2 LCD for real-time display

## Components Used

- Arduino
- 16x2 LCD
- 3 Ultrasonic Sensors
- Connecting wires
- Breadboard
- Tinkercad for simulation

## Technologies

- Arduino
- Embedded C/C++
- Ultrasonic sensing
- LCD interfacing
- Tinkercad simulation

## Working Principle

1. The ultrasonic sensors measure the distance in each parking slot.
2. The measured distance is converted into centimeters.
3. If the measured distance is below the defined threshold, the slot is considered occupied.
4. The system calculates the total number of free slots.
5. The LCD displays the available slots and individual slot status.

## Output

Example LCD output:

Free Slots: 2

S1:X S2:O S3:O

Where:

- `X` = Occupied
- `O` = Available

## Project Status

Completed as an Arduino-based parking monitoring prototype.

## Note

The original Tinkercad simulation link is currently unavailable, so only the project source code and documentation are maintained in this repository.
