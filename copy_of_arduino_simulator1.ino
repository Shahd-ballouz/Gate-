#define LED 10
#define LDR1 A0
#define LDR2 A1
#define buzzer 12
void setup() { Serial.begin(9600);
pinMode(LED,OUTPUT);
pinMode(LDR1,INPUT);
pinMode(LDR2,INPUT); 
pinMode(buzzer,OUTPUT);              
}
void loop() {
int count=0; 
int LDRStatus1 = analogRead(LDR1);
int LDRStatus2 = analogRead(LDR2);
  for (int i=0;i<6;i++){  
  
if (LDRStatus1 <= 200&&LDRStatus2 <= 200 ) {

digitalWrite(LED, HIGH);
delay(1000);
digitalWrite(LED, LOW);
delay(1000);
  count++;}
}if(count==5){
tone(buzzer, 100); 
delay(1000);
Serial.println("Maximum people have been reached");
}
}