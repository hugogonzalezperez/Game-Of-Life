#include "../include/grid.h"
#include "../include/render.h"

const int WIDTH = 600;
const int HEIGHT = 600;

int main() {
  GameOfLife game;
  Renderer renderer(game);

  bool running = true, paused = true;
  int speed = 100;  // milisegundos entre pasos
  SDL_Event event;

  while (running) {
    while (SDL_PollEvent(&event)) {
      renderer.handleEvent(event, running, paused, speed);
    }

    if (!paused) game.step();
    renderer.render(paused, speed);
    SDL_Delay(speed);
  }

  return 0;
}