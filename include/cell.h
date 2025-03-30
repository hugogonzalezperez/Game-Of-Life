#ifndef CELL_H
#define CELL_H

#include <functional>

class Cell {
 public:
  Cell(int x, int y) : x_(x), y_(y) {}

  int get_x() const { return x_; }
  int get_y() const { return y_; }

  bool operator==(const Cell& other) const { return x_ == other.get_x() && y_ == other.get_y(); }

 private:
  int x_, y_;
};

namespace std {
template <>
struct hash<Cell> {
  size_t operator()(const Cell& c) const {
    return hash<int>()(c.get_x()) ^ (hash<int>()(c.get_y()) << 1);
  }
};
}  // namespace std

#endif  // CELL_H
