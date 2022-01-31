//outside room
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
