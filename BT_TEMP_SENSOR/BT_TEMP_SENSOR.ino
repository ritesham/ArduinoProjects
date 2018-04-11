
// modified by EJO on Jan. 17, 2016.
// 
// What this does: The Arduino Uno sends the information to the temperature and humidty sensor to your smartphone.
//
// Musts:    Hardware -- A smartphone, the Arduino Uno, the HC-05 ZS-040 BT module, and a DHT11 Temp and Humid Sensor. Also, optional breadboard and wiring (see "Optional", below).
//           Software -- Bluetooth capability on your smartphone. And download the "Bluetooth Terminal" app.
//
// Optional: I used a breadboard and some wires to make the wiring cleaner in appearance (connecting the Arduino and HC-05 BT and DHT11 modules).
//           Also, after wiring and uploading this code, you can disconnect the USB cable to the Arduino Uno and attach an external power supply.
//           It looks cool as a stand-alone device when working and not attached to the computer.
//
// Wiring:   1. Connect the Arduino's 5v of power to the HC-05's "VCC" pin and to the DHT11's "VCC" pin (looking at the "hole" side of the sensor, this is the far LEFT pin).
//           2. Connect the Arduino's GND to the HC-05's "GND" pin and to the DHT11's "GND" pin (looking at the "hole" side of the sensor, this is the far RIGHT pin).
//           3. Connect the Arduino's DigitalPin 0 (RX<-0) to the HC-05's "TX" (receive) pin.
//           4. Connect the Arduino's DigitalPin 1 (TX->1) to the HC-05's "RX" (transmit) pin.
//           5. Connect the Arduino's DigitalPin 7 to the DHT11's "output" pin (looking at the "hole" side of the sensor, this is the pin that is 2nd from the left).
//
// Note:    Once the (above) wiring has been done, power-up the Arduino. Then download the code.
//          Special Note: Sometimes when downloading the code to the Arduino, you can get errors. Just unplug the TX and RX pins, redownload. There is some kind of 
//                        communication error issue when the TX and RX are plugged-in during download. After a successful download, just plug the wires back into the Arduino.
//
//          At this point it's probably a good idea to make sure you can "pair" to the HC-05. So, after the code is downloaded there will be power supplied to the HC-05 BT module. 
//          Next, on your smartphone, enable Bluetooth,scan for available devices, and then pair/connect to the HC-05 (probably named "HC-05"). The default passcode/password is 
//          usually "1234" (without the quotes).
//
// How to use: Once the wiring is complete and this source-code has been uploaded to the Arduino Uno (and the Arduino is powered, a.k.a. "the code is running"), launch the 
//             "Bluetooth Terminal" app on your smartphone.
//             The app will want to enable your smartphone's Bluetooth. Through the app, you have to choose which bluetooth device you want to connect to. Here's how:
//             1. Go to the options and select "Connect a device-secure",
//             2. Choose the HC-05.
//             3. The HC-05 will connect and begin scrolling the current temp and relative humidity (Fahrenheit and Celcius).
//             4. Modify and have fun. 
//


// include the DHT11 Library...
#include <DHT.h>

//DHT11 Sensor: pin-out, looking at the "hole" side, l-r: VCC, Output, Blank, GND
#define DHTPIN 7 // Output pin to Digital #7 on the Uno
#define DHTTYPE DHT11 //Type of DHT sensor we're using
DHT dht(DHTPIN, DHTTYPE); //initializes the DHT sensor

int ledPin = 13;
int state = 0;
int flag = 0;

void setup() {
 // pinMode(ledPin, OUTPUT);
 // digitalWrite(ledPin, LOW);
  Serial.begin(9600);

  Serial.println("DHTxx test!");
  dht.begin();
}

void loop(){
//  if(Serial.available()>0){
//    state = Serial.read();
//    flag=0;
//  }
//  if (state = 0){
//    digitalWrite(ledPin, LOW);
//    if(flag == 0){
//      Serial.println("LED:off");
//      flag = 1;
 //     }
 // }
 // else if (state = 1){
 //  digitalWrite(ledPin, HIGH);
 //   if(flag==0){
 //     Serial.println("led:on");
  //    flag = 1;
  //  }
  //}
  //DHT loop...
  // Wait 3 seconds between measurements.
  delay(3000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print("*C ");
  Serial.print(f);
  Serial.print("*F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print("*C ");
  Serial.print(hif);
  Serial.println("*F");
}

