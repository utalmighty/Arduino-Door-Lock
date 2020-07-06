//1* Arduino Uno Board, 1*Servo Motor, 1*Green Led, 5*Red LEDs, 5*200 ohms Resistors, Few Jumper Wires
#include <Servo.h>
#include <Keypad.h>
//Connect Servo Motor: Signal Pin:(~)3, Power Pin: 5V pin, Ground Pin: GRD pin
//Connect 4X4 Keypad: Pins 13 to (~)6 ORDER: "extreme left one from keypad goes to 13" and the extreme right goes to (~)6.
//Connect OPEN(Green)/CLOSE(RED) LEDs:Connect them with same GRD Pin with common Resistane(200 ohms)in -ve of both LEDs, directly connect +ve of RED LED on pin 4 and connect +ve of GREEN LED to pin 5
//Connect Signal 4 LED (For Animations): Connect Each LED with resistors (200 ohms)each on -ve of LEDS and ground them on common GRD pin using by soldering all four LEDs -ve pin (with resistors)on single wire;now connect +ve pins of LEDs to A0,A1,A2,A3 pin
Servo myservo;  // create servo object to control a servo
Servo backup;
const int pass=3364; //MAIN PASSWORD CHANGE WHEN NEEDED
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
//0 degree close door 180 degree open door
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {13, 12, 11, 10}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
int cnt=0;
int dublicate=pass;
void setup(){
  myservo.attach(3);
  backup.attach(2);
  //Serial.begin(9600);
   myservo.write(180);
   backup.write(0);
   digitalWrite(4,HIGH);
   digitalWrite(5,LOW);
  while(dublicate>0)
  {
    cnt=cnt+1;
    dublicate=dublicate/10;
  }
  }
