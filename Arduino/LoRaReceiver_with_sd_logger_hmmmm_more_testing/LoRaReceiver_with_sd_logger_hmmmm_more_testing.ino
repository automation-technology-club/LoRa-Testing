#include <SPI.h>
#include <LoRa.h>
#include <SD.h>
#include <Wire.h>
#include "RTClib.h"

#define ECHO_TO_SERIAL   1 // echo data to serial port

RTC_DS1307 RTC; // define the Real Time Clock object
const int chipSelect = 7;


char temp;
int rssi;
 char filename = "LOGGER00.CSV";
  
void error(char *str)
{
  Serial.print("error: ");
  Serial.println(str);
 while(1);
}


void setup() {
  Serial.begin(9600);
  while (!Serial);
Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(7, OUTPUT);
  //pinMode(10, OUTPUT);
 if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while(1);
  }
  else {
    Serial.println("card initialized.");
   // File dataFile = SD.open("datalog.txt", FILE_WRITE);
    //if (dataFile) {
     // dataFile.println("Start");
     // dataFile.println("");
     // dataFile.close();
      
    //}
  }
  // connect to RTC
  Wire.begin();  
  if (!RTC.begin()) {
   
    Serial.println("RTC failed");

  }
  
  Serial.println("LoRa Receiver");

  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
 DateTime now;
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
 
    now = RTC.now();
    
  Serial.print(now.year(), DEC);
  Serial.print("/");
  Serial.print(now.month(), DEC);
  Serial.print("/");
  Serial.print(now.day(), DEC);
  Serial.print(" ");
  Serial.print(now.hour(), DEC);
  Serial.print(":");
  Serial.print(now.minute(), DEC);
  Serial.print(":");
  Serial.print(now.second(), DEC);
 
    // received a packet
    Serial.print(" Received packet '");
   
    // read packet
    
    while (LoRa.available()) {
      temp += (char)LoRa.read();
          }
          Serial.print(temp);

    // print RSSI of packet
    Serial.print("' with RSSI ");
    
    rssi = LoRa.packetRssi();
    Serial.println(rssi);
    //Serial.println(LoRa.packetRssi());
   writeFile();
  }
  temp = "";
}

void writeFile() {
DateTime now;
  now = RTC.now();
  
File dataFile = SD.open("datalog.txt", FILE_WRITE);
if (dataFile)  {
  dataFile.print(now.year(), DEC);
  dataFile.print("/");
  dataFile.print(now.month(), DEC);
  dataFile.print("/");
  dataFile.print(now.day(), DEC);
  dataFile.print(" ");
  dataFile.print(now.hour(), DEC);
  dataFile.print(":");
  dataFile.print(now.minute(), DEC);
  dataFile.print(":");
  dataFile.print(now.second(), DEC);
 dataFile.print(" Received packet '");
dataFile.print(temp);
dataFile.print("' with RSSI ");
 dataFile.println(rssi);
    dataFile.close();
} else {
    Serial.println("error opening datalog.txt");
  }
  }
