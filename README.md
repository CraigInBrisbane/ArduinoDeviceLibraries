# Arduino Device Libraries

This is a set of device classes I use to control small components I use within my Arduino projects. 
They're very basic, and are all starter level development. I intend to enhance them as I learn
more about Arduino and best practices.


## Buzzer

A class that simply starts a buzzer for a time you specify by the ```beep``` function. The Loop function will then use the Buzzer's `update` method to handle when the buzzer should stop.

```Buzzer(int Pin)```

Constructor, Accepts a pin number to which the buzzer is connected.

```Beep(int ToneTime)```

The amount of time the tone should sound for. Usually called when you want the buzzer to start buzzing.

```Update()```

Update the state of the buzzer. Usually called from within the Loop function.

## FadingLED

A class that allows you to flowly fade in and out, a LED. 

```FadingLed(int LedPin, int FadePeriod, int DelayedStart, bool Debug)```

Constructor, Accepts a pin number to which the LED is connected, the time in milliseconds to go from bright to dim, a time in milliseconds to delay the start, and a flag to indicate if logging is needed.


```Update()```

Update the state of the LED. Usually called from within the Loop function.

## FlashingLED

A class allowing for a set and forget flashing LED.

```FlashingLed(int LedPin, long On, long Off)```

Constructor, Accepts a pin number to which the LED is connected, how long the LED should stay on for, and how long the LED should stay off for..


```Update()```

Update the state of the LED. Usually called from within the Loop function.

## LED

A very basic class that allows for turning a LED on and off.

```LED(int Pin)```

Constructor, Accepts a pin number to which the LED is connected.

```On()```

Turns the LED on.

```Off()```

Turns the LED off.

## PIR Sensor

A class to manage a PIR (Motion Sensor) device.

```PirSensor(int Pin)```

Constructor, Accepts a pin number to which the PIR sensor is connected.

```Check()```

Check if the PIR sensor is detecting any movement.


