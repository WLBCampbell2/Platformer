// if space is free below or your on a ladder go down
if place_free(x, y+4) || place_meeting(x, y+4, obj_ladder){
  vspeed=4
}
