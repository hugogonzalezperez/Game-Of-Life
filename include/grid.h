#ifndef GRID_H
#define GRID_H

#include <unordered_map>
#include <unordered_set>

#include "./cell.h"

class GameOfLife {
 public:
  void toggleCell(int x, int y) {
    Cell c{x, y};
    if (aliveCells.count(c))
      aliveCells.erase(c);
    else
      aliveCells.insert(c);
  }

  void reset() {
    aliveCells.clear();
  }

  void step() {
    std::unordered_set<Cell> newAliveCells;
    std::unordered_map<Cell, int> neighborCount;

    for (const auto& cell : aliveCells) {
      for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
          if (dx == 0 && dy == 0) continue;
          Cell neighbor{cell.get_x() + dx, cell.get_y() + dy};
          neighborCount[neighbor]++;
        }
      }
    }

    for (const auto& [cell, count] : neighborCount) {
      if (count == 3 || (count == 2 && aliveCells.count(cell)))
        newAliveCells.insert(cell);
    }

    aliveCells = std::move(newAliveCells);
  }

  const std::unordered_set<Cell>& getCells() const { return aliveCells; }

 private:
  std::unordered_set<Cell> aliveCells;
};

#endif  // GRID_H