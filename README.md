# M5CoreDisplay
This is a display driver for the [M5 Core BASIC](https://docs.makerfactory.io/m5stack/core/black/) display.

It's only for 320x240 pixel ILI9341 or ILI9342 TFT on ESP32.



The [display driver for M5Stack](https://github.com/m5stack/M5Stack/tree/master/src) is somewhat inconvenient, because it's huge in
source, undocumented and doesnt derive from Adafruit GFX. And the header file did not help either.

Additionally, i don't want to include the whole M5 stuff in my projects, as i need every byte of RAM..


This restructured driver is now largely compatible with Adafruit GFX,
so if you look at documentation, pls refer to the [Adafruit GFX documentation](https://learn.adafruit.com/adafruit-gfx-graphics-library).

There's one difference, pixel coordinates and colours are given as 32bit numbers,
whereas Adafruit GFX uses 16bit numbers. Take care.

Further differences:
* sleep(), wakeup() - let the display go to sleep.
* setBrightness() - control the backlight brightness, using a value 0..255
* pushColor() - set on or more pixels by a 16bit value, after a call to setAddrWindow()
* pushColors() - send an array of 16bit pixels, after a call to setAddrWindow()



# LICENSE:
As this source code now derives from both, M5Stack source and Adafruit GFX,
both licenses are mentionend here.

Of course, the whole code was restructured by me..


--Winfried
