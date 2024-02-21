
The game features a snake constantly moving around the board. 
The player controls the direction of the snake's "head," which must try to eat randomly appearing apples. 
Eating an apple increases the snake's length. The game ends if the player crashes into the edge of the board or into itself. 
Each apple eaten increases the player's score by 10 points. The goal is to eat as many apples as possible, thus achieving the highest score.

User Manual
3.1 Main Menu
  ![image](https://github.com/piotrekskt/C-Snake-game-/assets/154207023/20589303-e1ef-4e06-99c1-3928841683c7)

  The main menu includes the game logo, instructions on how to start the game, and a leaderboard showing scores achieved during gameplay. 
  Scores will appear after the first game where the player scores more than 0 points. 
  To assign a player name to the obtained score, input it when the following screen appears:
  ![image](https://github.com/piotrekskt/C-Snake-game-/assets/154207023/0031f261-37b5-4c79-90e6-3584e9a1a9e0)

  After entering the name, we return to the main menu, where a new game can be started.

3.2 Gameplay
![image](https://github.com/piotrekskt/C-Snake-game-/assets/154207023/cfccb82f-0af7-423d-aec7-9581bd207766)

  In the game, individual characters represent:
  • "O" - player's head, which constantly moves, with the player controlling its direction.
  • "o" - player's body, which follows the head, collision with which ends the game.
  • "%" - board barrier, collision with which ends the game.
  • "@" - apple (point), the player's goal is to direct the head to the apple. This results in adding a body element and 10 points to the score.

Below the game board is the score of the current gameplay "Score: ".

3.3 Controls
  To initiate head movement, assign it an initial direction, and then change it to avoid collisions.
  
  "W" - assigns the head direction upwards.
  "S" - assigns the head direction downwards.
  "A" - assigns the head direction to the left.
  "D" - assigns the head direction to the right.
  "ESC" - ends the current gameplay and returns to the main menu.

Compilation
The project utilizes the Visual Studio 2022 development environment, which allows for standard project compilation. 
The C++ 20.0 language standard was used. The game was developed and tested on the Windows operating system, so it is recommended to use this system for proper operation.



