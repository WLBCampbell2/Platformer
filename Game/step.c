if place_empty(obj_player.x, obj_player.y+1) {
  gravity=0.5
  gravity_direction=270
}
else {
  gravity=0
  gravity_direction=270
}
if vspeed=-12 {
  vspeed=-12
}
if instance_place(obj_player.x, obj_player.y, obj_ladder) {
  gravity=0
  gravity_direction=270
  vspeed=0
}
