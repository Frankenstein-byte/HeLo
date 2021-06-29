#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <LiquidCrystal.h>

const int RS = D2, EN = D3, d4 = D5, d5 = D6, d6 = D7, d7 = D8;   
LiquidCrystal lcd(RS, EN, d4, d5, d6, d7);

const char* ssid = "BPAS home";
const char* password = "cracksen";

const char* host = "maker.ifttt.com";
const int httpsPort = 443;
const int led = 20;
int flag = 0;
unsigned long time1;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(115200);
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

//  WiFiClientSecure client;
//  client.setInsecure();
//  Serial.print("connecting to ");
//  Serial.println(host);
//  if (!client.connect(host, httpsPort)) {
//    Serial.println("connection failed");
//    return;
//  }
//
//  String url = "/trigger/ESP/with/key/eAYk_HbS1PAgz7k9BYbzqevtjL3vvHfvGbcOHKv5AGv";
//  Serial.print("requesting URL: ");
//  Serial.println(url);
//
//  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
//               "Host: " + host + "\r\n" +
//               "User-Agent: BuildFailureDetectorESP8266\r\n" +
//               "Connection: close\r\n\r\n");
//
//  Serial.println("request sent");
//  while (client.connected()) {
//    String line = client.readStringUntil('\n');
//    if (line == "\r") {
//      Serial.println("headers received");
//      break;
//    }
//  }
//  String line = client.readStringUntil('\n');
//
//  Serial.println("reply was:");
//  Serial.println("==========");
//  Serial.println(line);
//  Serial.println("==========");
//  Serial.println("closing connection");
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop()
{  
  int bpm;
  bpm = analogRead(A0)/5;
  //Serial.println(bpm);
  lcd.setCursor(0,0);
  lcd.print("BPM : ");
  lcd.setCursor(7,0);
  lcd.print(bpm);
  
  if(Serial.available()>0)
  {
    char temp[5];
    temp[5] = char(Serial.read());
    delay(2);
    Serial.println(temp[5]);
  }
  digitalWrite(led, HIGH);
  time1 = millis();
  if(time1 % 3000 == 0)
  {
    WiFiClientSecure client;
    client.setInsecure();
    Serial.print("connecting to ");
    Serial.println(host);
    if (!client.connect(host, httpsPort)) {
      Serial.println("connection failed");
      lcd.setCursor(0,1);
      lcd.print("Connection Failed");
      return;
    }
  
    String url = "/trigger/ESP/with/key/eAYk_HbS1PAgz7k9BYbzqevtjL3vvHfvGbcOHKv5AGv";
    Serial.print("requesting URL: ");
    Serial.println(url);
  
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "User-Agent: BuildFailureDetectorESP8266\r\n" +
                 "Connection: close\r\n\r\n");
  
    Serial.println("request sent");
    lcd.setCursor(0, 1);
    lcd.print("Request Sent");
    while (client.connected()) {
      String line = client.readStringUntil('\n');
      if (line == "\r") {
        Serial.println("headers received");
        break;
      }
    }
    String line = client.readStringUntil('\n');
  
    Serial.println("reply was:");
    Serial.println("==========");
    Serial.println(line);
    Serial.println("==========");
    Serial.println("closing connection");
    digitalWrite(led, LOW);
    //digitalWrite(led, LOW);
  }
  delay(10);
}
