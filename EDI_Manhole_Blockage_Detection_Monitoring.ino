#include "ESP8266_AT.h"
#include <ThingSpeak.h>

#define MQ2pin A0

#define DOMAIN "api.thingspeak.com"
#define PORT "80"
#define API_WRITE_KEY "JSGU3MEFZM6FEWKY"
#define CHANNEL_ID "1633372"

#define SSID "adina"
#define PASSWORD "adina1234"

char _buffer[150];
uint8_t Connect_Status;
#ifdef SEND_DEMO
uint8_t Sample = 0;
#endif

float sensorValue; //variable to store sensor value

int trigPin = 10;
int echoPin = 9;
long time_echo;
int distance;

void setup() {
    pinMode(10, OUTPUT);
    pinMode(9, INPUT);
    Serial.begin(115200);
//
//    WiFi.begin(SSID, PASSWORD);             // Connect to the network
//    Serial.print("Connecting to ");
//    Serial.print(SSID); 
//    Serial.println(" ...");
//    
//    int i = 0;
//    while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
//      delay(1000);
//      Serial.print(++i); Serial.print(' ');
//    }
//  
//    Serial.println('\n');
//    Serial.println("Connection established!");

    Serial.println("Gas sensor warming up!");
    delay(5000);
}

void loop() {
//    Connect_Status = ESP8266_connected();
//    if (Connect_Status == ESP8266_NOT_CONNECTED_TO_AP) //Again check connection to WIFI/
//        ESP8266_JoinAccessPoint(SSID, PASSWORD); //Connect to WIFI/
//    if (Connect_Status == ESP8266_TRANSMISSION_DISCONNECTED)
//        ESP8266_Start(0, DOMAIN, PORT);
    int temp_adc_val;
    float temp_val;
    temp_adc_val = analogRead(15); /* Read Temperature */
    temp_val = (temp_adc_val * 4.88); /* Convert adc value to equivalent voltage */
    temp_val = (temp_val / 10); /* LM35 gives output of 10mv/°C */
    sensorValue = analogRead(MQ2pin); // read analog input pin 0

//    Serial.print("Sensor Value: ");

//    if (sensorValue > 400) {
//        Serial.print(" | Smoke detected!");
//    }
    digitalWrite(10, LOW);
    delayMicroseconds(2);
    digitalWrite(10, HIGH);
    delayMicroseconds(10);
    digitalWrite(10, LOW);
    time_echo = pulseIn(9, HIGH);
    distance = time_echo / 2 / 29.1;
//    Serial.print("Distance: ");
    Serial.print(sensorValue);
    Serial.print(" ");
//    Serial.print("\nTemperature = ");
    Serial.print(temp_val);
//    Serial.print(" Degree Celsius\n");
    Serial.print(" ");
    Serial.println(distance);
//    memset(_buffer, 0, 150);
//    sprintf(_buffer, "GET /update?api_key=%s&field1=%f&field2=%f&field3=%d", API_WRITE_KEY, temp_val, sensorValue, distance); //connect to thingspeak server to post data using your API_WRITE_KEY/
//    ESP8266_Send(_buffer);
//    delay(15000); /* Thingspeak server delay */
//
//    memset(_buffer, 0, 150);
//    sprintf(_buffer, "GET /channels/%s/feeds/last.txt", CHANNEL_ID); //Connect to thingspeak server to get data using your channel ID/
//    ESP8266_Send(_buffer);
//    Read_Data(_buffer);
//    delay(600);
 
    delay(2000); // wait 2s for next reading
}
