# esp8266-vk-api
 
## Возвращает информацию про запись со стен пользователей или сообществ по их идентификаторам

    api.wall("индетификатор записи");
    
    Например запись https://vk.com/wall-126750524_250 
    Индетификатор записи -126750524_250 
  
        Возвращаемая информация
  
  api.likes информация о лайках к записи
  api.comments информация о комментариях к записи 
  api.reposts информация о репостах записи 
  api.views информация о просмотрах записи 

 ## Возвращает информацию о лайках к фото         
   
 api.like("photo",идентификатор пользователя сообщества,идентификатор Like-объекта ); 
     
    Например запись https://vk.com/photo-126750524_456239024 
    Идентификатор пользователя сообщества -126750524 
    идентификатор Like-объекта  456239024 
  
        Возвращаемая информация
  
  api.like_photo информация о лайках к фото 

## Количество непрочитанных сообщений Vk
      api.new_messages(access_token);

        Возвращаемая информация    
  api.messages_new непрочитанные сообщения

## Отправляет сообщение Vk
                               
api.message(id пользователя  которому отправляется сообщение, access_token, "текст сообщения"); 

## Последнее сообщение от пользователя Vk
  api.history_messages(id пользователя, access_token);

       Возвращаемая информация    
api.last_message   Возвращает последнее сообщение от пользователя (String)

