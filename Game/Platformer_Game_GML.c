/*
    Whole platform game
*/

// step
if room_next(room) != -1{
  execute_file("step.c")
}

/*
    Movement
*/

// space
if keyboard_check(vk_space) && room_next(room) != -1{
  execute_file("space_button.c")
}

// shift
if keyboard_check(vk_shift){
  if room_next(room) != -1{
    execute_file("shift_button.c")
  }
  else{
    y=y+4
  }
}

// A
if keyboard_check(ord("A")){
  execute_file("A_button.c")
}

// D
if keyboard_check(ord("D")){
  execute_file("D_button.c")
}

// W
if keyboard_check(ord("W")) && room_next(room) = -1{
  y=y-4
}

// S
if keyboard_check(ord("S")) && room_next(room) = -1{
  y=y+4
}

// Movement is probally not a problem


/*
slowly goes through platform
// Collision with obj_plat
if !place_meeting(x, y + 1, obj_plat){
    move_contact_solid(270, -1)
}
// maybe a problem*/

// no key
if keyboard_check(vk_nokey){
  execute_file("no_key.c")
}
// Probally not a problem

// alt key
if keyboard_check(vk_alt){
  execute_file("alt_key.c")
}
// Probally not a problem
/*
//lives just dissapear
// outside room
if(obj_player.x >= 0 && obj_player.x <= room_width && obj_player.y >= 0 && obj_player.y <= room_height){
  execute_file("outside_room.c")
}
// maybe a problem*/

// no lives
if room_next(room) != -1 && lives < 1{
  execute_file("no_lives.c")
}
// Probally not a problem

// F11
if keyboard_check(vk_f11){
  execute_file("f11_key.c")
}
// Probally not a problem
