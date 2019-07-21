/*
 * A class that handles a flashing LED.
 */
class FlashingLed {
  int   ledPin;
  long  onTime;
  long  offTime;
  int   state;
  unsigned long previousMillis;

  public:
  FlashingLed() {
  }

  void Init(int LedPin, long On, long Off) {
    ledPin = LedPin;
    onTime = On;
    offTime = Off;
    pinMode(LedPin, OUTPUT);
    state = LOW;
    previousMillis = 0;
  }


  void Update() {
    unsigned long currentMillis = millis();
    
    if((state == HIGH) and (currentMillis - previousMillis >= onTime)) {
      state = LOW;
      previousMillis = currentMillis;
      digitalWrite(ledPin, state);
    } 
    else
    if((state==LOW) and (currentMillis - previousMillis >= offTime)) {
      state = HIGH;
      previousMillis = currentMillis;
      digitalWrite(ledPin, state);
    }
  }
};
