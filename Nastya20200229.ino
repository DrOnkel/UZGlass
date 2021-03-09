int pinTrig = 3;
int pinLed = 13;
long time0;
float distens;
float OldDistance;
unsigned long t0, t1, t2;
byte NofSound;

void setup() {
  pinMode(pinLed, OUTPUT);
  pinMode(pinTrig, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);




  attachInterrupt(digitalPinToInterrupt(2), Countt, FALLING);


  Serial.begin(9600);

  Serial.println(" is program from Nastya 17.12.1901   GiassNastya20200229  " );
  NofSound = 24;
  if (0)
  {
    Serial.write( 0x7E);
    Serial.write( 0xFF);
    Serial.write( 0x06);
    Serial.write( 0x03);
    Serial.write( 0x00);
    Serial.write( 0x00);
    Serial.write( NofSound);
    Serial.write( 0xFE );
    Serial.write( 0xF8 - NofSound);
    Serial.write( 0xEF);

  }

  Serial.end();
  delay(500);
}

// the loop function runs over and over again forever
void loop() {


  if ( distens < 50 ) {

    digitalWrite(5, HIGH);
    digitalWrite(6, LOW );

  }


  if ( distens < 30 ) {

    digitalWrite(5, LOW );
    digitalWrite(6, HIGH );
  }


  if ( distens > 50 ) {

    digitalWrite(5, LOW );
    digitalWrite(6, LOW );

  }

if(distens>200)
distens =200;

  if(  distens < 0.8 * OldDistance    ||   distens >  1.2 * OldDistance ) 

  {

    OldDistance = distens;

    Serial.begin(9600);
    Serial.println("");
    Serial.print(distens);
    Serial.println("");


if(distens<200 )
{
    NofSound = distens;

    Serial.write( 0x7E);
    Serial.write( 0xFF);
    Serial.write( 0x06);
    Serial.write( 0x03);
    Serial.write( 0x00);
    Serial.write( 0x00);
    Serial.write( NofSound);
    Serial.write( 0xFE );
    Serial.write( 0xF8 - NofSound);
    Serial.write( 0xEF);
}






    Serial.end();
  }
  delay(300);

  digitalWrite(pinTrig, HIGH);  //включаем Триг

  delay(10);                    //ждем
  digitalWrite(pinTrig, LOW);   //выключаем Триг
  t0 = micros();
  delay(200);


}



void Countt(void)
{


  time0 = micros() - t0;

  distens = 0.0181 * time0 - 38.4066;

  //  Serial.println(distens);

}