int dub=pass;
int c=1;
String user="";
double divi=0.00;
int ascai=0;
int i=0;
String aspass="";
int rem=0;
int counter=0;
int count=0;
int s=0;
void loop(){
  while(dub>0)
  {
    rem=dub%10;
    ascai=rem+48;
    aspass=aspass+ascai;
    dub=dub/10;
  }
  dub=pass;
  g:
  //Serial.println("ENTER MAIN password");
  while(count<cnt){
  int customKey = customKeypad.getKey();
  if (customKey){
    //Serial.println(customKey);
    user=customKey+user;
    count++;
    if(count==1){
      digitalWrite(A3,HIGH);
    }
    if(count==2)
    {
      digitalWrite(A2,HIGH);
    }
    if(count==3)
    {
      digitalWrite(A1,HIGH);
    }
    if(count==4){
      digitalWrite(A0,HIGH);
    }
    }
  }
  count=0;
    while(c==1)
    {
   //Serial.println("OK STOP");
    if(user==aspass){
      //Serial.println("main password PASS");
      myservo.write(0);
      delay(1000);
      digitalWrite(4,LOW);
      digitalWrite(5,HIGH);
      delay(150);
      digitalWrite(A0,LOW);
      digitalWrite(A1,LOW);
      digitalWrite(A2,LOW);
      digitalWrite(A3,LOW);
        digitalWrite(A0,HIGH);
        delay(50);
        digitalWrite(A0,LOW);
        delay(50);
        digitalWrite(A0,HIGH);
        delay(50);
        digitalWrite(A0,LOW);
        delay(50);
         digitalWrite(A1,HIGH);
        delay(50);
        digitalWrite(A1,LOW);
        delay(50);
        digitalWrite(A1,HIGH);
        delay(50);
        digitalWrite(A1,LOW);
        delay(50);
         digitalWrite(A2,HIGH);
        delay(50);
        digitalWrite(A2,LOW);
        delay(50);
        digitalWrite(A2,HIGH);
        delay(50);
        digitalWrite(A2,LOW);
        delay(50);
         digitalWrite(A3,HIGH);
        delay(50);
        digitalWrite(A3,LOW);
        delay(50);
        digitalWrite(A3,HIGH);
        delay(50);
        digitalWrite(A3,LOW);
        delay(50);
      user="";
      c=2;
      //start............................................................................................
      int bro=0;
      String pop="";
      int gatepass=0;
      int gatepass2=0;
      int servomotor=0;
      String pop2="";
      int bro2=0;
      no:
      //Serial.println("Enter NEW PASSWORD");
       while(bro<4){
  gatepass = customKeypad.getKey();
  if (gatepass){
    //Serial.println(gatepass);
    pop=gatepass+pop;
    bro++;
    if(bro==1){
      digitalWrite(A3,HIGH);
    }
    if(bro==2)
    {
      digitalWrite(A2,HIGH);
    }
    if(bro==3)
    {
      digitalWrite(A1,HIGH);
    }
    if(bro==4){
      digitalWrite(A0,HIGH);
    }
    }
  }
  //Serial.println("ENTER AGAIN");
  while(bro2<4){
  gatepass2 = customKeypad.getKey();
  if (gatepass2){
    //Serial.println(gatepass2);
    pop2=gatepass2+pop2;
    bro2++;
    if(bro2==1){
      digitalWrite(A3,LOW);
    }
    if(bro2==2)
    {
      digitalWrite(A2,LOW);
    }
    if(bro2==3)
    {
      digitalWrite(A1,LOW);
    }
    if(bro2==4){
      digitalWrite(A0,LOW);
    }
    }
  }
  if(pop2==pop)
  {
    bro2=0;
    bro=0;
    //Serial.println("password safe Sucessfull");
     digitalWrite(A0,HIGH);
      digitalWrite(A1,HIGH);
      digitalWrite(A2,HIGH);
      digitalWrite(A3,HIGH);
      delay(100);
      digitalWrite(A0,LOW);
      digitalWrite(A1,LOW);
      digitalWrite(A2,LOW);
      digitalWrite(A3,LOW);
      delay(100);
      digitalWrite(A0,HIGH);
      digitalWrite(A1,HIGH);
      digitalWrite(A2,HIGH);
      digitalWrite(A3,HIGH);
      delay(100);
      digitalWrite(A0,LOW);
      digitalWrite(A1,LOW);
      digitalWrite(A2,LOW);
      digitalWrite(A3,LOW); /////////////////////////// 
      p:
      servomotor = customKeypad.getKey(); 
      if(servomotor==0)
      {
       goto p;
      }
        else{
          // goes from 180 degrees to 0 degrees
    myservo.write(180);
    delay(1000);// tell servo to go to position in variable 'LOCKED'
    digitalWrite(5,LOW);
    digitalWrite(4,HIGH);
    int ledeft=0;
    while(ledeft<=2){
        digitalWrite(A0,HIGH);
        delay(50);
        digitalWrite(A1,HIGH);
        delay(50);
        digitalWrite(A2,HIGH);
        delay(50);
        digitalWrite(A3,HIGH);
        delay(50);
        digitalWrite(A0,LOW);
        delay(50);
        digitalWrite(A1,LOW);
        delay(50);
        digitalWrite(A2,LOW);
        delay(50);
        digitalWrite(A3,LOW);
        delay(500); // waits 15ms for the servo to reach the position
        digitalWrite(A3,HIGH);
        delay(50);
        digitalWrite(A2,HIGH);
        delay(50);
        digitalWrite(A1,HIGH);
        delay(50);
        digitalWrite(A0,HIGH);
        delay(50);
        digitalWrite(A3,LOW);
        delay(50);
        digitalWrite(A2,LOW);
        delay(50);
        digitalWrite(A1,LOW);
        delay(50);
        digitalWrite(A0,LOW);
        delay(500);
        ledeft++;
        }
        }
  }
  else{
    bro2=0;
    bro=0;
    pop="";
    pop2="";
    gatepass=0;
    gatepass2=0;
    //Serial.println("enter same passwords, tryagain");
     delay(150);
      digitalWrite(A0,LOW);
      digitalWrite(A1,LOW); 
      digitalWrite(A2,LOW);
      digitalWrite(A3,LOW);
      digitalWrite(A2,HIGH);
      digitalWrite(A1,HIGH);
      delay(75);
      digitalWrite(A1,LOW);
      digitalWrite(A3,HIGH);
      delay(75);
      digitalWrite(A3,LOW);
      digitalWrite(A1,HIGH);
      delay(75);
      digitalWrite(A2,LOW);
      digitalWrite(A0,HIGH);
      delay(75);
      digitalWrite(A0,LOW);
      digitalWrite(A2,HIGH);//.
      delay(75);
      digitalWrite(A1,LOW);
      digitalWrite(A3,HIGH);
      delay(75);
      digitalWrite(A3,LOW);
      digitalWrite(A1,HIGH);
      delay(75);
      digitalWrite(A2,LOW);
      digitalWrite(A0,HIGH);
      delay(75);
      digitalWrite(A0,LOW);
      digitalWrite(A2,HIGH);//.
      delay(75);
      digitalWrite(A1,LOW);
      digitalWrite(A3,HIGH);
      delay(75);
      digitalWrite(A3,LOW);
      digitalWrite(A1,HIGH);
      delay(75);
      digitalWrite(A2,LOW);
      digitalWrite(A0,HIGH);
      delay(75);
      digitalWrite(A0,LOW);
      digitalWrite(A2,HIGH);//.
      delay(75);
      digitalWrite(A1,LOW);
      digitalWrite(A2,LOW);
    goto no;
    
  }
  int vv=0;
  double divvv=0.00;
  x:
  int f=0;
  int enter=0;
  String gp="";
  //Serial.println("ENTER password TO open DOOR");
  while(f<4)
  {
     enter = customKeypad.getKey();
  if (enter){
    //Serial.println(gatepass);
    gp=enter+gp;
    f++;
    if(f==1){
      digitalWrite(A3,HIGH);
    }
    if(f==2)
    {
      digitalWrite(A2,HIGH);
    }
    if(f==3)
    {
      digitalWrite(A1,HIGH);
    }
    if(f==4){
      digitalWrite(A0,HIGH);
    }
    }
  }
  if(gp==pop){
    //Serial.println("OPEN");
    int j=0;
     // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(0);              // tell servo to go to position in variable 'pos'
    delay(1000); 
    digitalWrite(4,LOW);                   // waits 15ms for the servo to reach the position
    digitalWrite(5,HIGH);
    while(j==0)
    {
    digitalWrite(A0,HIGH);
    digitalWrite(A1,LOW);
      digitalWrite(A2,LOW);
      digitalWrite(A3,HIGH);
      delay(500);
      digitalWrite(A0,LOW);
      digitalWrite(A1,HIGH);
      digitalWrite(A2,HIGH);
      digitalWrite(A3,LOW);
      delay(500);
     }
  }
     else{
      vv++;
      //Serial.println("still closed");
      delay(150);
      digitalWrite(A0,LOW);
      digitalWrite(A1,LOW);
      digitalWrite(A2,LOW);
      digitalWrite(A3,LOW);
      digitalWrite(A2,HIGH);
      digitalWrite(A1,HIGH);
      delay(75);
      digitalWrite(A1,LOW);
      digitalWrite(A3,HIGH);
      delay(75);
      digitalWrite(A3,LOW);
      digitalWrite(A1,HIGH);
      delay(75);
      digitalWrite(A2,LOW);
      digitalWrite(A0,HIGH);
      delay(75);
      digitalWrite(A0,LOW);
      digitalWrite(A2,HIGH);//.
      delay(75);
      digitalWrite(A1,LOW);
      digitalWrite(A3,HIGH);
      delay(75);
      digitalWrite(A3,LOW);
      digitalWrite(A1,HIGH);
      delay(75);
      digitalWrite(A2,LOW);
      digitalWrite(A0,HIGH);
      delay(75);
      digitalWrite(A0,LOW);
      digitalWrite(A2,HIGH);//.
      delay(75);
      digitalWrite(A1,LOW);
      digitalWrite(A3,HIGH);
      delay(75);
      digitalWrite(A3,LOW);
      digitalWrite(A1,HIGH);
      delay(75);
      digitalWrite(A2,LOW);
      digitalWrite(A0,HIGH);
      delay(75);
      digitalWrite(A0,LOW);
      digitalWrite(A2,HIGH);//.
      delay(75);
      digitalWrite(A1,LOW);
      digitalWrite(A2,LOW);
      divvv=vv%3;
      if(divvv==0)
      {
        //Serial.println("Syren Alarm 10 sec");//add code for syren Alarm and make it last for 10 sec plus light effect
        delay(10000);
        digitalWrite(A0,HIGH);
        delay(50);
        digitalWrite(A1,HIGH);
        delay(50);
        digitalWrite(A2,HIGH);
        delay(50);
        digitalWrite(A3,HIGH);
        delay(50);
        digitalWrite(A0,LOW);
        delay(50);
        digitalWrite(A1,LOW);
        delay(50);
        digitalWrite(A2,LOW);
        delay(50);
        digitalWrite(A3,LOW);
        delay(50);  
     }
     goto x;
     }
      //end..............................................................................................
    }
    else{
     //Serial.println(" original FAIL");
      user="";
      delay(150);
      digitalWrite(A0,LOW);
      digitalWrite(A1,LOW);
      digitalWrite(A2,LOW);
      digitalWrite(A3,LOW);
      digitalWrite(A2,HIGH);
      digitalWrite(A1,HIGH);
      delay(75);
      digitalWrite(A1,LOW);
      digitalWrite(A3,HIGH);
      delay(75);
      digitalWrite(A3,LOW);
      digitalWrite(A1,HIGH);
      delay(75);
      digitalWrite(A2,LOW);
      digitalWrite(A0,HIGH);
      delay(75);
      digitalWrite(A0,LOW);
      digitalWrite(A2,HIGH);//.
      delay(75);
      digitalWrite(A1,LOW);
      digitalWrite(A3,HIGH);
      delay(75);
      digitalWrite(A3,LOW);
      digitalWrite(A1,HIGH);
      delay(75);
      digitalWrite(A2,LOW);
      digitalWrite(A0,HIGH);
      delay(75);
      digitalWrite(A0,LOW);
      digitalWrite(A2,HIGH);//.
      delay(75);
      digitalWrite(A1,LOW);
      digitalWrite(A3,HIGH);
      delay(75);
      digitalWrite(A3,LOW);
      digitalWrite(A1,HIGH);
      delay(75);
      digitalWrite(A2,LOW);
      digitalWrite(A0,HIGH);
      delay(75);
      digitalWrite(A0,LOW);
      digitalWrite(A2,HIGH);//.
      delay(75);
      digitalWrite(A1,LOW);
      digitalWrite(A2,LOW);
      counter++;
      divi=counter%3;
      if(divi==0)
      {
        //Serial.println("Syren Alarm");//add code for syren Alarm and make it last for 10 sec plus light effect
        delay(10000);
        digitalWrite(A0,HIGH);
        delay(50);
        digitalWrite(A1,HIGH);
        delay(50);
        digitalWrite(A2,HIGH);
        delay(50);
        digitalWrite(A3,HIGH);
        delay(50);
        digitalWrite(A0,LOW);
        delay(50);
        digitalWrite(A1,LOW);
        delay(50);
        digitalWrite(A2,LOW);
        delay(50);
        digitalWrite(A3,LOW);
        delay(50);
      }
      goto g; 
    }
    }
}
