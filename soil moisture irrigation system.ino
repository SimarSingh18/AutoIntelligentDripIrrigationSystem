#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
 
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("IRRIGATION");
  lcd.setCursor(0, 1);
  lcd.print("SYSTEM IS ON ");
    lcd.print("");
    delay(3000);
  lcd.clear();
}
 //to check the value of moisture
void loop() {
  int value = analogRead(A0);
  Serial.println(value); // range of soil moisture sensor is -> 0 to 1023 || high value = less moisture and vice versa
  if (value > 950) {   //value can be set according to the moisture level required by the crop (a crop can require more water so we can set the value accordinly so that the crop gets the required amount of water)
    digitalWrite(2, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Water Pump is ON ");
  } else {
    digitalWrite(2, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Water Pump is OFF");
  }
  //to tell about the moisture
  if (value < 300) {
    lcd.setCursor(0, 1);
    lcd.print("Moisture : HIGH");
  } else if (value > 300 && value < 950) {
    lcd.setCursor(0, 1);
    lcd.print("Moisture : MID ");
  } else if (value > 950) {
    lcd.setCursor(0, 1);
    lcd.print("Moisture : LOW ");
  }
}