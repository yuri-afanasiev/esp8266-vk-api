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
String access_token = "";// 1.Чтобы получить токен нужно перейти по ссылке https://vk.cc/7iEJnf 
                              // 2. Нажимаем разрешить
                              // 3.  После чего перенаправляет на страницу
                              // 4. oauth.vk.com/blank.html#access_token=код который тут будет надо вставить в поле access_token &expires_in=0
   
VkApi api; 
 
void setup() {
    Serial.begin(115200);  
    WiFi.mode(WIFI_STA);  
    WiFi.begin(ssid, password);  
    while (WiFi.status() != WL_CONNECTED) {
           delay(500);
           Serial.print(".");
          }  
    api.token(access_token);    
    api.like("photo",-126750524,456239024); //https://vk.com/photo-126750524_456239024 
    
      Serial.println("likes"); 
      Serial.println(api.like_photo);//информация о лайках к фото 
      
}
void loop() {
}
