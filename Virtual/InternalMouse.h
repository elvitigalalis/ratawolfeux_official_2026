#ifndef INTERNALMOUSE_H
#define INTERNALMOUSE_H

#include <vector>

#include "MazeGrid.h"
class InternalMouse {
 public:
  InternalMouse(int startingRobotPosition[2], char startingRobotDirection,
                int mazeNumRows = 16, int mazeNumCols = 16);
  ~InternalMouse();

  void moveIMForwardOneCell(int cellNumberToMoveForward);
  void turnIM45DegreeStepsRight(int halfStepsRight);

 private:
  void setUpIMMaze();

  std::vector<std::vector<MazeGrid*>> cellMaze;
  char currentRobotDirection;
  int* currentRobotPosition;
};

#endif