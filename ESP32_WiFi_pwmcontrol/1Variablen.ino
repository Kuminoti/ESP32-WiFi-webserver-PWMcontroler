#include <WiFi.h>
#include <WiFiClient.h>

#define freq 1000                                       //pwm frequency 1kHz            
#define resolution 8                                    //pwm resolution 0-255

#define timeoutTime 2000                                //Enter your SSID and WI-FI password
#define ssid ""
#define password ""                      

WiFiServer server(80);                                  //Server on port 80

//In-and outputs inside Arrays                                     
int output[] = {26, 27, 25};                            //Digital Outputs
int pwmpin[] = {0, 2, 4};                               //Analog Outputs
int ledChannel[] = {1, 2, 3};                           //LED-Channels
int pos[] = {1, 2, 3, 4, 5, 6};                         //Slider posiition

String output25State = "off";                             
String output26State = "off";
String output27State = "off";

String valueString  = String(5);
String valueString2 = String(6);
String valueString3 = String(7);
String valueString4 = String(8); 
String valueString5 = String(9);
String valueString6 = String(10);
String valueString7 = String(11);
String valueString8 = String(12);
String valueString9 = String(13);

String header;                                            //your HTTP header

unsigned long currentTime = millis();
unsigned long previousTime = 0;
