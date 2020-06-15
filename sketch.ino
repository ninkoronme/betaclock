#include <LiquidCrystal.h>
#include <DS3231.h>

DS3231  rtc(SDA, SCL);

int hours = 15; // set current hour
int mins = 0; // set current minute
int seconds = 0; // set current sec

int dayy = 1; //set current day
int monthh = 1; // set current month
int yearr = 2000; // set current year

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(115200);
  rtc.begin();
  
  rtc.setDOW(SUNDAY);     // PLEASE SET CURRENT DAY OF WEEK
  rtc.setTime(hours, mins, seconds);     
  rtc.setDate(dayy, monthh, yearr);  
  
  lcd.begin(16, 2);
  lcd.print("  Moscow time:  ");
}

void loop() {

  // lcd displaying.
  
  lcd.setCursor(0, 1);
  lcd.print(rtc.getTimeStr()); // display time
  lcd.print(" ");
  lcd.print(rtc.getDateStr()); // display date

  // some serial port things lmao
  
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");

  Serial.println(rtc.getTimeStr());
  delay(1000);
}
