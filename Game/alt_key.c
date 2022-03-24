// goes to next room if available, if not ends the game
if room_next(room) != -1{
  room_goto_next()
}
else game_end()
