if place_free(x, y+4){
  vspeed=4
  if place_meeting(x, y, obj_ladder){
    gravity=0
  }
  else{
    vspeed=0
  }
}
