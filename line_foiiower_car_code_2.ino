#include<AFMotor.h>

#define left A0
#define right A1

AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

void setup()
{
  
  // put your setup code here, to run once:
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
  
  pinMode(left,INPUT);
  pinMode(right,INPUT);
  
  Serial.begin(9600);
  

}

void loop()
{
  // put your main code here, to run repeatedly:
  
 Serial.println(analogRead(left));
 Serial.println(analogRead(right));

 if(analogRead(left)==1 && analogRead(right)==1){
    //stop
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
  }
  //line detected by left sensor
  else if(analogRead(left)==1 && analogRead(right)==0){
    //turn left
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    
  }
  //line detected by right sensor
  else if(analogRead(left)==0 && analogRead(right)==1){
    //turn right
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);

  }
  //line detected by none
  else if(analogRead(left)==0 && analogRead(right)==0){
    //FORWARD
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    
  }
  
}




  
