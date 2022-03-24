// sets hspeed to -4 if there is space to move to
if place_free(x-4, y){
  hspeed=-4
}

// sets sprite depending on if based is true or false
if global.based=false{
  sprite_index = spr_left
}
else{
  sprite_index = spr_based_left
}
