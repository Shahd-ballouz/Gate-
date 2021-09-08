#define LED 10
#define LDR1 A0
#define LDR2 A1
#define buzzer 5
int count = 0;
void setup() { Serial.begin(9600);
pinMode(LED,OUTPUT);
pinMode(LDR1,INPUT);
pinMode(LDR2,INPUT); 
pinMode(buzzer,OUTPUT);              
}
void loop() {  
int LDRStatus1 = analogRead(LDR1);
int LDRStatus2 = analogRead(LDR2);
if (LDRStatus1 <= 200 && count < 6) {
  count++;
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(1000);
  }
if (LDRStatus2 <= 200 && count != 0) {
  count--;
  }
if(count == 0 ){
    Serial.println("There are no people in the room.");
  }
  Serial.println(count);
  Serial.println(LDRStatus1);
  Serial.println(LDRStatus2);
  delay(1000);
if(count==5){
  Serial.println("Maximum people have been reached.");
  tone(buzzer, 100); 
  delay(2000);
  noTone(buzzer); 
  digitalWrite(LED, LOW);
  delay(500);
}
}
