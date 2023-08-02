# NUCLEO G431KB BOXI GAME
![Banner-boxi-game](https://github.com/NYDEREK/GAME_STM32-NUCELO-G431KB/assets/112076828/f6b44766-35ec-425b-b42e-cc429abf3a96)
<img alt="Static Badge" src="https://img.shields.io/badge/Platform-STM32cubeIDE-darkcyan"> <img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/NYDEREK/GAME_STM32-NUCELO-G431KB"> <img alt="Static Badge" src="https://img.shields.io/badge/uC-STM32G431KB-light_blue"> <img alt="GitHub top language" src="https://img.shields.io/github/languages/top/NYDEREK/GAME_STM32-NUCELO-G431KB"> 

(for now not everthing it's done its work in progres)

## 🎮GAME🎮

Boxi (player) must avoid mobs and spikes and collect coins from each map to win. There will be 15 maps and only 3 lives. maps are randomly selected one by one.

## 🐱‍👤CODE🐱‍👤

The code is written on classes and objects, which makes adding new functions transparent and easy. There are classes (Map, Spike, Player, Block, Mob,Coin) each class except Map has functions:
* generateHIT -to create hit box objects
* Check -if boxi/player hit him (only map and boxi don't have it)
* Display_Block/Spike/player/map - for easy screen change in the future I want to add ILI9341 display so inside this function is ssd1306 driver function to draw bitmap on display
* Change_position- so we can create an array of objects for them by checking for collisions in a for loop and this function can reposition each other at the beginning of the code
in main we have functions: Gravitation , Jump , Check_buttons . Every object other than the player and the map tells them if the player is standing or has any collisions with them, so for example if the boxi is standing on something, he can jump.

and we have functions: Display_Over_Screen, Game. In the game, we use all the functions of the objects and display the game. In Display_Over_Screen, we display the game on the screen when a player dies

![obraz_2023-03-12_165535059](https://user-images.githubusercontent.com/112076828/224556436-bd9b311a-e8e2-4f13-9b84-e3af18211fe2.png)


## Project use:
for OLED i am using afiskon's library https://github.com/afiskon/stm32-ssd1306

