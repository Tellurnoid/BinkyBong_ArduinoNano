/*
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
*/

#define sw1 7
#define sw2 8

#define RPin 11
#define GPin 10
#define BPin 9

void setup() {
    pinMode(sw1, INPUT_PULLUP);
    pinMode(sw2, INPUT_PULLUP);
    Serial.begin(9600);
    White();
}

int data=0;
int cursor=0;
int cursorBorder=6;

void loop() {

for(;;){
    if(digitalRead(sw1)==LOW){
        cursor++;
        if(cursor>cursorBorder){cursor=0;}
        while(digitalRead(sw1)==LOW);
        }
        //if(cursor==0){Off();}
        if(cursor==0){White();}
        if(cursor==1){Hanni();}
        if(cursor==2){Haerin();}
        if(cursor==3){Minji();}
        if(cursor==4){Danielle();}
        if(cursor==5){Hyein();}
  delay(100);
  }

}


void debug(){
    if (Serial.available() > 0) {
    data = Serial.read();
       if(data=='0'){Off();}
        else if(data=='1'){Minji();}
        else if(data=='2'){Hanni();}
        else if(data=='3'){Danielle();}
        else if(data=='4'){Haerin();}
        else if(data=='5'){Hyein();}
        else if(data=='6'){White();}
        else if(data=='A'){SlowAll();}
        else if(data=='W'){SlowWhite();}
    }  
}

void RGBWrite(int rVal, int gVal, int bVal){
  analogWrite(RPin, 255-rVal);
  analogWrite(GPin, 255-gVal);
  analogWrite(BPin, 255-bVal);
}

//RGB
void White(){RGBWrite(255, 200, 150);  Serial.println("White");}
void Off(){RGBWrite(0, 0, 0);  Serial.println("OFF");}

void Hanni()     { RGBWrite(250,30, 30);    Serial.println("Hanni");}
void Haerin()    { RGBWrite(0, 250, 20);  Serial.println("Haerin");}
void Minji()     {RGBWrite(0, 0, 250);    Serial.println("Minji");}
void Danielle()  {RGBWrite(250, 240, 0);  Serial.println("Danielle");}
void Hyein()     {RGBWrite(250, 0, 180); Serial.println("Hyein");}

int SlowDel=6;
void  SlowAll(){//RGB
  for(int i=0; i<250; i++){RGBWrite(0, 0, i); delay(SlowDel); }//Minji
  for(int i=0; i<250; i++){RGBWrite(0, i, 120/250*i); delay(SlowDel); }//Hanni
  for(int i=0; i<250; i++){RGBWrite(i-20, i, 0);  delay(SlowDel);}//Danielle
  for(int i=0; i<250; i++){RGBWrite(0, i, 0); delay(SlowDel); }//Haerin
  for(int i=0; i<250; i++){RGBWrite(100/250*i, 0, i);  delay(SlowDel);}//Hyein
}
void SlowWhite(){
    for(int i=0; i<250; i++){RGBWrite(i, i, i);  delay(SlowDel);}
}