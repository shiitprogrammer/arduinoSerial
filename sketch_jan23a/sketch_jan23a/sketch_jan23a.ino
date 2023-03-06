int new_rpm = 0;
int old_rpm;
int motor1 = 0;
int motor2 = 0;


void motorspeed(int new_speed,int old_speed, char motortype) {
  if (motortype == 'a') {
    motor1 = 5;
    motor2 = 2;
    blink();
  }
    
  if (motortype == 'b') {
    motor1 = 2;
    motor2 = 11;
    blink();
    delay(200);
    blink();
  }
  if (motortype == 'c') {
    motor1 = 5;
    motor2 = 11;
    blink();
    delay(200);
    blink();
    delay(200);
    blink();
  }


  if (new_speed == 0) {

    for (int i= old_speed; i> 25; i--) {
      
      analogWrite(motor1,i);
      analogWrite(motor1-2,0);
      analogWrite(motor2,i);
      analogWrite(motor2-2,0);
      delay(10);
    }
      analogWrite(motor1,0);
      analogWrite(motor1-2,0);
      analogWrite(motor2,0);
      analogWrite(motor2-2,0);
  old_speed = 0;

  }
  if (old_speed < new_speed)
  {
    for (int i= old_speed; i< new_speed; i++) {
      analogWrite(motor1,i);
      analogWrite(motor1-2,0);
      analogWrite(motor2,i);
      analogWrite(motor2-2,0);
      delay(10);
   
    }
  } 
  if (old_speed > new_speed) {
  for (int i= old_speed; i> new_speed; i--) {
      analogWrite(motor1,i);
      analogWrite(motor1-2,0);
      analogWrite(motor2,i);
      analogWrite(motor2-2,0);
      delay(10);

    }
  }
}
void setup() {
  // put your setup code here, to run once:
pinMode(3, OUTPUT);
pinMode(LED_BUILTIN, OUTPUT);
Serial.begin(9600);
old_rpm1 = 30;
old_rpm2 = 30;

}

void loop() {
  // put your main code here, to run repeatedly:
String message = "";
if ( Serial.available())
  {
  message = Serial.readString();
  int message_int = message.toInt();
  new_rpm = map(message_int,0,4000,0,255);
  motorspeed(new_rpm,old_rpm,last );
  
  }

old_rpm1 = new_rpm1;
old_rpm2 = new_rpm2;
} 




