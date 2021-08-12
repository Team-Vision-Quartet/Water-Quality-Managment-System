
// include the library code:
#include <LiquidCrystal.h>
long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

int Waterlevel = 0;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int pingPin=6;
int LDRSTATUS = 0;
void setup() {
  pinMode(pingPin, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(10, OUTPUT);
  // set up the LCD's number of columns ,and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  
}

void loop() {
  long duration, cm;
  LDRSTATUS = analogRead(A0);

 
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);

  
  if(cm > 300) {
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("NO_WATER...!!!!");
    digitalWrite(9, LOW);
    lcd.setCursor(0, 1);
    lcd.print("MOTOR IS OFF:(:(");
    
    
    
  }
  if(cm < 100) {
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    lcd.setCursor(0, 0);
    lcd.print("WATER IS THERE");
    if (LDRSTATUS > 100) {
      digitalWrite(9, HIGH);
      lcd.setCursor(0, 1);
      lcd.print("WATER IS TURBID!!!!");
      digitalWrite(13, LOW);
      digitalWrite(10, LOW);
      delay(3000);
      lcd.setCursor(0, 1);
      lcd.print("MOTOR IS OFF.....");
      delay(3000);
      
    } else {
      digitalWrite(9, LOW);
      lcd.setCursor(0, 1);
      lcd.print("Quality is good!!!!");
      digitalWrite(13, LOW);
      digitalWrite(10, HIGH);
      delay(3000);
      lcd.setCursor(0, 1);
      lcd.print("MOTOR IS ON.....");
      delay(3000);
      
      
    }
    
  }
  
  
  delay(100);

  
}
 