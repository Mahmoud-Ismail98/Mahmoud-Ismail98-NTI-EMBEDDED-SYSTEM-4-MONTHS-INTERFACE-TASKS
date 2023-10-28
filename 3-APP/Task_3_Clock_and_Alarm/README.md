## Discription
This is a simple alarm clock and clock application. It allows the user to choose between alarm mode and clock mode. In alarm mode, the user can set the alarm time in seconds. In clock mode, the application will display the current time in HH:MM:SS format.

The application uses a timer to generate a countdown for the alarm. If the alarm is enabled, the application will sound a buzzer when the countdown reaches zero.

The application also uses a keypad to allow the user to input the alarm time and choose between alarm mode and clock mode.

### Brief description of the different functions in the application:
- Timer0_AlarmCallBack(): This function is called every time the timer overflows. It decrements the alarm value and sounds the buzzer if the alarm is enabled.
- Timer0_TimerCallBack(): This function is called every time the timer overflows. It increments the hours, minutes, and seconds variables and updates the LCD display.
- main(): This is the main function of the application. It initializes the hardware and peripherals, and then starts the timer. It then waits for the user to press a button on the keypad. If the user presses button 1, the application enters alarm mode. If the user presses button 2, the application enters clock mode. If the user presses any other button, the application displays an error message.

  Overall, this is a simple but functional alarm clock and clock application. It can be used to set alarms and display the current time.


## Drivers
| # | MCAL |
| ------ | ------ |
| 1 | Port |
| 2 | DIO |
| 3 | CLCD |
| 4 | Timer |
| 5 | KeyPad |

## Video


https://github.com/MAHMOUD-ELIMBABI/NTI_Interfacing/assets/40310192/cb776d65-0b02-4385-b28b-8f720ea642cb

