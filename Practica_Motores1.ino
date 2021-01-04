int in2Pin = 9;       // Define pins used for L293D
int in1Pin = 10;
int enable1Pin = 11;

int dir = 0;  // Define variables for motor direction and speed
int spd = 0;

void setup()
{
  pinMode(in2Pin, OUTPUT);  //Define pin modes
  pinMode(in1Pin, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
}

void loop() {
  int potInput = analogRead(A0);  // Read potentiometer value
  spd = map(abs(potInput), 0, 1023, 0, 255); // Calculate motor speed, pot travel from midpoint
  driveMotor(); 
}

void driveMotor() 
{
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, HIGH);
  analogWrite(enable1Pin, spd);
}
