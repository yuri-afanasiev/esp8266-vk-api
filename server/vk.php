<?php   
$ri = htmlspecialchars($_GET['ri']);
if ($ri == '30') {
      $id = htmlspecialchars($_GET['id']);
	  $token = htmlspecialchars($_GET['access_token']);
      $url_30='https://api.vk.com/method/wall.getById?posts='. $id.'&v=5.68&access_token='. $token;
      $json_string = file_get_contents($url_30);
      $json = json_decode($json_string, true); 
      $views = $json['response']['0']['views']['count'];//  
      $reposts = $json['response']['0']['reposts']['count'];//информация о репостах записи 
      $comments = $json['response']['0']['comments']['count'];//информация о комментариях к записи 
      $likes = $json['response']['0']['likes']['count'];//информация о лайках к записи 
	  $json_data = array ('views'=>$views,'reposts'=>$reposts,'comments'=>$comments,'likes'=>$likes);
      echo  json_encode($json_data); 
	   //http://192.168.1.170/vk/vk.php/?id=-126750524_250&ri=30
}
 if ($ri == '31') {
    $type = htmlspecialchars($_GET['type']);
    $owner_id = htmlspecialchars($_GET['owner_id']);
    $item_id = htmlspecialchars($_GET['item_id']);
	$token = htmlspecialchars($_GET['access_token']);
    $url_31 ='https://api.vk.com/method/likes.getList?type='. $type.'&owner_id='. $owner_id.'&item_id='. $item_id. '&count=2&v=5.68&access_token='. $token;
    $json_string = file_get_contents($url_31);
    $json = json_decode($json_string, true); 
    $like_photo = $json['response']['count']; 
	$json_data = array ('like_photo'=>$like_photo);
    echo  json_encode($json_data); 
	//http://192.168.1.170/vk/vk.php/?owner_id=-126750524&item_id=456239024&count=2&v=5.68&type=photo&ri=31
}
 if ($ri == '32') {
      $group_id = htmlspecialchars($_GET['group_id']);
	  $token = htmlspecialchars($_GET['access_token']);
      $url_32='https://api.vk.com/method/groups.getMembers?group_id='. $group_id.'&count=1&v=5.37&access_token='. $token;
      $json_string = file_get_contents($url_32);
      $json = json_decode($json_string, true); 
	  $participants = $json['response']['count'];
	  $json_data = array ('participants'=>$participants);
      echo  json_encode($json_data);  
	  //http://192.168.1.170/vk/vk.php/?group_id=126750524&ri=32
}
if ($ri == '33') {
      $token = htmlspecialchars($_GET['access_token']);
      $url_33='https://api.vk.com/method/account.getCounters?filter=messages&v=5.68&access_token='. $token ;
      $json_string = file_get_contents($url_33);
      $json = json_decode($json_string, true); 
	  $messages_new = $json['response']['messages'];
	  $json_data = array ('messages_new'=>$messages_new);
      echo  json_encode($json_data);  
	   
}

?>