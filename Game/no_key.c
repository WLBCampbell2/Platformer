// move to the floor
move_contact_solid(270, 0.5)
// no hspeed
hspeed=0

// sprite is set depending on wether based is true or not
if global.based=false{
  sprite_index = spr_face
}
else{
  sprite_index = spr_based_face
}
