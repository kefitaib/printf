				# PRINTF
### Objective:
Recreate the C library printf
## Requirements:
Files should be compiled with gcc 4.8.4
No more than 5 functions per file
Files should end with a new line
No global variables allowed
## _printf
this function prints the buffer to the standard output and and returns the number of characters it printed everything is called from here also it calls other functions
## percentPrint
This function is called if % is found adds it % to the buffer
## charPrint
This function is called if %c is found it affects the character passed as an argument to the buffer
## stringPrint
This function is called if %s is found it affects a string passed as an argument to the buffer
## integerPrint
This function is called if %i is found it converts an integer to a string and affects it to the buffer
## unsignedintPrint
This function is called if %u is foundit  converts a positive integer to a string and affects it to the buffer
## binaryPrint
This function converts a decimal number to binary
## hexaPrint
This function is called if %x is found it converts a decimal to a hexa with lower case alphabet [0-9][a-f]
## hexaUpperPrint
This function is called if %X is found it converts a decimal to a hexa with upper case alphabet [0-9][A-F]
## reverseStringPrint
This function is called if %r is found it reverses a string given as parameter
## rot13
This function is called if %R it converts a string to ROT13 encoding
## holberton.h
Header file that contains prototypes for all the functions and a struct holding a function and a character
## man_3_printf
Custom man page created for our printf function
# EXAMPLE
_printf("hello %s", "world");
prints Hello world
## Authors
taib kefi & yacine kedidi