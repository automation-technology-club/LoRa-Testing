#include <SPI.h>
#include <LoRa.h>
#include <SD.h>
#include <Wire.h>
#include "RTClib.h"

#define ECHO_TO_SERIAL   1 // echo data to serial port

RTC_DS1307 RTC; // define the Real Time Clock object
const int chipSelect = 7;
File logfile;

char temp;
int rssi;

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
  pinMode(10, OUTPUT);
 //SD.begin(chipSelect);
   if (!SD.begin(chipSelect)) {
    error("Card failed, or not present");
  }
  
  Serial.println("card initialized.");
  
  // create a new file
  char filename[] = "LOGGER00.CSV";
  for (uint8_t i = 0; i < 100; i++) {
    filename[6] = i/10 + '0';
    filename[7] = i%10 + '0';
    if (! SD.exists(filename)) {
      // only open a new file if it doesn't exist
      logfile = SD.open(filename, FILE_WRITE); 
      break;  // leave the loop!
    }
  }
  if (! logfile) {
    error("couldnt create file");
  }
  
  Serial.print("Logging to: ");
  Serial.println(filename);

  // connect to RTC
  Wire.begin();  
  if (!RTC.begin()) {
    logfile.println("RTC failed");
#if ECHO_TO_SERIAL
    Serial.println("RTC failed");
#endif  //ECHO_TO_SERIAL
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
  // log time
  //logfile.print(now.unixtime()); // seconds since 1/1/1970
 // logfile.print(", ");
  logfile.print('"');
  logfile.print(now.year(), DEC);
  logfile.print("/");
  logfile.print(now.month(), DEC);
  logfile.print("/");
  logfile.print(now.day(), DEC);
  logfile.print(" ");
  logfile.print(now.hour(), DEC);
  logfile.print(":");
  logfile.print(now.minute(), DEC);
  logfile.print(":");
  logfile.print(now.second(), DEC);
  logfile.print('"');
  #if ECHO_TO_SERIAL
  //Serial.print(now.unixtime()); // seconds since 1/1/1970
  //Serial.print(", ");
  Serial.print('"');
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
  Serial.print('"');
#endif //ECHO_TO_SERIAL

    // received a packet
    Serial.print(" Received packet '");
    logfile.print(" Received packet '");
    // read packet
    
    while (LoRa.available()) {
      temp = (char)LoRa.read();
      Serial.print(temp);
      logfile.print(temp);
      //Serial.print((char)LoRa.read());
      //logfile.print((char)LoRa.read());
    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    logfile.print("' with RSSI ");
    rssi = LoRa.packetRssi();
    Serial.println(LoRa.packetRssi());
    logfile.println(LoRa.packetRssi());
  }
}
