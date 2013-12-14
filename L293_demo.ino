/*
 *  L293_demo - show how the L293D can drive motors.
 *
 *  20131208  MJB  written.  (Michael J Bakula)
 */

// control pins for 'A' side of the L293D
#define OUT1A  9
#define OUT2A 10
#define led   13

int source = OUT1A; 
int sink = OUT2A;
int veloc = 10;
int moment = 1000;
boolean toggle = 0; 
 
void setup() {
  pinMode(OUT1A, OUTPUT);
  pinMode(OUT2A, OUTPUT);
  pinMode(led,OUTPUT);
  analogWrite(led, HIGH);
} // setup()

void loop() {
  for (int veloc=0; veloc < 255; veloc+=5) {
    analogWrite(source, veloc);
    delay(30);
  }
  delay(moment);  
  for (int veloc=255; veloc > 0; veloc-=5) {
    analogWrite(source, veloc);
    delay(30);
  }
  delay(moment);
  toggle = ~toggle;
  digitalWrite(led, toggle);
  source = toggle ? OUT2A : OUT1A;  // ternary operator conditional
  sink   = toggle ? OUT1A : OUT2A;  //  -- if/else to swap sink & source
  digitalWrite(sink, LOW);          // just in case
} // loop()
//end L293_demo
