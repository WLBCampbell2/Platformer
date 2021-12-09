if !place_free(obj_player.x, obj_player.y+1) && place_free(obj_player.x, obj_player.y-4){
  vspeed=-7
}
if place_meeting(obj_player.x, obj_player.y, obj_ladder) && place_free(obj_player.x, obj_player.y-4){
  y=y-4
}
