#include <Arduino.h>
#include "DHT.h"
#include <LiquidCrystal.h>

#define DHTPIN 52
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  dht.begin();
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Hallo!");
}

void loop() {
 delay(2000);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    lcd.setCursor(0,0);
    lcd.print(F("DHD error"));
    return;
  }

  float heatIndex = dht.computeHeatIndex(temperature, humidity, false);

  lcd.setCursor(0,0);
  lcd.print(F("H: "));
  lcd.print(humidity);

  lcd.setCursor(0,1);
  lcd.print(F("T:"));
  lcd.print(temperature);
  lcd.print(F("C "));

  lcd.print(F("HI:"));
  lcd.print(heatIndex);
  lcd.print(F("C"));
}