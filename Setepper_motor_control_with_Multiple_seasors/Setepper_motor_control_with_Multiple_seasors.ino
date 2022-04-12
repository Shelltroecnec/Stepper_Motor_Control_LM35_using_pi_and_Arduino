/*Stepper Motor Controlling with Mutiple Sensor and IOT */

// Define stepper motor connections and steps per revolution:
#define dirPin 2
#define stepPin 3
#define stepsPerRevolution 200
#define MS1 8
#define MS2 9
#define MS3 10
#define red A1
#define green A2
#define blue A3
void LM35();
void IR();
void color ();

//Declaring Variables and Constant
float lm_read;
int temp;
const int IR_sensor=5;
int RED_freq = 0;
int GREEN_freq = 0;
int BLUE_freq = 0;

void setup() {
  // Declare pins as output:
  Serial.begin(9600);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(MS1,OUTPUT);
  pinMode(MS2,OUTPUT);
  pinMode(MS3,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(red,INPUT);
  pinMode(green,INPUT);
  pinMode(blue,INPUT);
  pinMode(IR,OUTPUT);
  digitalWrite(MS1,LOW);
  digitalWrite(MS2,LOW);
  digitalWrite(MS3,LOW);
}
void loop() {
  // Set the spinning direction clockwise:
  temp = analogRead(A0);
 float milivolt = ((temp * 4.88)/1024);
lm_read = (milivolt / 10);
Serial.println(lm_read);
delay(1000);
if( lm_read > 0.28)
{
  LM35();
  }
if(digitalRead(IR_sensor) == HIGH)
{
  IR();
 }
 if(blue != 0)
 {
  color();
 }
  
  // Set the spinning direction counterclockwise:
  digitalWrite(dirPin, LOW);

  // Spin the stepper motor 1 revolution quickly:
  for (int i = 0; i < stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }
  delay(1000);
}
void IR ()
{
  digitalWrite(dirPin,HIGH);
  digitalWrite(MS1,HIGH);
  for(int x = 0; x < stepsPerRevolution; x++){
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(1000);
}}
void LM35()
{
  digitalWrite(dirPin,HIGH);
  digitalWrite(MS2,HIGH);
  for(int x = 0; x < stepsPerRevolution; x++){
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(1000);
}}
void color ()
{
  BLUE_freq = analogRead(blue);
  Serial.print(BLUE_freq);
  delay(1000);
  if(BLUE_freq > 900)
  {
   digitalWrite(dirPin,HIGH);
  digitalWrite(MS2,HIGH);
  digitalWrite(11,HIGH);
  delay(300);
  digitalWrite(11,LOW);
  for(int x = 0; x < stepsPerRevolution; x++){
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(1000);
}}}
