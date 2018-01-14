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
	int participants;
	int online;
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
		   delay(200);
	 while (client_vk.available()) {
			line = client_vk.readStringUntil('\r');
			DynamicJsonBuffer  jsonBuffer;
			JsonObject& root = jsonBuffer.parseObject(line);
			likes = root["response"][0]["likes"]["count"];//информация о лайках к записи
			comments = root["response"][0]["comments"]["count"];//информация о комментариях к записи
			reposts = root["response"][0]["reposts"]["count"];//информация о репостах записи 
			views = root["response"][0]["views"]["count"];//информация о просмотрах записи
	    	}
	 client_vk.stop();
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
		delay(200);
	  while (client_vk.available()) {
			line = client_vk.readStringUntil('\r');
			DynamicJsonBuffer  likeBuffer;

			JsonObject& root = likeBuffer.parseObject(line);
			like_photo = root["response"]["count"];
		  }
	  client_vk.stop();
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
		//client_vk.stop();
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
		client_vk.stop();
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
		delay(200);
		while (client_vk.available()) {
			line = client_vk.readStringUntil('\r');
			DynamicJsonBuffer  vkBuffer;

			JsonObject& root = vkBuffer.parseObject(line);
			messages_new = root["response"]["messages"];
		}
		client_vk.stop();
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
		delay(200);
		while (client_vk.available()) {
			line = client_vk.readStringUntil('\r');
			DynamicJsonBuffer  vkBuffer;

			JsonObject& root = vkBuffer.parseObject(line);
		String last_messagew = root["response"]["items"][0]["body"];
		last_message = last_messagew;
		}
		client_vk.stop();
	}

	void group(int group_id) {
		 //https://vk.com/dev/groups.getMembers
		 //group_id       id группы 
                                
		String url = "/method/groups.getMembers?";
		url += "group_id=";
		url +=  group_id;
		url += "&count=1&v=5.37";
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
		delay(200);
		while (client_vk.available()) {
			line = client_vk.readStringUntil('\r');
			DynamicJsonBuffer  likeBuffer;

			JsonObject& root = likeBuffer.parseObject(line);
			participants = root["response"]["count"];
		}
		client_vk.stop();
	}
 


	void users_online(String users) {
		//https://vk.com/dev/users.get
		String url = "/method/users.get?";
		url += "user_ids=";
		url += users;
		url += "&fields=online&name_case=Nom&v=5.69";
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
		delay(1000);
		while (client_vk.available()) {
			line = client_vk.readStringUntil('\r');
			DynamicJsonBuffer  likeBuffer;

			JsonObject& root = likeBuffer.parseObject(line);
			online = root["response"][0]["online"];
		}
		client_vk.stop();
	}


};
class vk_api_host {

private:
	const int httpPort = 80;
	String host_vk;
	String wurl;

	String line;
	String object_type;
	int owner_id;
	int item_id;


public:
	int likes, comments, reposts, views;
	int like_photo;
	int messages_new;
	int participants;
	int error;
	String  last_message;
	WiFiClient  client_vk_host;

	void server(String host) {
		host_vk = host;
	}

	void url(String host) {
		wurl = host;
	}
	void wall(String id) {
		String url = wurl;
		url += "?id=";
		url += id;
		url += "&ri=30";
		 

		if (client_vk_host.connect(host_vk.c_str(), httpPort)) {
			client_vk_host.print(String("GET ") + url + " HTTP/1.1\r\n" +
				"Host: " + host_vk + "\r\n" +
				"Connection: close\r\n\r\n");
			 
		}
		delay(500);
		while (client_vk_host.available()) {
			line = client_vk_host.readStringUntil('\r');
			DynamicJsonBuffer  jsonBuffer;
			JsonObject& root = jsonBuffer.parseObject(line);
			likes = root["likes"];//информация о лайках к записи
			comments = root["comments"];//информация о комментариях к записи
			reposts = root["reposts"];//информация о репостах записи 
			views = root["views"];//информация о просмотрах записи
		}



	}

	void like(String object_type, int owner_id, int item_id) {
		//https://vk.com/dev/likes.getList  
		//object_type   post — запись на стене  photo — фотография
		//owner_id      идентификатор владельца Like-объекта: id пользователя   
		//item_id       идентификатор Like-объекта      

	 
	 
		String url = wurl;
		url += "?owner_id=";
		url += owner_id;
		url += "&item_id=";
		url += item_id;
		url += "&type=";
		url += object_type;
		url += "&ri=31";


		if (client_vk_host.connect(host_vk.c_str(), httpPort)) {
			client_vk_host.print(String("GET ") + url + " HTTP/1.1\r\n" +
				"Host: " + host_vk + "\r\n" +
				"Connection: close\r\n\r\n");
		 
		}
		delay(500);
		while (client_vk_host.available()) {
			line = client_vk_host.readStringUntil('\r');
			DynamicJsonBuffer  jsonBuffer;
			JsonObject& root = jsonBuffer.parseObject(line);
			like_photo = root["like_photo"];
		}

		 

			 
 

}


	void group(int group_id) {
		//https://vk.com/dev/groups.getMembers
		//group_id       id группы 
		String url = wurl;
		url += "?group_id=";
		url += group_id;
		url += "&ri=32";


		if (client_vk_host.connect(host_vk.c_str(), httpPort)) {
			client_vk_host.print(String("GET ") + url + " HTTP/1.1\r\n" +
				"Host: " + host_vk + "\r\n" +
				"Connection: close\r\n\r\n");

		}
		delay(500);
		while (client_vk_host.available()) {
			line = client_vk_host.readStringUntil('\r');
			DynamicJsonBuffer  jsonBuffer;
			JsonObject& root = jsonBuffer.parseObject(line);
			participants = root["participants"];
		}



	}


	void new_messages(String token) {
		//https://vk.com/dev/account.getCounters

		String url = wurl;
		url += "?token=";
		url += token;
		url += "&ri=33";


		if (client_vk_host.connect(host_vk.c_str(), httpPort)) {
			client_vk_host.print(String("GET ") + url + " HTTP/1.1\r\n" +
				"Host: " + host_vk + "\r\n" +
				"Connection: close\r\n\r\n");

		}
		delay(500);
		while (client_vk_host.available()) {
			line = client_vk_host.readStringUntil('\r');
			DynamicJsonBuffer  jsonBuffer;
			JsonObject& root = jsonBuffer.parseObject(line);
			messages_new = root["messages_new"];
		}



	}


};
 
