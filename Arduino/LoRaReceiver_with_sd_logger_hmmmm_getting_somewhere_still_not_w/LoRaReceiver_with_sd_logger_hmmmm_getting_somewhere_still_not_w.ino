#include <SPI.h>
#include <LoRa.h>
#include <SD.h>

const int chipSelect = 7;

char temp;
int rssi;
String readString;
String dataString = "";
   
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
  
 if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while(1);
  }
  else {
    Serial.println("card initialized.");
    File dataFile = SD.open("datalog.txt", FILE_WRITE);
    if (dataFile) {
     dataFile.println("Start");
     //dataFile.println("");
     dataFile.close();
     }
  }
  
  
  Serial.println("LoRa Receiver");

  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
 
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
 
    
    // received a packet
    Serial.print(" Received packet '");
   
    // read packet
    
    while (LoRa.available()) {
      temp = (char)LoRa.read();
      readString += temp;
          }
          Serial.print(readString);

    // print RSSI of packet
    Serial.print("' with RSSI ");
    
    rssi = LoRa.packetRssi();
    Serial.println(rssi);
    //Serial.println(LoRa.packetRssi());

dataString = "Received packet ' ";
dataString += readString;
dataString += "' with RSSI ";
dataString += String(rssi);

  LoRa.end();  
    
   File dataFile = SD.open("datalog.txt", FILE_WRITE);
if (dataFile)  {
  
 dataFile.println(dataString);
 dataFile.close();
} else {
    Serial.println("error opening datalog.txt");
  }
  LoRa.begin(915E6);
  }
 
  dataString = "";
  readString = "";
  
}

 /*
  * I Think I know why the SD card isn't being written too
  * I think it has something to do with the LoRa Libary
  * I can write to the SD card before LoRa.begin(915E6) is used.
  * I'm not sure how to solve the problem. Stopping LoRa Library
  * doesn't seem to work.   
  */

