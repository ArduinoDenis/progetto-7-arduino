//Sensore di parcheggio

int triggerPort = 7;

int echoPort = 8;

int cicalino = 9;

unsigned long time;

unsigned long lampeggio_time;

unsigned long pausa_time;

void setup() {

pinMode( triggerPort, OUTPUT );

pinMode( echoPort, INPUT );

pinMode( cicalino, OUTPUT );

Serial.begin( 9600 );

Serial.println( "Sensore ultrasuoni: ");

}

void loop() {

//porta bassa l'uscita del trigger

digitalWrite( triggerPort, LOW );

//invia un impulso di 10microsec su trigger

digitalWrite( triggerPort, HIGH );

delayMicroseconds( 10 );

digitalWrite( triggerPort, LOW );

long duration = pulseIn( echoPort, HIGH );

long r = 0.034 * duration / 2;

Serial.print( "durata: " );

Serial.print( duration );

Serial.print( " , " );

Serial.print( "distanza: " );

if( duration > 38000 ) Serial.println( "fuori portata");

else { Serial.print( r ); Serial.println( "cm" );}

if( r > 3 && r <= 200){

delay(r*10);

digitalWrite(cicalino, HIGH);

delay(r*10); }

if( r <= 3){

digitalWrite(cicalino, HIGH);

delay(1000);}

digitalWrite(cicalino, LOW);

delay(10);

}
