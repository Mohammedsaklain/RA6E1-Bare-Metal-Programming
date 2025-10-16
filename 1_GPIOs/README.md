## Aim of this Project: 
To setup clocks, gpio's and to create the gpio driver. Make use of inbuilt push button for input data read with blocking mode.
### Output
Toggles Inbuilt LED when User button(S1) is pressed. The basic switch debouncing logic is adapted to eliminate debouncing effect.


### Theory:

• All pins except P109 (as TDO of JTAG ports) operate as input pins immediately after a reset, and pin functions are switched by register settings.
