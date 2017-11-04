/*  
      
      Количество непрочитанных сообщений Vk
      api.new_messages(access_token);

      Возвращаемая информация    
      api.messages_new непрочитанные сообщения
        
Счетчик сбрасывается после прочтения сообщения    

      
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
        
       api.new_messages(access_token);

       Serial.println("messages new"); 
      Serial.println(api.messages_new);//Количество непрочитанных сообщений Vk
}
void loop() {
}
