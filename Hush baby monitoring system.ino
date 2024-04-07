
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

#include "live-streaming/blynk_config.h"
#include "hotspot_config.h"

// Your WiFi credentials.
// Set password to "" for open networks.

const int sampleWindow = 50;                              // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;

#define ANALOG_INPUT A0

#define DHTPIN 4 
const int sensorPin = 5;

#define RAIN_SENSOR_THRESHOLD 500 // adjust this value based on your sensor
#define fan_pin 14         // What digital pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11     // DHT 11
//#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
int sensor = 13;  // Digital pin D7
bool pir_active=false;
BLYNK_CONNECTED() // Every time we connect to the cloud.
{
    Blynk.syncVirtual(V7);
}
BLYNK_WRITE(V7)
{
    pir_active=param.asInt();
}

void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
  
  int sensorState = digitalRead(sensorPin);  // Read the digital value from the sensor
 
  if(sensorState == LOW)  // Rain detected
  {
    Blynk.logEvent("wetness123");
  }
  
  long state = digitalRead(sensor);
  if(pir_active){
    if(state==HIGH){
      Blynk.virtualWrite(V1,1);
      Blynk.logEvent("motion_detected");
      
    }
    else{
      Blynk.virtualWrite(V1,0);
    }
  }



  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  
  
  if(t>30){
    digitalWrite(fan_pin,LOW);
    Blynk.logEvent("high_temperature");
  }
  else digitalWrite(fan_pin,HIGH);
  
  unsigned long startMillis= millis();                   // Start of sample window
  float peakToPeak = 0;                                  // peak-to-peak level
 
  unsigned int signalMax = 0;                            //minimum value
  unsigned int signalMin = 1024;                         //maximum value
 
                                                          // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(ANALOG_INPUT);                             //get reading from microphone
      if (sample < 1024)                                  // toss out spurious readings
      {
         if (sample > signalMax)
         {
            signalMax = sample;                           // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;                           // save just the min levels
         }
      }
   }
  peakToPeak = signalMax - signalMin;                    // max - min = peak-peak amplitude
  int db = map(peakToPeak,20,900,49.5,90);
  

  Blynk.virtualWrite(V0, sensorState);

  Blynk.virtualWrite(V5, h);
  Blynk.virtualWrite(V6, t);
  Blynk.virtualWrite(V2, db);
  if(db>=50){
    Blynk.logEvent("loud_sound");
  }
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(sensor, INPUT);
  pinMode(fan_pin,OUTPUT);
  digitalWrite(fan_pin,LOW);
   


  Blynk.begin(BLYNK_AUTH_TOKEN, SSID, PASS);
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);

  dht.begin();

  // Setup a function to be called every second
  timer.setInterval(2000L, sendSensor);
}


void loop()
{
  Blynk.run();
  timer.run();
}