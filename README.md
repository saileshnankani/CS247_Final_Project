# The-UW-Game

Welcome to the UW Game!

The UW Game is a Role-playing game (RPG), where a co-operative education student going to the University of Waterloo tries to find their way to California.
But first, they must battle geese, answer tough questions, and interact with Waterloo community.
The player progresses through each location by moving around the map to have conversation with non-player characters (NPC) and engage in combat.
The player has health, which needs to remain positive throughout the game.
If the player is able to pass all of their interviews, they go to California and complete the game! :sunny:

This project was made by _Sailesh Nankanki, Angelo Lao, Rosie Bahrani_ for the Software Design Principles course (CS 247) at the University of Waterloo.

## Overview
### Key Features:
- Conversation
- Interview
- Combat
- Easy, Medium, Hard Level
- Graphical
- Ability to traverse between locations grids in the game. 
- Ability to change locations, player position, number and type of characters, conversation, and interviews without any recompilation.

### The Board:
 
The playing board (location) is a 2D matrix, where the row size could vary. These are finite and consist of Tiles, of which there are a variety of types including teleporter and wall tiles. These tiles can contain any character. There are 3 types of tiles: wall, open, and teleporter. Teleporter tiles teleports players from one location to another. 
 
### Display:
 
There is both a text-based display and a graphical display of the game board. The interaction for both displays is terminal based i.e. the controls are typed into the terminal and the conversation/interview also shows up on the terminal. 
 
### Command Interpreter:
 
You can interact with the system by issuing text-based commands. The following commands are supported:
- w : moves the player one tile to the North
- s : moves the player one tile to the South
- a : moves the player one tile to the East
- d : moves the player one tile to the West
- 0 - 9 : To respond to NPCs / answer interview questions
- q : quits the game

### Level:
 
There are 3 levels : easy, medium, and hard.

 
**Easy:** Each attack decreases the player’s HP by 5 points.

**Medium:** Each attack decreases the player’s HP by 10 points.

**Hard:** Each attack decreases the player’s HP by 20 points. 


They are a set number of enemies.  
 
### Scoring:
 
The main objective of the game is to pass through all the interviews while keeping your health positive. To be able to get to the last level, the player needs to engage in an interview and pass the interviews. Each response is graded and the total score is tracked. Currently, the player needs to get at least half of them correct to pass the interview, however this can be changed by modifying the .in files and not recompilation is needed. 
Each time there is an attack, the user is able to see the update HP on the terminal. It needs to be positive during the game, otherwise the user loses the game. During a combat, the user is also able to see the updated health of the enemy on the display until it dies. 

## Design
Some of the key challenges we faced were:

### Allowing the game to have multiple locations:
We solved this problem by deciding that locations should maintain independent state (representing the grid of the location as well as the characters in the location).  The game keeps track of all of the locations using a vector, which allows Locations to be added easily and be allocated on the heap.  Since each of the locations maintain independent state, the game can easily change which location is the ‘current’ one, and display or update that Location instead.  Do note that there are Player instances in each map, so that a player appears in their last-seen position in a location if they leave it and teleport back.
### Developing a system to keep track of the player’s health across maps:
We solved this problem by allowing Player instances in each location to share some crucial private fields, such as health.  Whenever a Player instance takes damage, the health shared by all Players is decreased appropriately.
### Implementing Character interactions between Characters in a Grid
Causing the behaviour of interactions to depend on the type of both characters in the interaction:
We solved this problem by using something similar to **Visitor Pattern**; when a character attempts to make its move onto a tile, if another character is standing on that tile, an interaction occurs.  The source of the interaction is passed to the occupant of the tile, whose appropriate ‘notify’ method is called based on the type of the source.  By doing this, we do things like prevent enemies from attacking other enemies, but coupling also increases since more classes need to be aware of all of the Characters

