## Discription
The app you provided is a simple calculator that can perform basic arithmetic operations (addition, subtraction, multiplication, and division). It uses a keypad to input numbers and a liquid crystal display (LCD) to display the results.

### The main loop of the program works as follows:

1. It gets the pressed button from the keypad.
1. If the button is 'c', it clears the display and resets the calculator.
1. Otherwise, it displays the button on the LCD.
1. It then checks if the pressed button is an operator (+, -, *, or /). If it is, it stores the operator in a variable and increments an equation index variable.
1. If the pressed button is the equals sign (=), it performs the operation indicated by the operator variable on the two operands (Local_u16OP1 and Local_u16OP2) and displays the result on the LCD.
1. Otherwise, the pressed button is assumed to be a number, and it is stored in the operand variable corresponding to the equation index variable.
1. The program repeats this loop until the user presses the reset button.


## Drivers
| # | MCAL |
| ------ | ------ |
| 1 | Port |
| 2 | DIO |
| 3 | CLCD |
| 4 | KeyPad |


## Video

https://github.com/MAHMOUD-ELIMBABI/NTI_Interfacing/assets/40310192/782ffdd3-7b5d-4978-9165-2ca65eb748fc

