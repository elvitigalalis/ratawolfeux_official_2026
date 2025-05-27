#ifndef ASTARSOLVER_H
#define ASTARSOLVER_H

#include "../API.h"

class AStarSolver {
 public:
  AStarSolver(API api);
  ~AStarSolver();

  void solveMaze();
 private:
};

#endif