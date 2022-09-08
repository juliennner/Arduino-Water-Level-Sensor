int level;
 int volume; 
 float capacity;
 float sensor;
 int potpin=A1;
 int led1=7;
 int led2=6;
 int led3=5;
 int motorpin=4;
void setup() {
 
  // put your setup code here, to run once:
  //functions for reading from pins
pinMode(potpin, INPUT);
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(motorpin,OUTPUT);
Serial.begin(9600);
}

void loop() {

    
//The level is read from potentiometer
  level=analogRead(potpin);
  sensor=map (level,0,1023,0,5);
  capacity=map(level,0,1023,0,6000);
  Serial.print(capacity);
  
// put your main code here, to run repeatedly:
//function for reading sensor input
//contol using if statement

 if(capacity < 1000){
  Serial.println("Tank is empty");
   digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
     digitalWrite(led3,LOW);
   digitalWrite(motorpin,HIGH);}
// Led1 lights and the motor runs when the tank is empty

else if (capacity<2000){
  Serial.println("Ready to refill");
   digitalWrite(led1,LOW);
    digitalWrite(led3,LOW);
   digitalWrite(led2,HIGH);
   digitalWrite(motorpin,HIGH);}
//Led2 lights and the motor runs to signal for refilling.
  
else if (4500 < capacity < 5800 ){
  Serial.println("Tank is full"); 
   digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
   digitalWrite(led3,HIGH);
    digitalWrite(motorpin,HIGH);
   
   }
//Led3 lights to signal that the tank is full and the motor runs when the capacity is less than 6000.
 else  (5800<capacity<6000);{
  digitalWrite(motorpin,LOW);
 } 

   }
   
 //The motor stops running when the capacity reaches 6000.
