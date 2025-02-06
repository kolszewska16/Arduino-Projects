const int LDR_PIN= A0;
const int POT_PIN= A1;
const int RED_PIN= 9;
const int GREEN_PIN= 10;
const int BLUE_PIN= 11;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int light= analogRead(LDR_PIN);
  int potValue= analogRead(POT_PIN);
  int brightness= map(potValue, 0, 1023, 0, 255);

  Serial.print("Light level: "); Serial.print(light);
  Serial.print(" | Brightness level: "); Serial.println(brightness);

  if(light> 200&& light< 500){
    analogWrite(RED_PIN, brightness/ 4);
    analogWrite(GREEN_PIN, brightness/ 4);
    analogWrite(BLUE_PIN, brightness/ 4);
  }
  else if(light<= 200){
    analogWrite(RED_PIN, brightness);
    analogWrite(GREEN_PIN, brightness);
    analogWrite(BLUE_PIN, brightness);
  }
  else{
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, 0);
    analogWrite(BLUE_PIN, 0);
  }
  delay(100);
}
