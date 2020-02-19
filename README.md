
# hologram_sim7000_TCPIP
Send a messages to Hologram Cloud with auto AT commands with sim7000a/e/c breakout
(sold on amazon or aliexpress) and Arduino. Make sure you get the correct breakout for your
region
sim7000a - americas
sim7000e - euro
sim7000c - asia

 I have been able to power the breakout with just the 5v arduino pin.

There is a sim800 library for Hologram, however most of the at commands and proceedures
are different for the sim7000. For example...

No "AT+CIPSEND=[DATA_LENGTH_IN_BYTES]" is needed. I have been just using "AT+CIPSEND" with
100% success. 

Tested with Uno and Nano. Working without a hitch for both. More board tests will be
added as I get to it. It is just straight AT commands, so it should work with anything
Arduino compatible.

Only need the SoftwareSerial.h

Must have Hologram.io sim activated.

Does not print to serial monitor, as I wanted to keep it barebones so you can
amend it any way you wish to suit your needs.
ie... Add PSM, PDM, restarts, wakes, etc

You can check the sent data in the
Hologram.io dashboard in real time.

Free to use as you wish!
