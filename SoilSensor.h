class SoilSensor {
    private:
        int Sensor_PIN                  = 0;
        int Power_PIN                   = 0;
        int Poll_Interval               = 0;
        int readValue                   = 0;
        unsigned long previousMillis    = 0;
        bool debugMode                  = false;

    public:


        // Constructor for the Sensor.
        SoilSensor() {
        }
    
        // Initialise the settings.
        void Init(int SensorPin, int PowerPin, int PollInterval) {
            Sensor_PIN =    SensorPin;
            Power_PIN =     PowerPin;
            Poll_Interval = PollInterval;
        }

        void SetDebugMode(bool DebugMode) {
            debugMode = DebugMode;
            if(DebugMode==true) {
                Serial.begin(9600);
                Serial.println("Debug mode enabled on SoilSensor...");
            }
        }

        // Method called to see if we have any updated from the sensor, based on the Poll Interval time.
        int Update() {


            // Are we ready to send updated?
            if(Sensor_PIN == 0) {
                if(DebugMode==true) {
                    Serial.println("Update called, but Init has not been called yet. Returning -1");
                }
                return -1;
            }

            unsigned long currentMillis = millis();

            // Check if we're due a poll.
            if(currentMillis - previousMillis > Poll_Interval) {
                if(DebugMode==true) {
                    Serial.println("Will read...");
                }

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

                // Return the last read value.
                return readValue;
            }

            if(DebugMode == true) {
                Serial.print("Update triggered, but poll value is ");
                Serial.print(Poll_Interval);
                Serial.print(", but difference is ");
                Serial.println(currentMillis - previousMillis);
            }
        }
};
