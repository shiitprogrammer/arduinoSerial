int new_rpm = 0;
int old_rpm;


void blink() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(20);
  digitalWrite(LED_BUILTIN, LOW);
  delay(20);
}

void motorspeed(int new_speed,int old_speed, int motor) {
  if (old_speed < new_speed)
  {
    for (int i= old_rpm; i< new_speed; i++) {
      analogWrite(motor,i);
      analogWrite(motor-2,i);
      delay(10);
      blink();
    }
  } 
}
void setup() {
  // put your setup code here, to run once:
pinMode(3, OUTPUT);
pinMode(LED_BUILTIN, OUTPUT);
Serial.begin(9600);
old_rpm = 0;

}

void loop() {
  // put your main code here, to run repeatedly:
String message = "";
if ( Serial.available())
  {
  message = Serial.readString();
  int message_int = message.toInt();
  new_rpm = map(message_int,0,4000,0,255);
  motorspeed(new_rpm,old_rpm, 5);
  
  }

old_rpm = new_rpm;
} 




