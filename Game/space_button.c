if !place_free(x, y+1) && place_free(x, y-4){
  vspeed=-4
}
if place_meeting(x, y, obj_ladder) && place_free(x, y-4){
  vspeed=-4
}
