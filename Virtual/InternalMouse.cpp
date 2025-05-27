#include "InternalMouse.h"

InternalMouse::InternalMouse(int startingRobotPosition[2],
                             char startingRobotDirection, int mazeNumRows,
                             int mazeNumCols)
    : currentRobotPosition(startingRobotPosition),
      currentRobotDirection(startingRobotDirection)
{
  // Vector of (# of rows) copies of (vectors of (# of cols) maze cells).
  cellMaze = std::vector<std::vector<MazeGrid*>>(
      mazeNumCols, std::vector<MazeGrid*>(mazeNumRows));

  setUpIMMaze();
}

void InternalMouse::setUpIMMaze() {
  // Formatted as (x, y); x = column, y = row number.
  for (int col = 0; col < cellMaze.size(); col++) {
    for (int row = 0; row < cellMaze[0].size(); row++) {
      cellMaze[col][row] = new MazeGrid(col, row);
    }
  }
}

InternalMouse::~InternalMouse() {
  // Deletes all cell objects in the maze.
  for (int col = 0; col < cellMaze.size(); col++) {
    for (int row = 0; row < cellMaze[0].size(); row++) {
      delete cellMaze[col][row];
    }
  }
}

void InternalMouse::moveIMForwardOneCell(int cellNumberToMoveForward) {

}
void InternalMouse::turnIM45DegreeStepsRight(int halfStepsRight) {}
