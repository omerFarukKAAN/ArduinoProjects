int echoPin = 9;
int trigPin = 8;
int led[] = {2,3,4,5};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  int sure, mesafe, yakinlik;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  sure = pulseIn(echoPin, HIGH);
  mesafe = (sure/2)/29.1;
  Serial.print("Mesafe : ");
  Serial.println(mesafe);
  yakinlik = map(mesafe,0,100,1,4);
  Serial.print("Yakinlik : ");
  Serial.println(yakinlik);
  for(int i = 0; i<4; i++){
    digitalWrite(led[i], LOW);
  }
  for(int i = 0; i<yakinlik; i++){
    digitalWrite(led[i], HIGH);  
  }
}
