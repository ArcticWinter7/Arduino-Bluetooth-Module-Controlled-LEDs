
#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h> 
SoftwareSerial MyBlue(2, 3); // RX | TX 
int flag = 0; 
int LED = 8; 


int pixelPin = 5;
int numpixels = 40;
Adafruit_NeoPixel pixels(numpixels, pixelPin, NEO_GRB + NEO_KHZ800);


void setup() 
{   
 Serial.begin(9600); 
 MyBlue.begin(9600); 
 pixels.begin();
 pinMode(LED, OUTPUT); 
 pinMode(pixelPin, OUTPUT);
 Serial.println("Ready to connect\nDefualt password is 1234 or 000"); 


 //digitalWrite(LED, HIGH); 
} 

//note that this uses ASCII for the characters, so 1 is 49 and 0 is 48
/each of theese does a different LED pattern
String numberZero = "48";
String numberOne = "49";
String numberTwo = "50";
String cmd = "0";
String prevCmd = "";




void loop() 
{ 
  if (MyBlue.available() > 0)
  {
    cmd = MyBlue.read();
    Serial.println(cmd);
    commands(cmd);
  }
  
}  

void commands(String cmd)
{
  if (cmd == "48")
  {
    
  }
  
  if (cmd == "49") 
  {
    digitalWrite(LED, HIGH); 
    Serial.println("LED On"); 
    delay(1000);
    digitalWrite(LED, LOW); 
    Serial.println("LED Off"); 
    delay(1000);
  }  

  if (cmd == "50")
  {
    Serial.println("LED spiral start");
    for(int i=0; i<numpixels; i++) 
    {
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    pixels.show();
    delay(100);
    pixels.clear();
    }
    Serial.println("LED spiral end");
  }
}
  
