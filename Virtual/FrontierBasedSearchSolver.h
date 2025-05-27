#ifndef FRONTIERBASEDSEARCHSOLVER_H
#define FRONTIERBASEDSEARCHSOLVER_H

#include "../API.h"

class FrontierBasedSearchSolver {
 public:
  FrontierBasedSearchSolver(API api);
  ~FrontierBasedSearchSolver();

  void solveMaze();
 private:
};

#endif