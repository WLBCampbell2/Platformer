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

// Collision with objects below
if !place_empty(x, y-1){
  y-=1
  execute_file("gravity_turn_off.c")
}
// better than falling through but not great

// no key
if keyboard_check(vk_nokey){
  execute_file("no_key.c")
}

// alt key
if keyboard_check(vk_alt){
  execute_file("alt_key.c")
}

// outside room
if !(x >= 0 && x <= room_width && y >= 0 && y <= room_height){
  execute_file("outside_room.c")
}

// no lives
if room_next(room) != -1 && lives < 1{
  execute_file("no_lives.c")
}

// F11
if keyboard_check(vk_f11){
  execute_file("f11_key.c")
}
