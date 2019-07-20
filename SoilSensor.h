class SoilSensor {
    private:
        int Sensor_PIN                  = 0;
        int Power_PIN                   = 0;
        int LED_Pin                     = 0;
        int Poll_Interval               = 0;
        int readValue                   = 0;
        unsigned long previousMillis    = 0;
        bool DebugMode                  = false;

    public:


        // Constructor for the Sensor.
        SoilSensor() {
        }
    
        // Initialise the settings.
        void Init(int SensorPin, int PowerPin, int LEDPin, int PollInterval) {
            Sensor_PIN =    SensorPin;
            Power_PIN =     PowerPin;
            Poll_Interval = PollInterval;
            LED_Pin =       LED_Pin;
        }

        void SetDebugMode(bool mode) {
            DebugMode = mode;
            if(DebugMode==true) {
                Serial.begin(9600);
                Serial.println("Debug mode enabled on SoilSensor...");
            }
        }

        // Method called to see if we have any updated from the sensor, based on the Poll Interval time.
        int Update() {


            // Are we ready to send updated?
            if(Sensor_PIN == 0) {
                return -1;
            }

            unsigned long currentMillis = millis();

            // Check if we're due a poll.
            if(currentMillis - previousMillis > Poll_Interval) {
                if(DebugMode==true) {
                    Serial.print("Will read... Sensor Pin: ");
                    Serial.print(Sensor_PIN);
                    Serial.print(", Power Pin: ");
                    Serial.println(Power_PIN);
                }

                // We need to power down the LED, as it's draws power, and we need as much as possible for the sensor.
                int initialLEDValue = digitalRead(LED_Pin);                
                if(initialLEDValue == HIGH)
                    digitalWrite(LED_Pin, LOW);

                // Switch on the sensor.
                digitalWrite(Power_PIN, HIGH);
                // Let the sensor get ready for 20ms.
                delay(20);
                // read the value
                readValue = analogRead(Sensor_PIN);
                // Switch off the sensor to save power. 
                digitalWrite(Power_PIN, LOW);
                // Record the last time a value was read.
                previousMillis = currentMillis;

                if(DebugMode==true) {
                    Serial.print("Read value ");
                    Serial.println(readValue);
                }

                // Restore the LED state.
                if(initialLEDValue == HIGH)
                    digitalWrite(LED_Pin, initialLEDValue);

                // Return the last read value.
                return readValue;
            }

            return -1;
        }
};
