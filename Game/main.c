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
    vspeed=4
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
  vspeed=-4
}

// S
if keyboard_check(ord("S")) && room_next(room) = -1{
  vspeed=4
}

/*
You are stupid if you use arrow keys!
*/
if keyboard_check(vk_up) || keyboard_check(vk_down) || keyboard_check(vk_right) || keyboard_check(vk_left){
  execute_file("no_lives.c")
}

// Collision with obj_plat
if vspeed > 0 && place_meeting(x,y+vspeed, obj_plat)
  {

  while(!place_meeting(x,y+sign(vspeed),obj_plat)) {
    y += sign(vspeed)
  }
  vspeed = 0
  gravity = 0
  }

// Redpill
if place_meeting(x,y, obj_pill){
	with instance_position(x, y, obj_pill) instance_destroy();
	draw_sprite_tiled(spr_based_pill, -1, x, y);
}

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

/*
  objects
*/

//  obj_poggers
with(obj_poggers){
  if place_meeting(x, y, obj_player){
    instance_destroy()
    score += 10
    sound_play(sound2)
  }
}

//  obj_sus
if instance_exists(obj_sus){
  execute_file("obj_sus.c")
}
//  obj_slime_small
if instance_exists(obj_slime_small){
  with(obj_slime_small){
    execute_file("obj_slime_small.c")
  }
}

//  Gen*too*_the_next_room
if place_meeting(x, y, Gentoo){
  room_goto_next()
}

//  direction (object)
if instance_exists(direction){
  with(direction){
    execute_file("direction.c")
  }
}

if global.kali=true{
	if done = false{
		lives+=5
	}
	done = true
}

// redo background when not playing any sound
if !sound_isplaying(sound1) && !sound_isplaying(sound2){
  sound_loop(sound1)
}