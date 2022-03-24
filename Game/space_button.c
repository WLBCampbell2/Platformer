// space is free above and space is not free below
if place_free(x, y-4) && !place_empty(x, y+4){
  vspeed=-4.5
}
