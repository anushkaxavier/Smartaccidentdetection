   #include <Wire.h>
#include <Adafruit_SSD1306.h>//graphics
#include <Adafruit_GFX.h>//graphics
#define SSD1306_LCDHEIGHT 64//communication//height of oled

// OLED display TWI address
#define OLED_ADDR   0x3C//oled address

Adafruit_SSD1306 display(-1);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

   //ULTRASONIC SENSOR DISTANCE MEASUREMENT//
   #include <Servo.h>//library servo.h

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

  #define trigPin D0
   #define echoPin D3
void setup() {
  myservo.attach(2); 
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.print("Ultrasonic sensor starting");
  Serial.println("");
  delay(1000);
  //pinMode(D0,OUTPUT);
  //pinMode(D1,OUTPUT);
 }

void loop() {
   int pos;
  // put your main code here, to run repeatedly:
int duration,distance;
digitalWrite(trigPin,HIGH);//generate the sound wave
delay(1000);//to produce delay
digitalWrite(trigPin,LOW);//enabling echopin high
duration=pulseIn(echoPin,HIGH);//read the pulse of sound
distance=(duration/2)* 0.0343;//time*speed of the sound(^0.0343 cm/microsec) /2 becoz to nd fro movement
Serial.print("Distance is");
Serial.println(distance);
delay(2000);
if(distance>5)//close
{
  //digitalWrite(D0,HIGH);
  //digitalWrite(D1,LOW);
  
   for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
   // delay(25);                       // waits 15ms for the servo to reach the position
  }
   display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
   display.clearDisplay();//to clear dispaly
  

  
// display a line of text
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(3,5);//position x-y coordinates
  display.print("closed");//print in led display
 
 
  // update display with all of the above graphics
  display.display();
  delay(2000);

}
else
{
//digitalWrite(D1,HIGH);
//digitalWrite(D0,LOW);

 for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
   // delay(25);  
 }
   // waits 15ms for the servo to reach the position
    display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
    display.clearDisplay();//to clear dispaly
  

  
// display a line of text
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(3,5);//position x-y coordinates
  display.print("open");//print in led display
 
 
  // update display with all of the above graphics
  display.display();
  delay(2000);

}
}
