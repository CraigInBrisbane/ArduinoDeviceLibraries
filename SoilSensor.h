class SoilSensor {
    private:
        int Sensor_PIN                  = 0;
        int Power_PIN                   = 0;
        int Poll_Interval               = 0;
        int readValue                   = 0;
        unsigned long previousMillis    = 0;

    public:


        // Constructor for the Sensor.
        SoilSensor() {
        }
    
        // Initialise the settings.
        Setup(int SensorPin, int PowerPin, int PollInterval) {
            Sensor_PIN =    SensorPin;
            Power_PIN =     PowerPin;
            Poll_Interval = PollInterval;
        }

        // Method called to see if we have any updated from the sensor, based on the Poll Interval time.
        int Update() {

            // Are we ready to send updated?
            if(Sensor_PIN == 0)
                return;

            unsigned long currentMillis = millis();

            // Check if we're due a poll.
            if(currentMillis - previousMillis > Poll_Interval) {
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
                // Return the last read value.
                return readValue;
            }
        }
};
