#define BUZZER  26
const int VALUE_THRESHOLD=30;
int TOUCH_SENSOR_VALUE_1;
int TOUCH_SENSOR_VALUE_2;
int TOUCH_SENSOR_VALUE_3;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER, OUTPUT);
  Serial.begin(115200);
  delay(2000);
  digitalWrite(BUZZER, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  TOUCH_SENSOR_VALUE_1 = touchRead(T5);
  TOUCH_SENSOR_VALUE_2 = touchRead(T6);
  TOUCH_SENSOR_VALUE_3 = touchRead(T7);
  
  Serial.print("TOUCH_SENSOR_VALUE_1:");
  Serial.print(TOUCH_SENSOR_VALUE_1);
  Serial.print("     ");
  Serial.print("TOUCH_SENSOR_VALUE_2:");
  Serial.print(TOUCH_SENSOR_VALUE_2);
  Serial.print("     ");
  Serial.print("TOUCH_SENSOR_VALUE_3:");
  Serial.print(TOUCH_SENSOR_VALUE_3);
  Serial.print("     ");
  delay(500);

  if (TOUCH_SENSOR_VALUE_1<VALUE_THRESHOLD){
    for (int i=0;i<2;i++){
      digitalWrite(BUZZER, HIGH);
      delay(100);
      digitalWrite(BUZZER, LOW);
      delay(100);
    }
  }
  if (TOUCH_SENSOR_VALUE_2<VALUE_THRESHOLD){
    for (int i=0;i<5;i++){
      digitalWrite(BUZZER, HIGH);
      delay(50);
      digitalWrite(BUZZER, LOW);
      delay(50);
    }
  }
  if (TOUCH_SENSOR_VALUE_3<VALUE_THRESHOLD){
    for (int i=0;i<8;i++){
      digitalWrite(BUZZER, HIGH);
      delay(25);
      digitalWrite(BUZZER, LOW);
      delay(25);
    }
  }
  else{
    digitalWrite(2,LOW);
  }
}