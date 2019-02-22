## Compile and run
```
make main.obj && make main.hex && make program
```


## Todo
* Update main.c to get delay time from another file, lib.c
  (main.c is the TTT program, lib.c is the buttons/lights lib)
* Call a function in lib.c to get the delay time
* Register a callback with lib.c
* Write main.c in a different language



## Plan
Write a low-level button/led library.

TTT program would import it, and be able to

	1. turn on/off led lights at indexes
	2. register callback function that's called whenever a button is pressed
	3. start/stop the program

So steps in TTT program are:

1. import library
2. register callback function (that turns on/off lights)
3. start the program while loop


## Notes
neotrellis docs: https://adafruit.github.io/Adafruit_Seesaw/html/class_adafruit___neo_trellis.html

neotrellis manual: https://cdn-learn.adafruit.com/downloads/pdf/adafruit-neotrellis.pdf

avr blink program:  https://electronics.stackexchange.com/questions/340607/avr-atmega328p-led-example

avr programming: https://hackaday.com/2010/10/23/avr-programming-introduction/

rust on arduino: http://jakegoulding.com/blog/2016/01/02/rust-on-an-arduino-uno/

avrdude:

https://www.nongnu.org/avrdude/

https://www.nongnu.org/avrdude/user-manual/avrdude.html

Importing a C++ library:

libraries are found in /Documents/Arduino/libraries

1. delete the existing one
2. zip up your updates
3. click Sketch -> Include Library -> Add .zip Library
4. click Sketch -> Include Library (if the new one doesn't show up, restart)


