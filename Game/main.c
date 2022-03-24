/*
    Whole platform game
*/

// execute step
if room_next(room) != -1{
  execute_file("step.c")
}

/*
    Movement
*/

// execute space when space is pressed
if keyboard_check(vk_space) && room_next(room) != -1{
  execute_file("space_button.c")
}

// execute shift when shift is pressed and its not the last room
if keyboard_check(vk_shift){
  if room_next(room) != -1{
    execute_file("shift_button.c")
  }
  else{
    vspeed=4
  }
}

// execute A when A key is pressed
if keyboard_check(ord("A")){
  execute_file("A_button.c")
}

// execute D when D key is pressed
if keyboard_check(ord("D")){
  execute_file("D_button.c")
}

// execute W when W key is pressed and its the last room
if keyboard_check(ord("W")) && room_next(room) = -1{
  vspeed=-4
}

// execute S when S key is pressed and its the last room
if keyboard_check(ord("S")) && room_next(room) = -1{
  vspeed=4
}

/*
You are stupid if you use arrow keys!
But really if ou press any arrow key you lose all lives
*/
if keyboard_check(vk_up) || keyboard_check(vk_down) || keyboard_check(vk_right) || keyboard_check(vk_left){
  execute_file("no_lives.c")
}

// Collision with obj_plat
// when speed is greater than 0 and the character is y+vspeed away from the platform do the following:
//  while the character is not meeting the platform at y+sign(vspeed) the characters y is increased by sign(vspeed)
//  vspeed is set to 0
//  gravity is set to 0
if vspeed > 0 && place_meeting(x,y+vspeed, obj_plat){
  while(!place_meeting(x,y+sign(vspeed),obj_plat)) {
    y += sign(vspeed)
  }
  vspeed = 0
  gravity = 0
  }

// when pressing no key execute no_key
if keyboard_check(vk_nokey){
  execute_file("no_key.c")
}

// when pressing the alt key execute alt_key
if keyboard_check(vk_alt){
  execute_file("alt_key.c")
}

// when the character is not ((x greater than or equal to 0) and (x less than or equal to the room's width) and (y is lesser than or equal to the room height)) execute outside_room
if !(x >= 0 && x <= room_width && y >= 0 && y <= room_height){
  execute_file("outside_room.c")
}

// when lives are less than 1 and its not the last room execute no_lives
if room_next(room) != -1 && lives < 1{
  execute_file("no_lives.c")
}

// when pressing F11 execute f11_key
if keyboard_check(vk_f11){
  execute_file("f11_key.c")
}

/*
  objects
*/

// with obj_poggers check for a collision with the character and if so destroy itself and increase score by 10 and play a sound
with(obj_poggers){
  if place_meeting(x, y, obj_player){
    instance_destroy()
    score += 10
    sound_play(sound2)
  }
}

// if obj_sus is in the current room execute obj_sus
if instance_exists(obj_sus){
  execute_file("obj_sus.c")
}
// if obj_slime_small is in the current room execute obj_slime_small
if instance_exists(obj_slime_small){
  with(obj_slime_small){
    execute_file("obj_slime_small.c")
  }
}

// if the character collides with Gentoo execute go to the next room
if place_meeting(x, y, Gentoo){
  room_goto_next()
}

// if direction is in the current room execute direction
if instance_exists(direction){
  with(direction){
    execute_file("direction.c")
  }
}

// if kali is true give lives
if global.kali=true{
	if done = false{
		lives+=5
	}
	done = true
}

// this will redo the background sound when not playing any sound
if !sound_isplaying(sound1) && !sound_isplaying(sound2){
  sound_loop(sound1)
}