#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

#define DHT_PIN 2
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
 // Clear the buffer

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  if(!isnan(temperature) && !isnan(humidity)) {
  display.clearDisplay();

  display.setCursor(0, 0);
  display.print(F("The Weather"));
  display.setCursor(0, 10);
  display.print(F("Temperature: "));
  display.print(temperature);
  display.println(F(" \370C"));

  display.setCursor(0, 20);
  display.print(F("Humidity: "));
  display.print(humidity/2.5);
  display.println(F(" %"));

  display.display();
  }
  else {
    Serial.println(F("Failed to read from DHT sensor!"));
  }
  delay(1000);
}

