#!/bin/bash
if test -f all_code.txt; then
    rm all_code.txt
fi
# Code within GameMaker
funny_extension="internalfilesinmysillygame"
cat > obj_player_create.$funny_extension << "EOF1"
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
EOF1

cat > obj_player_step.$funny_extension << "EOF2"
execute_file("main.c")

//  Kali
with(obj_player){
    if keyboard_check_pressed(combo_key[combo_step]){
        combo_step+=1
    }
    if (combo_step==5){
        global.kali=true
    }
}
EOF2

cat > quit_alt.$funny_extension << "EOF3"
show_message("Score: "+string(score))
game_end()
EOF3
cp quit_alt.$funny_extension quit_esc.$funny_extension
cp quit_alt.$funny_extension quit_left_mouse.$funny_extension

cat > restart_f5.$funny_extension << "EOF4"
show_message("Score: "+string(score))
game_restart()
EOF4
cp restart_f5.$funny_extension restart_left_mouse.$funny_extension

cat > background_sound_create.$funny_extension << "EOF5"
sound_loop(sound1)
EOF5

# Puting internal code in output file
echo -e "Internal code:\n\n\n" >> all_code.txt
for ifile in $(ls *.$funny_extension)
do
echo -e "Contents of \"$(ls $ifile | awk -F .$funny_extension '{ print $1 }')\":\n$(cat $ifile)\n\n" >> all_code.txt
done

# Code from external files
echo -e "External code:\n\n\n" >> all_code.txt
for file in $(ls *.c)
do
echo -e "Contents of \"$file\":\n$(cat $file)\n\n" >> all_code.txt
done
# Removing temp files
rm *.$funny_extension
