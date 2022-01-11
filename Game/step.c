if place_empty(x, y+1) {
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
if instance_place(x, y, obj_ladder) {
  gravity=0
  gravity_direction=270
  vspeed=3
}
