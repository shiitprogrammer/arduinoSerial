int new_rpm;
int old_rpm1;
int old_rpm2;
int motor1 = 0;
int motor2 = 0;

void control_motor(int new_speed, int old_speed, int motor) {
    if (new_speed == 0) {

    for (int i= old_speed; i> 25; i--) {
      
      write_motor(motor);
      delay(10);
    }
      stop_motor(motor);
      old_speed = 0;

  }
  if (old_speed < new_speed)
  {
    for (int i= old_speed; i< new_speed; i++) {
      write_motor(motor);
      delay(10);
   
    }
  } 
  if (old_speed > new_speed) {
  for (int i= old_speed; i> new_speed; i--) {
      write_motor(motor);
      delay(10);

    }
  }
}

void write_motor(motor) {
  analogWrite(motor,i);
  analogWrite(motor-2,0);
}
void stop_motor(motor) {
  analogWrite(motor,0);
  analogWrite(motor-2,0);
}

void motorspeed(int new_speed,int old_speed1,int old_speed2, char motortype) {
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

  control_motor(new_speed1,old_speed1,motor1)
  control_motor(new_speed2,old_speed2,motor2)
}
void setup() {
  // put your setup code here, to run once:
pinMode(3, OUTPUT);
pinMode(5, OUTPUT);
pinMode(9, OUTPUT);
pinMode(11, OUTPUT);
pinMode(LED_BUILTIN, OUTPUT);
Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
String message = "";
if ( Serial.available())
  {
  message = Serial.readString();
  int message_int = message.toInt();
  new_rpm = map(message_int,0,4000,0,255);
  motorspeed(new_rpm,old_speed1,old_speed2,last );
  
  }

old_speed1 = new_speed1;
old_speed2 = new_speed2;

} 





