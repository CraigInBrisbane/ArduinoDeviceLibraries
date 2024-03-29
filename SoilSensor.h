﻿class SoilSensor {
    private:
        int Sensor_PIN                  = 0;
        int Power_PIN                   = 0;
        int Poll_Interval               = 0;
        int readValue                   = 0;
        unsigned long previousMillis    = 0;
        bool DebugMode                  = false;

    public:


        // Constructor for the Sensor.
        SoilSensor() {
        }
    
        // Initialise the settings.
        void Init(int SensorPin, int PowerPin, int PollInterval) {
            // Setup the pins.
            Sensor_PIN =    SensorPin;
            Power_PIN =     PowerPin;
            Poll_Interval = PollInterval;
            // Set the pin modes.
            pinMode(Sensor_PIN, INPUT);
            pinMode(Power_PIN, OUTPUT);
        }

        // Set the debug mode.
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
                if(DebugMode) {
                    Serial.print("Will read... Sensor Pin: ");
                    Serial.print(Sensor_PIN);
                    Serial.print(", Power Pin: ");
                    Serial.println(Power_PIN);
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

                if(DebugMode) {
                    Serial.print("Read value ");
                    Serial.println(readValue);
                }

                // Return the last read value.
                return readValue;
            }
            return -1;
        }
};
