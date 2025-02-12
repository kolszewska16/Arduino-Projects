const int BUZZER= A0;

const int RED= 4;
const int GREEN= 3;

const int WHITE1= 9;
const int WHITE2= 8;
const int WHITE3= 7;
const int WHITE4= 6;

const int BUTTON1= 13;
const int BUTTON2= 12;
const int BUTTON3= 11;
const int BUTTON4= 10;

const int correctSequence[4]= {BUTTON3, BUTTON4, BUTTON2, BUTTON1};
int inputSequence[4];
int inputIndex= 0;
int attempts= 0;
int lockTime;

int getButton(){
  if(digitalRead(BUTTON1)== LOW){
    digitalWrite(WHITE1, HIGH);
    return BUTTON1;
  }
  if(digitalRead(BUTTON2)== LOW){
    digitalWrite(WHITE2, HIGH);
    return BUTTON2;
  }
  if(digitalRead(BUTTON3)== LOW){
    digitalWrite(WHITE3, HIGH);
    return BUTTON3;
  }
  if(digitalRead(BUTTON4)== LOW){
    digitalWrite(WHITE4, HIGH);
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
  Serial.println("The system is unlocked");
}

void lockedSystem(){
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  tone(BUZZER, 50);
  delay(1000);
  noTone(BUZZER);
  Serial.println("The system is locked");
}

void reset(){
  delay(5000);
  digitalWrite(WHITE1, LOW);
  digitalWrite(WHITE2, LOW);
  digitalWrite(WHITE3, LOW);
  digitalWrite(WHITE4, LOW);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
}

void setup() {
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  pinMode(BUTTON4, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(WHITE1, OUTPUT);
  pinMode(WHITE2, OUTPUT);
  pinMode(WHITE3, OUTPUT);
  pinMode(WHITE4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(millis()< lockTime){
    return;
  }
  for(int i= 0; i< 4; i++){
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
      Serial.print("Number of failed attempts: ");
      Serial.println(attempts);
      reset();
    }

    if(attempts== 3){
      lockTime= millis()+ 10000;
      Serial.println("The system is locked, try again after 10s");
      attempts= 0;
    }
  }
}