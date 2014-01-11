gps-logger
==========

Notes
==========
These are main functions that is needed for the gps logger.

i. Initialise USART: This function initialise the USART Port for recieving and transmitting data.

ii. Initialise GPS Module: This function initialise the baudrate, update frequency, stop bit, message type for the gps module, recieving and processing data from the gps module.

iii. Calculate distance: This function calculates the distance from current position coordinate to the provided coordinated.

iv. Display data LCD: This function displays the desired data on the LCD screen.

v. Initialise SD Card: This function initialise the SD Card and the file system associated.

Sources
=========
Original source code: https://github.com/marmat/gps-logger

Interrupt vector list: http://www.nongnu.org/avr-libc/user-manual/group__avr__interrupts.html

Fuse Bit Initialisation
===================
Set Fuse low byte with the value of 0xCD

Bit that will need to be initialise during the compilation of the firmware.

CKOPT	1
CKSEL3	1
CKSEL2	1
CKSEL1	0
CKSEL0	1
SUT1	0
SUT0	0

