/*
  Возвращает информацию о лайках к фото        
  про запись со стен пользователей или сообществ по их идентификатор пользователя сообщества
   
 api.like("photo",идентификатор пользователя сообщества,идентификатор Like-объекта ); 
 
    
    Например запись https://vk.com/photo-126750524_456239024 
    Идентификатор пользователя сообщества -126750524 
    идентификатор Like-объекта  456239024 
  
        Возвращаемая информация
  
  api.like_photo информация о лайках к фото 
  
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
        
    api.like("photo",-126750524,456239024); //https://vk.com/photo-126750524_456239024 
    
      Serial.println("likes"); 
      Serial.println(api.like_photo);//информация о лайках к фото 
      
}
void loop() {
}
