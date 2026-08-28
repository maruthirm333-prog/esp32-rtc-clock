 #include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  if (!rtc.begin()) {
    Serial.println("DS3231 NOT FOUND!");
    while (1);
  }

  // SET RTC TO YOUR COMPUTER'S DATE & TIME
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  Serial.println("RTC SET SUCCESSFULLY");
}

void loop() {
  DateTime now = rtc.now();

  Serial.print(now.year());
  Serial.print("-");
  
  if (now.month() < 10) Serial.print("0");
  Serial.print(now.month());
  Serial.print("-");
  
  if (now.day() < 10) Serial.print("0");
  Serial.print(now.day());
  
  Serial.print(" ");

  if (now.hour() < 10) Serial.print("0");
  Serial.print(now.hour());
  Serial.print(":");

  if (now.minute() < 10) Serial.print("0");
  Serial.print(now.minute());
  Serial.print(":");

  if (now.second() < 10) Serial.print("0");
  Serial.println(now.second());

  delay(1000);
}