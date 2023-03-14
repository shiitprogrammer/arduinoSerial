int new_rpm;
int old_rpm1;
int old_rpm2;
int motor1 = 0;
int motor2 = 0;
int old_speed1;
int old_speed2;

void blink(int duration) {
  for (int i = 0; i < duration; i++) {
    digitalWrite(13,HIGH);
    delay(10);
    digitalWrite(13,LOW);
    delay(10);
  }

}

void control_motor(int new_speed, int old_speed, int motor) {
    if (new_speed == 0) {

    for (int i= old_speed; i> 25; i--) {
      
      write_motor(motor, i);
      delay(10);
      
    }
      stop_motor(motor);
      old_speed = 0;

  }
  if (old_speed < new_speed)
  {
    for (int i= old_speed; i< new_speed; i++) {
      write_motor(motor, i);
      delay(10);
    }
  } 
  if (old_speed > new_speed) {
  for (int i= old_speed; i> new_speed; i--) {
      write_motor(motor, i);
      delay(10);
    }
  }
}

void write_motor(int motor, int i) {
  analogWrite(motor,i);
  analogWrite(motor-2,0);
}
void stop_motor(int motor) {
  analogWrite(motor,0);
  analogWrite(motor-2,0);
}

void motorspeed(int new_speed,int old_speed1,int old_speed2, char motortype) {
  int new_speed1 = 0;
  int new_speed2 = 0;
  if (motortype == 'a') {
    motor1 = 5;
    motor2 = 2;
    new_speed1 = new_speed;
    new_speed2 = old_speed2;
    
  }
    
  if (motortype == 'b') {
    motor1 = 2;
    motor2 = 11;
    new_speed1 = old_speed1;
    new_speed2 = new_speed;
    
  }
  if (motortype == 'c') {
    motor1 = 5;
    motor2 = 11;
    new_speed1 = new_speed;
    new_speed2 = new_speed;
    
  }

  control_motor(new_speed1,old_speed1,motor1);
  control_motor(new_speed2,old_speed2,motor2);
}
void setup() {
  // put your setup code here, to run once:
pinMode(3, OUTPUT);
pinMode(5, OUTPUT);
pinMode(9, OUTPUT);
pinMode(11, OUTPUT);
pinMode(LED_BUILTIN, OUTPUT);
Serial.begin(9600);
int old_speed1;
int old_speed2;
}

void loop() {
int new_speed1;
int new_speed2;
  // put your main code here, to run repeatedly:
String message = "";
if ( Serial.available())
  {
  message = Serial.readString();
  char last = message.charAt(message.length() - 1);
  int message_int = message.toInt();
  new_rpm = map(message_int,0,4000,0,255);
  motorspeed(new_rpm,old_speed1,old_speed2,last );
  
  }

old_speed1 = new_speed1;
old_speed2 = new_speed2;

}





