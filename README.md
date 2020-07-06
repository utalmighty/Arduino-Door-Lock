# Arduino-Door-Lock
Arduino Door Lock using Servo Motor.
Hello viewers, here are the instructions to use Arduino Door LOCK.

<b>Circuit Setup:</b>

 1: <i>4X4 Matrix Keypad:</i> Extreme Left pin of Keypad goes into PIN 13 and followed by PIN 12 and so on until the extreme right pin from Kepad goes to PIN (~)6.
 
 2: <i>Servo Motor:</i> The Yellow wire(signal/PWM) of Servo goes into PIN (~)3, Red wire(+5V) of servo goes into PIN 5V, Brown wire(GND) goes into PIN Gnd.
 
 3: <i>Animation/Feedback Light(All Same Color recommended):</i> All the LEDs are conneced individually with 200 Ohm resistors(at their negative ends) and grounded at GND PIN of             arduino(to save pins at arduino, ground all the LEDs with resistor into single GRD pin). Positive(+ve) end of LEDs goes into A0, A1, A2, A3(keep the physical order same) eg.       A0 LEd goes to extreme left, A1 LED goes to preceding left and so on.
 
 4: <i>Lock/Unlock LEDs(RED for Locked/GREEN for Unlocked):</i> Connect Both LEDs to the same 200 ohm resistor because only single would be operable at a time and ground it in GND PIN.       Positive(+ve) pin of Red LED goes into PIN 4, Green LED goes PIN 5.
 
 <b>Working:</b> 
 
 <i>Step 1:</i> Type in The MAIN PASSWORD default is 3364 through 4X4 Keypad(You can change it in the code max 4 Digits) you will notice Animation/Feedback Light glows as you type in.
 
 <i>Step 2:</i> Once Verified, now type in the new session password (4 Digits)(resets once unlocked) all the LEDS will lit up as you type in,and to confirm the PIN again type the same pin and you will see the LEDs turing off, if the password is confirmed press any key to LOCK(it can only be unlocked with current session pin).

 <i>Step 3:</i> To unlock type in the current session pin. (if the wrong pin is entered three times a row, (tip: you can also add siren)the input system goes into sleep and wakes up    after 10 seconds with a light affects.
