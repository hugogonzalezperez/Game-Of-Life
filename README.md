# Game-Of-Life

This project is an implementation of John Conway's famous **Game of Life** in C++ using the **SDL2** library for rendering the simulation. The Game of Life is a cellular automaton that simulates the evolution of a set of live cells on a grid, following simple rules that produce complex and fascinating patterns.

## Features

- Simulation of the Game of Life with standard rules.
- Interactive graphical interface using **SDL2**.
- Simulation control via keyboard and mouse.
- Options to pause, reset, adjust speed, zoom, and show/hide the grid.

## Controls

| Key/Action           | Function                                                               |
|----------------------|-------------------------------------------------------------------------|
| **Space**           | Pause/Resume the simulation.                                          |
| **R**               | Reset the simulation (clear all live cells).                          |
| **G**               | Show/Hide the grid.                                                   |
| **+ / Numeric keypad +** | Increase simulation speed (decrease interval).                     |
| **- / Numeric keypad -** | Decrease simulation speed (increase interval).                     |
| **Mouse wheel**     | Zoom in/out.                                                           |
| **Left click**      | Activate/Deactivate a cell on the grid.                               |
| **Right click + drag** | Move the grid.                                                     |

## Technologies Used

- **C++20**: Programming language used to implement the game logic.
- **SDL2**: Library for graphics and event handling.
- **SDL2_image**: SDL2 extension for handling images.
- **SDL2_ttf**: SDL2 extension for handling fonts.

## Installation

### Prerequisites

Make sure you have the following tools and libraries installed on your system:

1. **C++ compiler** compatible with C++20 (such as `g++`).
2. **SDL2** and its extensions:
   - `libsdl2-dev`
   - `libsdl2-image-dev`
   - `libsdl2-ttf-dev`

On Debian/Ubuntu-based systems, you can install them with:

```bash
sudo apt update
sudo apt install g++ make libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev
```

## Clone Repository
To run this repository on your local machine, use the following command:
```bash
git clone git@github.com:hugogonzalezperez/Game-Of-Life.git
cd Game-Of-Life
```

## Compile and Run

### Compilation
Compile the project using the included makefile:
```bash
make
```
This will generate the executable in the `bin/` directory with the name `GameOfLife`.

### Execution
Run the program with:
```bash
./bin/GameOfLife
```

## Usage

1. When the program starts, a window will open with the Game of Life grid.
2. Use the controls mentioned in the table above to interact with the simulation.
3. You can pause the simulation, add live cells, adjust speed, zoom, and more.

