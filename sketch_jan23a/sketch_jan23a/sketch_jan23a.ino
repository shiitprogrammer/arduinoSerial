int new_rpm1 = 0;
int new_rpm2 = 0;
int old_rpm1 = 0;
int old_rpm2 = 0;
int motor1 = 0;
int motor2 = 0;


void select_motor(char x, int value) {
  if (x == 'a') {
    new_rpm1 = map(value,0,4000,0,255);
    motor1 = 5;
    motor2 = 2;
  }
  if (x == 'b') {
    new_rpm2 = map(value,0,4000,0,255);
    motor1 = 2;
    motor2 = 11;
  }
  if (x == 'c') {
    new_rpm1 = map(value,0,4000,0,255);
    new_rpm2 = map(value,0,4000,0,255);
    motor1 = 5;
    motor2 = 11;
  }
}

void write_motor(int speed) {
      analogWrite(motor1,speed);
      analogWrite(motor1-2,0);
      analogWrite(motor2,speed);
      analogWrite(motor2-2,0);
}

void set_motorspeed(int new_speed1,int new_speed2,int old_speed1,int old_speed2) {
  if (new_speed1 == 0) {

    for (int i= old_speed1; i> 25; i--) {
      write_motor(i);
      delay(100);
    }
  write_motor(0);
  old_speed1 = 0;

  }
    if (new_speed2 == 0) {

    for (int i= old_speed2; i> 25; i--) {
      write_motor(i);
      delay(100);
    }
  write_motor(0);
  old_speed2 = 0;

  }
  if (old_speed1 < new_speed1)
  {
    for (int i= old_speed1; i< new_speed1; i++) {
      write_motor(i);
      delay(100);
   
    }
  } 
    if (old_speed2 < new_speed2)
  {
    for (int i= old_speed2; i< new_speed2; i++) {
      write_motor(i);
      delay(100);
   
    }
  } 
  if (old_speed1 > new_speed1) {
  for (int i= old_speed1; i> new_speed1; i--) {
      write_motor(i);
      delay(100);

    }
  }
    if (old_speed2 > new_speed2) {
  for (int i= old_speed2; i> new_speed2; i--) {
      write_motor(i);
      delay(100);

    }
  }
}
void setup() {
  // put your setup code here, to run once:
pinMode(3, OUTPUT);
pinMode(5, OUTPUT);
pinMode(9, OUTPUT);
pinMode(11, OUTPUT);
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
  char last = message.charAt(message.length() - 1);
  int message_int = message.toInt();
  select_motor(last, message_int);
  set_motorspeed(new_rpm1,new_rpm2,old_rpm1,old_rpm2);
  
  }

old_rpm1 = new_rpm1;
old_rpm2 = new_rpm2;
} 




