#!/bin/bash
if test -f c.txt; then
    rm c.txt
fi
# Code within GameMaker
obj_player_create="
// lives
if room == 0{
    lives = 5
}

global.based=false

global.kali=false

done = false

/// defining combo
combo_key[1] = ord('K');
combo_key[2] = ord('A');
combo_key[3] = ord('L');
combo_key[4] = ord('I');
combo_step = 1;
"

obj_player_step="
execute_file(\"main.c\")

//  Kali
with(obj_player){
    if keyboard_check_pressed(combo_key[combo_step]){
        combo_step+=1
    }
    if (combo_step==5){
        global.kali=true
    }
}
"

quit="
show_message(\"Score: \"+string(score))
game_end()
"
quit_alt=$quit
quit_esc=$quit
quit_left_mouse=$quit

restart="
show_message(\"Score: \"+string(score))
game_restart()
"
restart_f5=$restart
restart_left_mouse=$restart

background_sound_create="sound_loop(sound1)"

# Puting internal code in file
echo -e "Internal code:\n\n\n" >> c.txt
for ifile in $(ls *.internalfilesinmysillygame)
do
echo -e "Contents of \"$ifile\":\n$(cat $ifile)\n\n" >> c.txt
done

# Code from external files
echo -e "External code:\n\n\n" >> c.txt
for file in $(ls *.c)
do
echo -e "Contents of \"$file\":\n$(cat $file)\n\n" >> c.txt
done