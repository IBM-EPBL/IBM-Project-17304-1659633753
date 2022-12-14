// C++ code
int trig=2;
int echo=3;

void setup()
{
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(12,OUTPUT);
}

void loop()
{
  //ultrasonic sensor
  digitalWrite(trig,LOW);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  float dur=pulseIn(echo,HIGH);
  float dis=(dur*0.0343)/2;
  Serial.print("Distance is: ");
  Serial.println(dis);

  //LED ON
  if(dis>=100)
  {
    digitalWrite(8,HIGH);
    digitalWrite(7,HIGH);
  }

  //Buzzer For ultrasonic Sensor
  if(dis>=100)
  {
  	tone(12,100);//tone(pin, frequency)
  	delay(1000);
  	noTone(12);
  	delay(1000);
  }
 
  //LED OFF
  if(dis<100)
  {
    digitalWrite(8,LOW);
    digitalWrite(7,LOW);
  }

  //Temperate Sensor
  double a= analogRead(A0);
  double t=(((a/1024)*5)-0.5)*100;
  Serial.print("Temp Value: ");
  Serial.println(t);
  delay(1000);


  //LED ON
  if(t>=100)
  {
    digitalWrite(8,HIGH);
    digitalWrite(7,HIGH);
  }

  //Buzzer for Temperature Sensor
  if(t>=100)
  {
  	tone(11,100);
  	delay(1000);
  	noTone(11);
  	delay(1000);
  }

  //LED OFF
  if(t<100)
  {
    digitalWrite(8,LOW);
    digitalWrite(7,LOW);
  }
}