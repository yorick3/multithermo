// Multithermo v1.0
// © 2021 - https://github.com/yorick3

// I2C LCD libraries
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// DHT22 / DHT11 libraries
#include <DHT.h>

// DS18B20 libraries
#include <OneWire.h> 
#include <DallasTemperature.h>

// I2C LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);
// Params: Address, length, rows

// Ambient sensor
#define DHTPIN 3
#define DHTTYPE DHT22
DHT ambient(DHTPIN, DHTTYPE);
float ambientHumidity;
float ambientTemperature;

// Probe sensor
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature probe(&oneWire);

void setup() {
  // Init LCD & sensors
  lcdInit();
  ambient.begin();
  probe.begin();
}

void loop() {
  // Read sensor values
  ambientHumidity = ambient.readHumidity();
  ambientTemperature = ambient.readTemperature();
  probe.requestTemperatures();
  updateDisplay(
    "A:" + String(ambientTemperature) + (char)223 + "C " + String(ambientHumidity) + "%",
    "P:" + getProbe());
  delay(4000);
}

// Init the LCD and show splash screen.
void lcdInit() {
  lcd.init();
  lcd.backlight();
  splash();
}

// Show the name and version of this program.
void splash() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("> MultiThermo");
  lcd.setCursor(0,1);
  lcd.print("> v1.0");
  delay(2000); // Duration
  lcd.clear();
}

// Updates the display to show a (new) message.
void updateDisplay(String line1, String line2) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(line1);
  lcd.setCursor(0,1);
  lcd.print(line2);
}

// Get value from probe.
// If probe is not connected or returns an invalid value,
// return "N/A".
String getProbe() {
  // Check if value is within spec for DS18B20,
  // if not, this indicates a disconnected probe.
  // https://datasheets.maximintegrated.com/en/ds/DS18B20.pdf
  float probeValue = probe.getTempCByIndex(0);
  if (probeValue >= -55 && probeValue <= 125) {
    return String(probeValue) + (char)223 + "C";
  }
  else {
    return " N/A";
  }
}