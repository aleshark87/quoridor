## Rules

>Quoridor is played on a game board of 81 square spaces (9x9). Each player is represented by a pawn which begins at the center space
of one edge of the board (in a two-player game, the pawns begin opposite each other). The objective is to be the first player to
move their pawn to any space on the opposite side of the gameboard from which it begins.
The distinguishing characteristic of Quoridor is its twenty walls. Walls are flat two-space-wide pieces which can be placed 
in the groove that runs between the spaces. Walls block the path of all pawns, which must go around them. The walls are divided
equally among the players at the start of the game, and once placed, cannot be moved or removed. On a turn, a player may either
move their pawn, or, if possible, place a wall.
Pawns can be moved to any space at a right angle (but not diagonally). If adjacent to another pawn, 
the pawn may jump over that pawn. If an adjacent pawn has a third pawn or a wall on the other side of it, the player may move to
either space that is immediately adjacent (left or right) to the first pawn. Multiple pawns may not be jumped. Walls may not be
jumped, including when moving laterally due to a pawn or wall being behind a jumped pawn.
Walls can be placed directly between two spaces, in any groove not already occupied by a wall. However, 
a wall may not be placed which cuts off the only remaining path of any pawn to the side of the board it must reach. 

### Compile

`./compile.sh`

### Start the game

`./quoridor`

### Todolist(wip)
* Barrier direction array attribute addition and managment
* Players control movement with barriers
* Path not hampered with barriers
