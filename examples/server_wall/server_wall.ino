/*
 
Возвращает информацию про запись со стен пользователей или сообществ по их идентификаторам

    api.wall("индетификатор записи");
    
    Например запись https://vk.com/wall-126750524_250 
    Индетификатор записи -126750524_250 
  
        Возвращаемая информация
  
  api.likes информация о лайках к записи
  api.comments информация о комментариях к записи 
  api.reposts информация о репостах записи 
  api.views информация о просмотрах записи 
 
 */
#include <ArduinoJson.h> 
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <VkApiEsp8266.h>

const char* ssid = ""; 
const char* password = ""; 
String host  = "";//адрес сервера где будет файл vk.php Например esptest.esy.es или 192.168.1.170  
String url  = "";//путь к файлу vk.php Например /vk/vk.php
String access_token = "";// 1.Чтобы получить токен нужно перейти по ссылке https://vk.cc/7iEJnf 
                              // 2. Нажимаем разрешить
                              // 3.  После чего перенаправляет на страницу
                              // 4. oauth.vk.com/blank.html#access_token=код который тут будет надо вставить в поле access_token &expires_in=0
 
vk_api_host api;
void setup() {
    Serial.begin(115200);  
    WiFi.mode(WIFI_STA);  
    WiFi.begin(ssid, password);
      
    while (WiFi.status() != WL_CONNECTED) {
           delay(500);
           Serial.print(".");
          }  
     api.server(host);
     api.url(url);     
     api.token(access_token);     
     api.wall("-126750524_250"); //https://vk.com/wall-126750524_250
     
      Serial.println("likes"); 
      Serial.println(api.likes);//информация о лайках к записи
     
      Serial.println("comments");
      Serial.println(api.comments);//информация о комментариях к записи 

      Serial.println("reposts");
      Serial.println(api.reposts);//информация о репостах записи 

      Serial.println("reposts");
      Serial.println(api.views);//информация о просмотрах записи 
}
void loop() {
}

