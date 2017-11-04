/*  
      
       Последнее сообщение от пользователя Vk
       api.history_messages(id пользователя, access_token);

       Возвращаемая информация    
       api.last_message   Возвращает последнее сообщение от пользователя (String)
        
 
      
 */
#include <ArduinoJson.h> 
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <VkApiEsp8266.h>

const char* ssid = ""; 
const char* password = "";    
const char* access_token = "";// 1.Чтобы получить токен нужно перейти по ссылке https://vk.cc/7iEJnf 
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
        
       api.history_messages(id пользователя, access_token);
       
       Serial.println("last message"); 
       Serial.println(api.last_message);//Возвращает последнее сообщение от пользователя 
}
void loop() {
}
