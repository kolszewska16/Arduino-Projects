#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

const int BUZZER= A0;

const int RED= 2;
const int GREEN= 3;

const int BUTTON1= 4;
const int BUTTON2= 5;
const int BUTTON3= 6;
const int BUTTON4= 7;

const int correctSequence[4]= {BUTTON4, BUTTON1, BUTTON3, BUTTON2};
int inputSequence[4];
int inputIndex= 0;
int attempts= 0;
unsigned long lockTime;

int getButton(){
  if(digitalRead(BUTTON1)== LOW){
    return BUTTON1;
  }
  if(digitalRead(BUTTON2)== LOW){
    return BUTTON2;
  }
  if(digitalRead(BUTTON3)== LOW){
    return BUTTON3;
  }
  if(digitalRead(BUTTON4)== LOW){
    return BUTTON4;
  }
  return 1;
}

bool checkSystem(){
  for(int i= 0; i< 4; i++){
    if(inputSequence[i]!= correctSequence[i]){
      return false;
    }
  }
  return true;
}

void unlockedSystem(){
  digitalWrite(GREEN, HIGH);
  digitalWrite(RED, LOW);
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("UNLOCKED");
}

void lockedSystem(){
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  tone(BUZZER, 50);
  delay(1000);
  noTone(BUZZER);
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("LOCKED");
  delay(2000);
}

void reset(){
  delay(5000);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  lcd.clear();
}

void setup() {
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  pinMode(BUTTON4, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  lcd.begin(16, 2);
}

void loop() {
  if(millis()< lockTime){
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("PLEASE, WAIT");
    delay(6000);
    lcd.clear();
    return;
  }

  for(int i= 0; i< 4; i++){
    if(i== 0){
      lcd.setCursor(2, 0);
      lcd.print("ENTER THE PIN");
    }
 
    switch(inputIndex){
      case 1:
        lcd.setCursor(6, 1);
        lcd.print("*");
        delay(150);
        break;
      case 2:
        lcd.setCursor(6, 1);
        lcd.print("**");
        delay(150);
        break;
      case 3:
        lcd.setCursor(6, 1);
        lcd.print("***");
        delay(150);
        break;
      case 4:
        lcd.setCursor(6, 1);
        lcd.print("****")
        delay(200);
        break;
    }
 
    int button= getButton();

    if(button!= 1){
      inputSequence[inputIndex]= button;
      inputIndex++;
      delay(250);
    }
  }

  if(inputIndex== 4){
    checkSystem();

    if(checkSystem()){
      unlockedSystem();
      inputIndex= 0;
      delay(10000);
      attempts= 0;
      reset();
    }
    else{
      lockedSystem();
      inputIndex= 0;
      attempts++;
      lcd.setCursor(0, 0);
      lcd.print("FAILED ATTEMPTS");
      lcd.setCursor(8, 1);
      lcd.print(attempts);
      reset();
    }

    if(attempts== 3){
      lockTime= millis()+ 10000;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("TRY AGAIN AFTER");
      lcd.setCursor(6, 1);
      lcd.print("10s");
      delay(2000);
      attempts= 0;
      inputIndex= 0;
    }
  }
}