  // aangeven pin nummers op Arduino board
  // verkeerslicht 1
  int rood1 = 8;
  int groen1 = 9;
  int blau1 = 10;
  
  // verkeerslicht 2
  int rood2 = 3;
  int groen2 = 2;
  int blau2 = 1;

void setup() {
  //aangeven wat elke poort is.
  pinMode(rood1,OUTPUT);
  pinMode(blau1,OUTPUT);
  pinMode(groen1,OUTPUT);
  pinMode(rood2,OUTPUT);
  pinMode(groen2,OUTPUT);
  pinMode(blau2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // A - ROOD
  // B - groen
  // DELAY (4)
  digitalWrite(rood1,HIGH);
  digitalWrite(rood2,LOW);
  digitalWrite(blau1,LOW);
  digitalWrite(blau2,HIGH);
  digitalWrite(groen1,LOW);
  digitalWrite(groen2,HIGH);
  delay(3000);
  // GROEN 
  // DELAY (4)
  digitalWrite(rood1,LOW);
  digitalWrite(rood2,HIGH);
  digitalWrite(blau1,HIGH);
  digitalWrite(blau2,LOW);
  digitalWrite(groen1,HIGH);
  digitalWrite(groen2,LOW);
  delay(3000);
  // GEEL (WIT)
  // DELAY (1)
  digitalWrite(groen1,HIGH);
  digitalWrite(groen2,LOW);
  digitalWrite(blau1,HIGH);
  digitalWrite(blau2,LOW);
  digitalWrite(rood1,HIGH);
  digitalWrite(rood2,LOW);
  delay(1000);
}
