#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <RTClib.h>

DateTime now;
RTC_DS3231 rtc;

LiquidCrystal_I2C lcd(0x27, 16, 2); // Adjust the I2C address if needed

void displayDate(void);
void displayTime(void);

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  if (!rtc.begin()) {
    Serial.println("RTC Module not Present");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC power failure, reset the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() {
  now = rtc.now();
  displayDate();
  displayTime();
}

void displayDate() {
  lcd.setCursor(0, 0);
  lcd.print("Date:");
  lcd.print(now.day());
  lcd.print('/');
  lcd.print(now.month());
  lcd.print('/');
  lcd.print(now.year());
}

void displayTime() {
  lcd.setCursor(0, 1);
  lcd.print("Time:");
  lcd.print(now.hour());
  lcd.print(':');
  lcd.print(now.minute());
  lcd.print(':');
  lcd.print(now.second());
  lcd.print("    ");
}
