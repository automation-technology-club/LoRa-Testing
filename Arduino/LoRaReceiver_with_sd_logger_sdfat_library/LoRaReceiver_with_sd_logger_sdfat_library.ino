#include <SPI.h>
#include <LoRa.h>
#include <SdFat.h>
#include <Wire.h>
#include "RTClib.h"

#define ECHO_TO_SERIAL   1 // echo data to serial port
#define FILE_BASE_NAME "Data"

RTC_DS1307 RTC; // define the Real Time Clock object
const int chipSelect = 5;

SdFat sd;

// Log file.
SdFile file;

#define error(msg) sd.errorHalt(F(msg))
void setup() {
const uint8_t BASE_NAME_SIZE = sizeof(FILE_BASE_NAME) - 1;
  char fileName[13] = FILE_BASE_NAME "00.csv";
  
  Serial.begin(9600);
  while (!Serial);
  
 if (!sd.begin(chipSelect, SD_SCK_MHZ(50))) {
    sd.initErrorHalt();
  }
  // Find an unused file name.
  if (BASE_NAME_SIZE > 6) {
    error("FILE_BASE_NAME too long");
  }
  while (sd.exists(fileName)) {
    if (fileName[BASE_NAME_SIZE + 1] != '9') {
      fileName[BASE_NAME_SIZE + 1]++;
    } else if (fileName[BASE_NAME_SIZE] != '9') {
      fileName[BASE_NAME_SIZE + 1] = '0';
      fileName[BASE_NAME_SIZE]++;
    } else {
      error("Can't create file name");
    }
  }
  if (!file.open(fileName, O_CREAT | O_WRITE | O_EXCL)) {
    error("file.open");
  }
  // connect to RTC
  Wire.begin();  
  if (!RTC.begin()) {
    file.println("RTC failed");
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
  file.print('"');
  file.print(now.year(), DEC);
  file.print("/");
  file.print(now.month(), DEC);
  file.print("/");
  file.print(now.day(), DEC);
  file.print(" ");
  file.print(now.hour(), DEC);
  file.print(":");
  file.print(now.minute(), DEC);
  file.print(":");
  file.print(now.second(), DEC);
  file.print('"');
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
    file.print(" Received packet '");
    // read packet
    
    while (LoRa.available()) {
      //temp = LoRa.read();
      Serial.print((char)LoRa.read());
      file.print((char)LoRa.read());
    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    file.print("' with RSSI ");
    
    Serial.println(LoRa.packetRssi());
    file.println(LoRa.packetRssi());
  }
}
