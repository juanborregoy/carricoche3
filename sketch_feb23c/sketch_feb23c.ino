int ENA = 10;
int IN1 = 9;
int IN2 = 8;
int IN3 = 7;
int IN4 = 6;
int ENB = 5;
//sensor del
const int Echo=2;
const int Trigger=3;
//Sensor tras
const int Echo2=11;
const int Trigger2=13;
int distance;
int distance2;


void setup() {

Serial.begin(9600);
  //Sensor del
  pinMode(Trigger,OUTPUT);
  pinMode(Echo,INPUT);
  digitalWrite(Trigger,LOW);
  //Sensor tras
  pinMode(Trigger2,OUTPUT);
  pinMode(Echo2,INPUT);
  digitalWrite(Trigger2,LOW);
  pinMode(Echo2,INPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
}

//sensor del
int detecta_sensor() {
 long t;
 long d;
  
 digitalWrite(Trigger,LOW);
 delayMicroseconds(5);
 digitalWrite(Trigger,HIGH);
 delayMicroseconds(15);
 digitalWrite(Trigger,LOW);
 t=pulseIn(Echo,HIGH);
 d=t*0.01657;
 return (d);
  
}

//Sensor tras
int detecta_sensor2() {
 long t2;
 long d2;
  
 digitalWrite(Trigger2,LOW);
 delayMicroseconds(5);
 digitalWrite(Trigger2,HIGH);
 delayMicroseconds(15);
 digitalWrite(Trigger2,LOW);
 t2=pulseIn(Echo2,HIGH);
 d2=t2*0.01657;
 return (d2);
}




  
void adelante (int vel){

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW); 
  analogWrite(ENA, vel); 

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW); 
  analogWrite(ENB, vel); 
}

void atras (int vel){

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH); 
  analogWrite(ENA, vel);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH); 
  analogWrite(ENB, vel); 
}

void derecha (int vel){

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW); 
  analogWrite(ENA, vel); 

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH); 
  analogWrite(ENB, vel); 
}

void izquierda (int vel){

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH); 
  analogWrite(ENA, vel); 
 
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW); 
  analogWrite(ENB, vel); 
}

void loop(){

 //Sensor 1
 distance=detecta_sensor();
 Serial.print("Distancia sensor 1: ");
 Serial.print(distance);
 Serial.println ("cm");
 //Sensor 2
 distance2=detecta_sensor2();
 Serial.print("Distancia sensor 2: ");
 Serial.print(distance2);
 Serial.println ("cm");


 if(distance > 50) {
   adelante(120);
 }

 else if(distance2 <= 50){
  adelante(0);
  atras(0);
  derecha(0);
  izquierda(0);
 }
  
 else if(distance <= 50) {
  adelante(0);
  atras(120);
  delay(1000);
  atras(0);
  delay(500);
  derecha(60);
  delay(2000);
  derecha(0);
  delay(500);
 }

 }
  
