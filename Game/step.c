// if below there is space set gravity to 0.25 and gravity_direction to 270
if place_empty(x, y+1) {
  gravity=0.25
  gravity_direction=270
}

// else set gravity to 0 and gravity_direction is set to 270
else {
  gravity=0
  gravity_direction=270
}

// if vspeed is -12 or less set it to -12
if vspeed<=-12 {
  vspeed=-12
}

// there is a ladder below gravity is set to 0 and gravity_direction is set to 270 and vspeed is set to 0
if instance_place(x, y+1, obj_ladder) {
  gravity=0
  gravity_direction=270
  vspeed=0
}
