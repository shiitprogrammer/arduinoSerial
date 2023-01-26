int motor = 3;
const int BUFFER_SIZE = 50;
char buf[BUFFER_SIZE];

void speedcontrol(int rpm) {
      if( rpm >= 500 && rpm <= 4000)
      { 
        
        int motorspeed = analogRead(A0);
        int speed = int(map(rpm, 0,4000,0,255));
        Serial.println(speed);
        for (int i = 50;i<speed;i++){
          analogWrite(motor, i);
        
        }
      }
      if(rpm == 0)
      {
        for (int i = 100 ;i>50;i--){
        analogWrite(motor, i);
        Serial.println("Slowing down");
          if (i == 50){
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
String message = "";

if ( Serial.available())
  {
  int data = Serial.readBytes(buf, BUFFER_SIZE);
  for(int i = 0; i < data; i++){
    
    message += (buf[i]);
    
  }

} 
if (message == "conversation"){
  Serial.println(analogRead(A0));
}
else if (message == "setrpm"){
  Serial.println("Received");
}
  
else if (message.toInt() >= 0) {
  int rpm = message.toInt();
  speedcontrol(rpm);
}
}



