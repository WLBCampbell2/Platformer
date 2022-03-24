// if its not the last room take a life away and if lives are still more than 0 put character at starting position and set gravity to 0 and vspeed to -1,
// else the screen wraps
if room_next(room) != -1{
  lives -= 1
  if lives > 0 {
    x = xstart
    y = ystart
    gravity=1
    vspeed=-1
  }
}
else move_wrap(true, true, 10)
