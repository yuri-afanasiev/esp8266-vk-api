/*
  Возвращает  информация о том, находится ли пользователь сейчас online       

 users_online(идентификатор пользователя) (String)
   
  
        Возвращаемая информация
  
  api.online  1 - online  0 - offline (int)
  
 */
#include <ArduinoJson.h> 
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <VkApiEsp8266.h>


const char* ssid = "";// ssid wifi
const char* password = ""; //  Пароль wifi   
   
VkApi api; 
 
void setup() {
    Serial.begin(115200);  
    WiFi.mode(WIFI_STA);  
    WiFi.begin(ssid, password);  
    while (WiFi.status() != WL_CONNECTED) {
           delay(500);
           Serial.print(".");
          }  
        
      api.users_online(" ");
     
      Serial.println("users");
      if (api.online == 1) { 
          Serial.println("online"); 
          } else {
          Serial.println("offline"); 
         } 
       
      
}
void loop() {
}
