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
