#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>

#include <iostream>
#include <string>

class Renderer {
 private:
  SDL_Window* window;
  SDL_Renderer* renderer;
  int cellSize = 10;
  int offsetX = 0, offsetY = 0;
  bool showGrid = false;
  bool dragging = false;
  int lastMouseX, lastMouseY;
  GameOfLife& game;

 public:
  Renderer(GameOfLife& g) : game(g) {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  }

  ~Renderer() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
  }

  void updateTitle(bool paused, int speed) {
    std::string title = "Speed: " + std::to_string(speed) + "ms | Zoom: " + std::to_string(cellSize) + "px | ";
    title += paused ? "Paused" : "Running";
    title += showGrid ? " | Grid ON" : " | Grid OFF";
    SDL_SetWindowTitle(window, title.c_str());
  }

  void render(bool paused, int speed) {
    updateTitle(paused, speed);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    if (showGrid) {
      SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
      for (int x = 0; x < 800; x += cellSize) {
        SDL_RenderDrawLine(renderer, x + offsetX % cellSize, 0, x + offsetX % cellSize, 600);
      }
      for (int y = 0; y < 600; y += cellSize) {
        SDL_RenderDrawLine(renderer, 0, y + offsetY % cellSize, 800, y + offsetY % cellSize);
      }
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (const auto& cell : game.getCells()) {
      SDL_Rect rect{(cell.get_x() * cellSize) + offsetX, (cell.get_y() * cellSize) + offsetY, cellSize, cellSize};
      SDL_RenderFillRect(renderer, &rect);
    }

    SDL_RenderPresent(renderer);
  }

  bool handleEvent(SDL_Event& event, bool& running, bool& paused, int& speed) {
    if (event.type == SDL_QUIT) {
      running = false;
      return true;
    }
    if (event.type == SDL_KEYDOWN) {
      switch (event.key.keysym.sym) {
        case SDLK_SPACE:
          paused = !paused;
          break;
        case SDLK_r:
          game.reset();
          break;
        case SDLK_g:
          showGrid = !showGrid;
          break;
        case SDLK_PLUS:
        case SDLK_KP_PLUS:
          if (speed > 10) speed -= 10;
          break;
        case SDLK_MINUS:
        case SDLK_KP_MINUS:
          if (speed < 500) speed += 10;
          break;
      }
    }
    if (event.type == SDL_MOUSEWHEEL) {
      if (event.wheel.y > 0 && cellSize < 50) cellSize += 1;
      if (event.wheel.y < 0 && cellSize > 5) cellSize -= 1;
    }
    if (event.type == SDL_MOUSEBUTTONDOWN) {
      int x, y;
      SDL_GetMouseState(&x, &y);
      if (event.button.button == SDL_BUTTON_LEFT) {
        int gridX = (x - offsetX) / cellSize;
        int gridY = (y - offsetY) / cellSize;
        game.toggleCell(gridX, gridY);
      } else if (event.button.button == SDL_BUTTON_RIGHT) {
        dragging = true;
        lastMouseX = x;
        lastMouseY = y;
      }
    }
    if (event.type == SDL_MOUSEBUTTONUP) {
      if (event.button.button == SDL_BUTTON_RIGHT) {
        dragging = false;
      }
    }
    if (event.type == SDL_MOUSEMOTION && dragging) {
      int x, y;
      SDL_GetMouseState(&x, &y);
      offsetX += x - lastMouseX;
      offsetY += y - lastMouseY;
      lastMouseX = x;
      lastMouseY = y;
    }
    return false;
  }
};

#endif  // RENDER_H
