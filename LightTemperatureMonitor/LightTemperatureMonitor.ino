const int LDR_PIN= A0;
const int LM_PIN= A1;
const int BUZZER_PIN= A2;
const int RED_PIN= 9;
const int GREEN_PIN= 10;
const int BLUE_PIN= 11;

float Temperature(int value){
  float temp= ((value* 5.0)/ 1024.0)* 100;
  return temp;
}

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int light= analogRead(LDR_PIN);
  int value= analogRead(LM_PIN);

  float temp= Temperature(value);
  Serial.print("Light: "); 
  Serial.print(light);
  Serial.print(" | Temperature: "); 
  Serial.print(temp);
  Serial.println("°C ");

  if(temp> 30){
    analogWrite(RED_PIN, 255);
    analogWrite(GREEN_PIN, 0);
    analogWrite(BLUE_PIN, 0);
    tone(BUZZER_PIN, 200);
    delay(1000);
    noTone(BUZZER_PIN);
  }
  else if(temp> 20){
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, 255);
    analogWrite(BLUE_PIN, 0);
  }
  else{
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, 0);
    analogWrite(BLUE_PIN, 255);
  }
  delay(10000);
}