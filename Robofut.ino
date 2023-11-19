//#include <analogWrite.h>
/*
 * Placa de balam 2032
 */
#include <PS4Controller.h>

//Motor Movimiento M3/M4
#define AIN1 18
#define AIN2 4

#define BIN1 27
#define BIN2 14

//Disparadores M1/M2
#define CIN1 32
#define CIN2 33

#define CIN3 25
#define CIN4 26

int rX;
int rY;
int lX;
int lY;


//gatillos joj
int l2;
int r2;

int cuadro;
int circulo;
int Square;
int triangulo;
unsigned long lastTimeStamp = 0;


void notify(){
char messageString[200];
 sprintf(messageString, "%4d,%4d,%4d,%4d, %4d, %4d,",
lX = PS4.LStickX(),
lY= PS4.LStickY(),
rX = PS4.RStickX(),
rY = PS4.RStickY(),
cuadro = PS4.Cross(),
circulo = PS4.Circle(),
Square = PS4.Square(),
triangulo = PS4.Triangle(),
l2 = PS4.L2(),
r2 = PS4.R2());

    if (millis() - lastTimeStamp > 50){
    Serial.println(messageString);
    lastTimeStamp = millis();
    }
    
//motor 1
if(lY>=125)
    {
 digitalWrite  (AIN1, HIGH); 
 analogWrite (AIN2, 0);

         }
if (lY<=20)
{
  digitalWrite(AIN1,HIGH); 
  analogWrite(AIN2,255 );



}
if (lY<-125)
{
  digitalWrite(AIN1,LOW); 
  analogWrite(AIN2,255);

}
//motor 2
if(rY>=125)
    {
 digitalWrite  (BIN1, HIGH);
 analogWrite (BIN2, 0);

         }
if (rY<=20)
{
  digitalWrite(BIN1,HIGH); 
  analogWrite(BIN2,255);
}
if (rY<-125)
{
  digitalWrite(BIN1,LOW); 
  analogWrite(BIN2,255);
}

if (l2 == 1){
 digitalWrite  (CIN1, LOW);
 analogWrite (CIN2, 255);
 digitalWrite (CIN3, LOW);
 analogWrite (CIN4, 255);
}
if (r2 ==1){
  digitalWrite(CIN1, HIGH ); 
  analogWrite(CIN2,0 );
  digitalWrite (CIN3, HIGH );
  analogWrite (CIN4, 0);
}

if (cuadro ==1){
  digitalWrite(CIN1, HIGH ); 
  analogWrite(CIN2,255 );
  digitalWrite (CIN3, HIGH );
  analogWrite (CIN4, 255);
}

}


void onConnect()
{
  Serial.println("Connected!.");
}

void onDisConnect()
{
  Serial.println("Disconnected!.");
}

void setup() 
{
  Serial.begin(115200);
  PS4.attach(notify);
  PS4.attachOnConnect(onConnect);
  PS4.attachOnDisconnect(onDisConnect);
  PS4.begin();
  Serial.println("Ready.");
  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
  pinMode(BIN1,OUTPUT);
  pinMode(BIN2,OUTPUT);

  pinMode(CIN1,OUTPUT);
  pinMode(CIN2,OUTPUT);
  pinMode(CIN3,OUTPUT);
  pinMode(CIN4,OUTPUT);

}

void loop()
{
}}
