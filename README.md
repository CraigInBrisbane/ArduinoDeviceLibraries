# Arduino Device Libraries

This is a set of device classes I use to control small components I use within my Arduino projects. 
They're very basic, and are all starter level development. I intend to enhance them as I learn
more about Arduino and best practices.


## Buzzer

```Buzzer(int Pin)```

Constructor, Accepts a pin number to which the buzzer is connected.

```Beep(int ToneTime)```

The amount of time the tone should sound for. Usually called when you want the buzzer to start buzzing.

```Update()```

Update the state of the buzzer. Usually called from within the Loop function.

## FadingLED

```FadingLed(int LedPin, int FadePeriod, int DelayedStart, bool Debug)```

Constructor, Accepts a pin number to which the buzzer is connected, the time in milliseconds to go from bright to dim, a time in milliseconds to delay the start, and a flag to indicate if logging is needed.


```Update()```

Update the state of the LED. Usually called from within the Loop function.
