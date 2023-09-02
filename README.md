# DE2 Basic Computer RS232 Interrupt Handling and LED Control Project

This software demonstrates the use of the DE2 Basic Computer's RS232 serial interface. It includes an interrupt handler for processing incoming data and controlling LED displays.

## NIOS Microcomputer Configuration

- NIOS-II (e)
- Onchip RAM – 21504 bytes
- PIO_0 = 16 RED LEDs (LEDR15 to LEDR0)
- PIO_1 = Counter-3 MSB (1 bit) input (3 Second counter)
- PIO_2 = 6 GREEN LEDs (LEDG0 to LEDG5)
- PIO_3 = 1 bit GPIO (LabsLand Switch SW2)
- PIO_4 = Seven Segment Display – HEX0, HEX1, HEX2, HEX3 (28 bits output)
- UART configured as IRQ1
- PIO_5 = Counter-1 MSB (1 bit) input (1 Second counter)
- PIO_6 = Counter-2 MSB (1 bit) input (2 Second counter)
- PIO_7 = Channel 1 of Oscilloscope
- PIO_8 = Channel 2 of Oscilloscope

## Project Information

### Level 1 

Detect counter 1 (1-second counter) MSB rising edge and display the count of the rising edges on GREEN LEDs (LEDG0 - LEDG5) in binary format. Indicate the counter 1 signal to Channel 1 of the oscilloscope.

### Level 2 

Whenever a counter 1 MSB rising edge occurs, transmit your student ID as a character to the UART transmitter. Display the received character in 8-bit binary format on 8-RED LEDs (LEDR8 - LEDR15).

### Level 

Program NIOS to detect multiples of 5 counts of Counter-1 (1-second counter) rising edges. Flash ON GREEN LEDs (LEDR0 and LEDR1) simultaneously for one second and OFF for the next one second. Deactivate the flashing when LabsLand Switch SW2 is ON.

### Level 4 

In addition to the previous tasks, whenever a falling edge of Counter 1's MSB is detected, display the count of the falling edge on the seven-segment display (HEX0). Use polling as Counter 1 is not connected to the interrupt controller.

### Level 5 

In addition to all previous levels, display the received character in UART (your student ID) in scroll mode. Implement left-to-right shifting of characters using Counter-3 rising edge for scrolling. HEX0 should continue to display as per the Level 4 task.

Refer to the provided materials for further details and requirements for each level.


*Author: Avvienash*
