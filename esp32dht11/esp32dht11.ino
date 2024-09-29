#include "DHT.h"
#include <Adafruit_Sensor.h> // Ensure this library is available and installed

// Define the GPIO 13 of esp32 to dht11 out pin
#define DHTPIN 13
// Define the type of dht11 or dht22
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  delay(2000);  // wait 2 seconds

  // Variable to store humidity value
  float humidity = dht.readHumidity();
  // Variable to store temperature value
  float temperature = dht.readTemperature();

  // If mistake in connection or dht11 is damaged then it will execute
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Gives output
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
}
