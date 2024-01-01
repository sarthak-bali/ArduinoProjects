//library for LCD Display
#include <LiquidCrystal.h>

//library for DHT Sensor
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2
#define DHTTYPE DHT11


DHT_Unified dht(2, DHT11);

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

uint32_t delayMS;

void setup() 
{
  //initializing the LCD and the DHT Sensor
  lcd.begin(16, 2);
  dht.begin();
}

void loop()
{
  //delay between readings
  delay(delayMS);
  sensors_event_t event;
  
  //pulling the temperature value
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    lcd.print(F("Error reading temperature!"));
  }

  //printing temperature value
  else{
    lcd.setCursor(0, 1);
    lcd.print(F("Temperature:"));
    lcd.print(event.temperature);
    lcd.print(F("C"));
  }

  //pulling humidity value
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity))
  {
    lcd.setCursor(0, 0);
    lcd.print(F("Error reading humidity!"));
  }
  
  //printing humidity value
  else
  {
  lcd.setCursor(0, 0);
  lcd.print(F("Humidity: "));
  lcd.print(event.relative_humidity);
  lcd.print(F("%"));
  }

  delay(100);

}
