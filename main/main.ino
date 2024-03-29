#include <Arduino.h>
//#include <Wire.h>
#include <Omron_D6FPH.h>

Omron_D6FPH mySensor;

void setup() {
    Serial.begin(9600);
    //Wire.begin();
    mySensor.begin(MODEL_0505AD3);
} 

void loop() {

    float pressure = mySensor.getPressure();
    if(isnan(pressure)){
    Serial.println("Error: Could not read pressure data");
    }else{
        Serial.print("Differential Pressure: ");
        Serial.println(pressure);
    }

    float temperature = mySensor.getTemperature();
    if(isnan(temperature)){
    Serial.println("Error: Could not read temperature data");
    }else{
        Serial.print("Temperature C: ");
        Serial.println(temperature);
    }
  delay(5000);
}
