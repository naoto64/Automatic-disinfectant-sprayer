#define ECHO_PIN 4  // Echo Pin
#define TRIG_PIN 3  // Trigger Pin
#define SERVO_PIN 0 // Servo Pin
#define K 2*1000000/340/100

long distance = 0;
int i;

void servo_0(){
  for(i = 0; i < 570; i++){
    digitalWrite(SERVO_PIN, HIGH);
    delayMicroseconds(500);
    digitalWrite(SERVO_PIN, LOW);
    delay(3);
  }
}


void servo_180(){
  for(i = 0; i < 180; i++){
    digitalWrite(SERVO_PIN, HIGH);
    delayMicroseconds(2400);
    digitalWrite(SERVO_PIN, LOW);
    delay(3);
  }
}

void setup(){
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(SERVO_PIN, OUTPUT);
  servo_180();
}

void loop(){
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  distance = pulseIn(ECHO_PIN, HIGH, 1000000);
  if(distance > 0){
    distance /= K;
    if(distance < 15){
      servo_0();
      servo_180();
    }
  }
  delay(500);
}
