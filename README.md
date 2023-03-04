Hi, this is my OLED screen game on nucleo-g431kb called "boxi game"

🎮GAME🎮

boxi player must avoid mobs and spikes and collect coins from each map to win. There will be 15 maps and only 3 lives. maps are randomly selected one by one.

🐱‍👤CODE🐱‍👤

The code is written on classes and objects, which makes adding new functions transparent and easy. There are classes (Map, Spike, Player, Block, Mob) each class except Map has functions:

✨generateHIT -to create hit box objects

✨Check -if boxes/player hit him (only map and boxes don't have it)

✨Display_Block/Spike/player/map - for easy screen change in the future I want to add ILI9341 display so inside this function is ssd1306 driver function to draw bitmap on display

✨Change_position- so we can create an array of objects for them by checking for collisions in a for loop and this function can reposition each other at the beginning of the code

in main we have functions: Gravitation , Jump , Check_buttons . Every object other than the player and the map tells them if the player is standing or has any collisions with them, so for example if the boxi is standing on something, he can jump.

and we have functions: Display_Over_Screen, Game. In the game, we use all the functions of the objects and display the game. In Display_Over_Screen, we display the game on the screen when a player dies
