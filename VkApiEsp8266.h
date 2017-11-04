 
 

#include <ArduinoJson.h> 
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
  
 

class VkApi {

private:
	const char* fingerprint_vk = "fb 9b af 57 f4 46 7c bf 90 80 e5 7a 18 6e 15 a3 0f 11 dd 9f"; //vk.com
	const char* host_vk = "api.vk.com";
	const int httpsPort = 443;
	String line;
	String object_type;
	int owner_id;
	int item_id;
	
	 
	 
	 
public:
	 
	int likes, comments, reposts, views;
	int like_photo;
	int messages_new;
	int error;
	String  last_message;
	WiFiClientSecure client_vk;

	
	void wall(String id) {
		//https://vk.com/dev/wall.getById
		String url = "/method/wall.getById?posts=";
		url += id;
		url += "&v=5.68";

		if (!client_vk.connect(host_vk, httpsPort)) {
			error = 1;
		   }
		   else {
			   error = 0;
			if (client_vk.verify(fingerprint_vk, host_vk)) {
				client_vk.print(String("GET ") + url + " HTTP/1.1\r\n" +
					"Host: " + host_vk + "\r\n" +
					"Connection: close\r\n\r\n");
			  }
			else {
				error = 1;
			     }
		}
		   delay(500);
	 while (client_vk.available()) {
			line = client_vk.readStringUntil('\r');
			DynamicJsonBuffer  jsonBuffer;
			JsonObject& root = jsonBuffer.parseObject(line);
			likes = root["response"][0]["likes"]["count"];//информация о лайках к записи
			comments = root["response"][0]["comments"]["count"];//информация о комментариях к записи
			reposts = root["response"][0]["reposts"]["count"];//информация о репостах записи 
			views = root["response"][0]["views"]["count"];//информация о просмотрах записи
	    	}

	}
	void like(String object_type,  int owner_id,  int item_id) {
		       //https://vk.com/dev/likes.getList  
		      //object_type   post — запись на стене  photo — фотография
		     //owner_id      идентификатор владельца Like-объекта: id пользователя   
		    //item_id       идентификатор Like-объекта                                


		String url = "/method/likes.getList?";
		url += "type=";
		url += object_type;
		url += "&owner_id=";
		url += owner_id;
		url += "&item_id=";
		url += item_id;
		url += "&count=2&&v=5.68";
		if (!client_vk.connect(host_vk, httpsPort)) {
			error = 1;
		}
		else {
			error = 0;
			if (client_vk.verify(fingerprint_vk, host_vk)) {
				client_vk.print(String("GET ") + url + " HTTP/1.1\r\n" +
					"Host: " + host_vk + "\r\n" +
					"Connection: close\r\n\r\n");
			}
			else {
				error = 1;
			}
		}
		delay(500);
	  while (client_vk.available()) {
			line = client_vk.readStringUntil('\r');
			DynamicJsonBuffer  likeBuffer;

			JsonObject& root = likeBuffer.parseObject(line);
			like_photo = root["response"]["count"];
		  }
	}
	void message(int id_vk, String token, String message) {
		// Отправляет сообщение https://vk.com/dev/messages.send

		String url = "/method/messages.send?user_id=";
		url += id_vk;
		url += "&message=";
		url += message;
		url += "&v=5.37&access_token=";
		url += token;
		if (!client_vk.connect(host_vk, httpsPort)) {
			error = 1;
		}
		else {
			error = 0;
			if (client_vk.verify(fingerprint_vk, host_vk)) {
				client_vk.print(String("GET ") + url + " HTTP/1.1\r\n" +
					"Host: " + host_vk + "\r\n" +
					"Connection: close\r\n\r\n");
			}
			else {
				error = 1;
			}
		}
	} 
	void message(int id_vk, String token, int message) {
		// Отправляет сообщение https://vk.com/dev/messages.send

		String url = "/method/messages.send?user_id=";
		url += id_vk;
		url += "&message=";
		url += message;
		url += "&v=5.37&access_token=";
		url += token;
		if (!client_vk.connect(host_vk, httpsPort)) {
			error = 1;
		}
		else {
			error = 0;
			if (client_vk.verify(fingerprint_vk, host_vk)) {
				client_vk.print(String("GET ") + url + " HTTP/1.1\r\n" +
					"Host: " + host_vk + "\r\n" +
					"Connection: close\r\n\r\n");
			}
			else {
				error = 1;
			}
		}
	}
	void new_messages(String token) {
		//https://vk.com/dev/account.getCounters

		String url = "/method/account.getCounters?filter=messages&v=5.68&access_token=";
		url += token;

		if (!client_vk.connect(host_vk, httpsPort)) {
			error = 1;
		}
		else {
			error = 0;
			if (client_vk.verify(fingerprint_vk, host_vk)) {
				client_vk.print(String("GET ") + url + " HTTP/1.1\r\n" +
					"Host: " + host_vk + "\r\n" +
					"Connection: close\r\n\r\n");
			}
			else {
				error = 1;
			}
		}
		delay(500);
		while (client_vk.available()) {
			line = client_vk.readStringUntil('\r');
			DynamicJsonBuffer  vkBuffer;

			JsonObject& root = vkBuffer.parseObject(line);
			messages_new = root["response"]["messages"];
		}
	}
	void history_messages(int id_vk, String token) {
		// Возвращает историю сообщений https://vk.com/dev/messages.getHistory    

		String url = "/method/messages.getHistory?count=1&user_id=";
		url += id_vk;
		url += "&v=5.37&access_token=";
		url += token;

		if (!client_vk.connect(host_vk, httpsPort)) {
			error = 1;
		}
		else {
			error = 0;
			if (client_vk.verify(fingerprint_vk, host_vk)) {
				client_vk.print(String("GET ") + url + " HTTP/1.1\r\n" +
					"Host: " + host_vk + "\r\n" +
					"Connection: close\r\n\r\n");
			}
			else {
				error = 1;
			}
		}
		delay(500);
		while (client_vk.available()) {
			line = client_vk.readStringUntil('\r');
			DynamicJsonBuffer  vkBuffer;

			JsonObject& root = vkBuffer.parseObject(line);
		String last_messagew = root["response"]["items"][0]["body"];
		last_message = last_messagew;
		}
	}
      
 
};

 
