#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int VRx = A0;      // X-axis
const int VRy = A1;      // Y-axis
const int SW  = 2;       // Joystick button (active LOW)

LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD I2C address 0x27, 16 columns x 2 rows

const int centerX = 512;
const int centerY = 512;
const int deadZone = 50;

const unsigned long debounceDelay = 50; // ms

bool lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(SW, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Joystick Ready");
  delay(1000);
}

void loop() {
  int rawX = analogRead(VRx);
  int rawY = analogRead(VRy);
  int x = rawX - centerX;
  int y = rawY - centerY;

  // Apply dead zone
  if (abs(x) < deadZone) x = 0;
  if (abs(y) < deadZone) y = 0;

  // Debounce button
  bool currentButtonState = digitalRead(SW);
  if (currentButtonState != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (currentButtonState != lastButtonState) {
      lastButtonState = currentButtonState;
    }
  }

  String direction = getDirection(x, y);
  String buttonState = lastButtonState == LOW ? "Pressed" : "Released";

  // Serial Output
  Serial.print("X: "); Serial.print(x);
  Serial.print(" | Y: "); Serial.print(y);
  Serial.print(" | Dir: "); Serial.print(direction);
  Serial.print(" | Button: "); Serial.println(buttonState);

  // LCD Output
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Dir:");
  lcd.print(direction);
  lcd.setCursor(0, 1);
  lcd.print("X:");
  lcd.print(x);
  lcd.print(" Y:");
  lcd.print(y);
  lcd.print(lastButtonState == LOW ? " P" : " R"); // P = Pressed, R = Released

  delay(500);
}

String getDirection(int x, int y) {
  if (x == 0 && y == 0) return "Center";
  if (x == 0 && y > 0) return "Up";
  if (x == 0 && y < 0) return "Down";
  if (x > 0 && y == 0) return "Left";
  if (x < 0 && y == 0) return "Right";
  if (x > 0 && y > 0) return "Up-Left";
  if (x < 0 && y > 0) return "Up-Right";
  if (x > 0 && y < 0) return "Down-Left";
  if (x < 0 && y < 0) return "Down-Right";
  return "Unknown";
}