// checks the image and increases the players speed if at a particular index, else index is changed
if (image_index=0){
    if place_meeting(x,y,obj_player){
      with(obj_player){vspeed+=3}
    }
}
else{
  if (image_index<3){
    image_index+=1
  }
  else{
    image_index=0
  }
}