# smart-car-parking
In this project, I developed an Automatic Car Parking System using Arduino UNO, an LCD, and an IR Sensor. The system displays the parking slot status (available or occupied) on an LCD screen based on signals from the IR sensor.

Features:
	•	IR Sensor: Detects the presence of a car in the parking slot.
	•	LCD Display: Shows real-time parking slot status (Available or Occupied).
	•	Servo Motor (optional): Automatically operates the parking barrier.

Components Used:
	1.	Arduino UNO: Controls the system and processes the signals from the sensor.
	2.	IR Sensor: Detects the presence of a car.
	3.	16x2 LCD: Displays the parking slot status.
	4.	Servo Motor (optional): Opens and closes the parking barrier automatically.

How It Works:
	1.	When a car approaches the parking slot, the IR Sensor detects its presence.
	2.	The Arduino UNO processes the signal and updates the LCD Display with the current parking slot status.
	3.	If a servo motor is used, the system can automatically control the parking barrier (opens when the slot is available and closes when occupied).
