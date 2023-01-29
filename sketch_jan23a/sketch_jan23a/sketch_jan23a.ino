int motor = 3;
const int BUFFER_SIZE = 50;
char buf[BUFFER_SIZE];
int a = 50;
void speedcontrol(int rpm) {
      if( rpm >= 500 && rpm <= 4000)
      { 
        
        int motorspeed = analogRead(A0);
        int speed = int(map(rpm, 0,4000,0,255));
        Serial.println(speed);
        for (a; a<speed; a++){
          analogWrite(motor, a);
        
        }
      }
      if(rpm == 0)
      {
        int b = a;
        for (b ;b>=50;--b){
        analogWrite(motor, b);
          if (b == 50){
          digitalWrite(motor,0);
          }
        }
      
      }
}

void setup() {
  // put your setup code here, to run once:
pinMode(3, OUTPUT);
pinMode(5, OUTPUT);
Serial.begin(115200);
int speed = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
char txtmessage[] = {};
String message = "";
if ( Serial.available())
  {
  message = Serial.readString();
  message.toCharArray(txtmessage, BUFFER_SIZE);
  for (int i=0;i<4;i++) {
    Serial.print(txtmessage[i]);
  }
  Serial.print(txtmessage[5]);
  

} 
  
else if (message.toInt() >= 0) {
  int rpm = message.toInt();
  speedcontrol(rpm);
}
}



