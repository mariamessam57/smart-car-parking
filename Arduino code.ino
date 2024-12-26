#include <Servo.h> 
#include <LiquidCrystal.h> 


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


Servo myservo;


#define ir_enter 8  
#define ir_exit 9   


int carCount = 0;           
const int maxCars = 4;     
int flagEnter = 0, flagExit = 0;

void setup() {
  
  Serial.begin(9600);

  
  pinMode(ir_enter, INPUT);
  pinMode(ir_exit, INPUT);
  
  
  myservo.attach(10);  
  myservo.write(90);  

  
  lcd.begin(16, 2); 
  lcd.setCursor(0, 0);
  lcd.print("   Car Parking  ");
  lcd.setCursor(0, 1);
  lcd.print("      System    ");
  delay(2000); 
  lcd.clear();

  
  lcd.setCursor(0, 0);
  lcd.print("Slots: ");
  lcd.print(maxCars - carCount);
}

void loop() {
  
  lcd.setCursor(0, 0);
  lcd.print("Slots: ");
  lcd.print(maxCars - carCount);
  lcd.print("       "); 

  lcd.setCursor(0, 1);
  lcd.print("Cars: ");
  lcd.print(carCount);
  lcd.print("       "); 

  if (digitalRead(ir_enter) == 0 && flagEnter == 0) {
    flagEnter = 1;  
    if (carCount < maxCars) {
      carCount++;
      myservo.write(180); 
      delay(1000);        
      myservo.write(90);
    } else {
      lcd.setCursor(0, 0);
      lcd.print("Parking Full     ");
      delay(1500);
      lcd.setCursor(0, 0);
      lcd.print("Slots: ");
      lcd.print(maxCars - carCount);
    }
  }
  if (digitalRead(ir_enter) == 1) {
    flagEnter = 0; 
  }

  
  if (digitalRead(ir_exit) == 0 && flagExit == 0) {
    flagExit = 1; 
    if (carCount > 0) {
      carCount--;
      myservo.write(180); 
      delay(1000);        
      myservo.write(90);  
    }
  }
  if (digitalRead(ir_exit) == 1) {
    flagExit = 0; 
  }

  delay(100); 
}
