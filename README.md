# Link to the GitHub project page:
https://github.com/Renyi03/Project-1

# Link to a 1-minute maximum video (YouTube or Vimeo) showing all implemented features


# Team members and GitHub accounts
* Sofia Barja Navarro (sofia-221b)
* Clara Sanchez Via (Valkyn22)
* Yin Ye Ji (Renyi03)

# Short description of the game
Pengo is an arcade game developed by Coreland and published by Sega in Japan on September 26, 1982.

In this video game, the player controls Pengo, a penguin trapped in a maze made out of ice blocks with multiple enemies known as Sno-Bees.
The player’s main objective is to survive each round by eliminating all the Sno-Bees.

# How to play the game, detailing the controls
To play the game, the player has to use the arrow keys to move the character (Pengo). If the player presses the arrow key at any direction and on that direction there is an ice block, there can be 2 consequences: pushing the block since the block meets another one or, if there is another block facing the one you are trying to push, the first one is going to break.
If the player presses a movement key towards a border, it will shake, and stun every Sno-bee touching it.
The goal of the game is to defeat all the Sno-Bees. If Pengo touches a Sno-Bee, the player loses one life, unless the Sno-bee is stunned. The game ends when all the lives are lost. Depending on how much time it took the player to pass the level, there will be some bonus points.

# List of features implemented
* Initial and title screen, with an intro animation
* Win/lose screen
* Lose condition (death) and Win condition (defeating all the enemies)
* Game screen
* User Interface:
	- Life counter: indicates the lives remaining, resetting for each level (at the top)
	- Points: total points since the game has started, resetting when game over (at the top)
	- Act number: indicates the number of the actual level, such as "ACT 7" at level 7 (at the bottom)
	- Level counter: indicates the number of the actual level with little Sno-bees images, one by one (at the bottom) and five by five (at the top). For example, in level 7, there will be two images at the bottom and one at the top.
* 16 different levels, generated randomly
* Border that the player can’t trespass, but can be shaked if a movement key is pressed towards it.
* Maze made out of ice blocks
* 4 enemies (Sno-bees) for each level, respawning in each level
* Collisions to each block
* Interactions with the ice blocks
	- Breaking
	- Pushing
* Actions of the Snobees:
	- Wander through the map randomly
	- If they are surrounded by 3 or more blocks, enter the "breaking mode", where they will break surrounding bloks with a 25% chance.
* Ways of defeating a Sno-bee:
	- Squashing them with a block
	- Walking over them when stunned
* Points system:
	- Breaking a block: 30 pts
	- Defeating a Sno-bee. 400 pts
	- Extra points according to the time spent in each level

* Background music and sound effects
* Textures for all the elements, and animations for Pengo, the Sno-bees and the walls

*Debugging functionalities:
	- Function for drawing a hitbox around Pengo or the Snobees, indicating if they are colliding with something
	- Press N to skip the level and go to the points screen