### Designing Conversations for NPCs and taking them as input
We wanted conversations to have multiple possibilities, and be available as input, so we used a style of taking in tree-like input similar to that of compiler-oriented courses, such as CS 241.  At each node, we signify the number of children and recursively take information in for each child.
### Creating different kinds of difficulty dynamically based on arguments passed by the user at runtime:
To solve this, we used the **Factory method pattern** - To develop levels in the game by creating three kinds of enemies dynamically at run time based on user input. Easy level creates enemies that do only 5 points damage. Medium level creates enemies that do 10 points damage. Hard level creates enemies that do 20 points damage.
## Resilience to Change
One of the key features of our game is that the following components of the game could be changed without any recompilation:

- **Location:** The maps for all current locations (mc, tatham, california) are all present in the .in files. This allows us to change the layout of any of the location. Also, we can easily extend the number of locations from three to an arbitrary number, but that requires a single line of code to be changed. 
- **Character:** Users can modify the .in files to enter any number and type of characters in the location and also specify their position in the map. The text of the conversations and interviews trees is also stored in files, which can be changed. This allows us to design the game however we like as we can make it harder and easier and have customizable interactions without ever having to recompile the code. 


We design our project to accommodate the following anticipated changes:


- We employed the MVC pattern to handle the different kinds of controllers, models, and views that could be potentially added to the project. The model is able to take many controllers and views and this allows us to customize our display with various combinations of these views and controllers. For example, if there is a better graphics library or a new console, then it could easily become a new view or controller respectively.
- We could add locations and add/decrease the number of levels as required by the client since we employ the Factory Design Pattern and we can generate customized Enemies with different damages. 

## Changes to the original plan
We made the following changes to the original plan:

- MVC: We decided that the best way to support multiple views (text-based and graphic) and different controllers was to use the MVC architecture rather than having Game manage both of them as we initially planned. This is because in our case, it would be difficult to extend Game to include other views and controllers. Also, we wanted Game to have single responsibility of managing model which would help us with the scenarios where the game needs to end (such as when player dies or fails the interview). We think keep Game in the original manner would have made it complicated to work and debug.
- As discussed above, a major challenge of this project was to figure out the interactions between Player and other characters. Our first reaction was to use Subject-Observer pattern, but then the Player needed to inherit from multiple classes, since it is already a Combatant. Therefore, it made more sense to us to use the visitor’s pattern as that would allow the player to visit the tiles and achieve appropriate interaction based on the type of occupant of that tile. 
- We added Interview and Interview Conversation because we found out that this helped us store our conversation. 


## Extra Credit Features
- **Graphics:** We employed inheritance to achieve different levels of input based on run time user input as command line arguments. The default view is the standard view, which does not need any argument. We achieved a graphical display using XWindow, which can be used by the “graphic” argument. 
- **Memory Management:** We managed the memory by using smart pointers and vectors. We only have a single delete in our whole program (that too only for the XWindow program that we used from class) and we only use raw pointers that are not meant to express ownership.
## Final Remarks


### What lessons did this project teach you about developing software in teams? If you worked alone, what lessons did you learn about writing large programs?

We found out that modularity, continuous integration, and frequent communication are the three key success factors for developing software in teams. First, the code needs to be modular enough and loosely coupled such that developers can work on the individual components based on client specification. This, along with frequent merges, lead to few code conflicts and easy integrations, which evenly distributed our workload throughout the project term. We learnt that highly coupled classes can be hard to extend and make changes to later on. Hence, we should try to make sure that the classes are designed as not be dependent on each other a lot. 


### What would you have done differently if you had the chance to start over?

We did not anticipate the incompatibility between the conversation and view classes. We would have redesigned our conversation and view classes and made client specifications clearer for better communication between these modules. We also realized later that conversation and interviews share a lot of code and we could possibly use inheritance there. We also experienced a lot of inadvertent coupling during the process of development between our NPC and Location classes. So we could have broken it down and made them less coupled. 
## Conclusion
In conclusion, for this project, we created a game where a UW student tries to find his/her way to California. They player interacts with interview questions, geese and other non-player-characters such as the interviewer. In this project, we used the **Visitor Design Pattern**, as well as, the **Factory Design Pattern**. In this project, we made certain changes to the original plan. These changes include using the MVC (Model View Controller) architecture & also, change the original Subject-Observer pattern & replace it with better methods. As for extra features, we created a graphical display; we also used smart pointers & vectors for more efficient memory management.

