# Catch-the-Ball-game

# Catch The Falling Balls 🏀

A classic, simple 2D arcade game developed in C++ using the Simple Graphics Gateway (SGG) library. The player controls a net/basket to catch falling balls and increase their score, while avoiding letting too many balls fall off the screen.

## 🚀 Features

* **Simple Gameplay**: Move the player horizontally to catch falling objects.
* **Dynamic Difficulty**: The speed of the falling balls increases gradually over time.
* **Game States**: Includes a Start Screen and Game Over screen.
* **Collision Detection**: Basic AABB (Axis-Aligned Bounding Box) collision logic is implemented to detect when a ball is caught.
* **Game Over Condition**: The game ends if a predefined number of balls (currently 7) are missed.
* **Audio**: Includes sound effects (Game Over) and background music (Start Screen).

## 💻 Tech Stack

* **Language**: C++
* **Graphics Library**: Simple Graphics Gateway (SGG)
* **Development Environment**: Microsoft Visual Studio 2022
* **Platform**: Windows 

## 🛠️ Setup and Installation

This project is configured as a Visual Studio solution. To build and run the game, you will need a Windows environment with Visual Studio installed.

### Prerequisites

1.  **Visual Studio:** Ensure you have Visual Studio (e.g., 2022) with C++ development tools installed.
2.  **SGG Library:** The project relies on the external `sgg.lib` (Release) and `sggd.lib` (Debug) files and the associated header files.
    * Place the SGG header files in a directory named `include` at the solution level.
    * Place the SGG library files (`.lib`) in a directory named `lib` at the solution level.

### Build Instructions

1.  **Clone the Repository:**
    ```bash
    git clone [YOUR_REPOSITORY_URL]
    ```
2.  **Open the Solution:** Open the `Ergasia.vcxproj` file in Visual Studio.
3.  **Set Configuration:** Select the desired configuration (`Debug` or `Release`) and platform (`x64`).
4.  **Build:** Right-click the project in the Solution Explorer and select **Build**.
5.  **Run:** The executable will be placed in the `bin` directory within your solution folder, as specified by the project settings.

## 📝 Code Structure Overview

| File | Description |
| :--- | :--- |
| `main.cpp` | Initializes the SGG graphics window, sets up the game loop (`update`, `draw`), and initializes the global `GameState` singleton. |
| `gamestate.h`/`.cpp` | **Core Game Manager (Singleton).** Handles game flow (Start/Playing/Game Over), global settings (canvas size: 6x6 units), managing the list of active `Ball` objects, and the game over logic. |
| `gameobject.h`/`.cpp` | The base class for all game entities (`Player`, `Ball`, `Level`). Provides virtual methods for `init`, `update`, and `draw`. |
| `player.h`/`.cpp` | Manages the player's movement (horizontal control via Left/Right arrows) and drawing of the basket/net (`net.png`). Inherits from `GameObject` and `Box`. |
| `ball.h`/`.cpp` | Manages the falling objects. Includes movement logic (gravity/speed) and collision checking against the `Player`. |
| `box.h` | Defines a simple `Box` struct used for collision detection, including `intersect`, `intersectDown`, and `intersectSideways` methods. |
| `level.h`/`.cpp` | Manages the background (`background.png`) and acts as a container for static/dynamic objects. **Note:** The main ball spawning logic is managed by `GameState.cpp`. |
| `assets/` | Directory containing game resources (images and sound files). |

## 🕹️ How To Play

1.  Start the game. The home screen will appear.
2.  Press **ENTER** to start playing.
3.  Use the **Left Arrow** and **Right Arrow** keys to move the player horizontally.
4.  Catch the falling balls to increase your score.
5.  If you miss 7 balls, the game ends.
6.  Press **ENTER** again on the Game Over screen to restart.
