#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display


#define trig 8
#define echo 9
#define LED 7
#define buser1 6
#define buser2 5

void setup() 
{
  Serial.begin(9600);
  Serial.println("초음파 센서 시작");
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT); 
  pinMode(LED, OUTPUT);
  pinMode(buser1, OUTPUT); 
  pinMode(buser2, OUTPUT);
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  
  }

void loop() 
{
  long duration, distance;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
 

  duration = pulseIn(echo, HIGH);
  distance = duration*170/1000;
  if(distance<=90)
  {
    digitalWrite(LED, HIGH); delay(100); digitalWrite(LED, LOW); 
    digitalWrite(buser1, HIGH); delay(100); digitalWrite(buser1, LOW);
    lcd.setCursor(0,0);
    lcd.print("danger");
  
  }

if(distance>=91&&distance<=99)
{
  digitalWrite(LED, HIGH); delay(100); digitalWrite(LED, LOW); 
    digitalWrite(buser1, HIGH); delay(100); digitalWrite(buser1, LOW);
  lcd.clear();
}
 if(distance>=100&&distance<=190)
  {
    digitalWrite(LED, HIGH); delay(100); digitalWrite(LED, LOW); 
      digitalWrite(buser2, HIGH); delay(100); digitalWrite(buser2, LOW);
      lcd.setCursor(0,0);
      lcd.print("be careful");
  }
  if(distance>=191&&distance<=199)
{
  
  lcd.clear();
}
  if(distance>200)
  {
    lcd.setCursor(0,0);
    lcd.print("");
  }


   Serial.print("거리 :");
   Serial.print(distance);
   Serial.println("mm");
   delay(100);

}
