#include <SoftwareSerial.h>
//I have this set to only run once, but you can pop it in the loop and have sensors or whatever trigger the code.
//I am just going to use a mosfet to turn the sim7000 off then on as needed after waking the arduino for a restart from begining.
//You may want to play with the delay function timing if your sim7000 takes a bit longer to connect.
 
//SIM7000 TX is connected to Arduino D8
#define SIM7000_TX_PIN 8
 
//SIM7000 RX is connected to Arduino D7
#define SIM7000_RX_PIN 7
 
SoftwareSerial serialSIM7000(SIM7000_TX_PIN,SIM7000_RX_PIN);
 
void setup() {

   
  //Being serial communication with Arduino and SIM7000
  serialSIM7000.begin(115200);
  delay(1000);

 //Must use the \r\n to simulate the return carriage and a new line in all commands
  serialSIM7000.write("AT+CMEE=1\r\n");
 delay(500);
 
 
  serialSIM7000.write("AT+CGACT?\r\n");
 delay(500);

  
  serialSIM7000.write("AT+CIPSHUT\r\n");
 delay(500);

   
  serialSIM7000.write("AT+CGATT=1\r\n");
 delay(500);

   
  serialSIM7000.write("AT+CSTT=\"hologram\"\r\n");
 delay(2000);

   
  serialSIM7000.write("AT+CIICR\r\n");
 delay(2000);

   
  serialSIM7000.write("AT+CIFSR\r\n");
 delay(2000);

    
  serialSIM7000.write("AT+CIPSTART=\"TCP\",\"cloudsocket.hologram.io\",\"9999\"\r\n");
 delay(3000);

    
  serialSIM7000.write("AT+CIPSEND\r\n");
  //I have also found that AT+CIPSEND=[DATA_LENGTH_IN_BYTES] is NOT needed. So just AT+CIPSEND is okay. 
 delay(2000);

    //Replace the "xxxxxxxxx" with your Hologram Decice key found in the Hologram dashboard. It is in the "Webhooks" section for the device.
    //Do not alter the forward slashes at all. They must be kept in place so the "s print in as needed.
    //Replace "Message" and "Topic" to suit your needs for the Hologram Data Cloud and/or Route triggers.
  serialSIM7000.write("{\"k\":\"xxxxxxxxx\",\"d\":\"Message\", \"t\":\"Topic\"}\r\n");
  
  //must use the below "cntrl z" method as written below to finalize. 
 serialSIM7000.write((char)26);
  delay(1000);

}
 
void loop() {

}
