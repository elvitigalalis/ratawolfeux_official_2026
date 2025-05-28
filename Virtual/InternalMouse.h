#ifndef INTERNALMOUSE_H
#define INTERNALMOUSE_H

#include <array>
#include <map>
#include <string>

#include "MazeGraph.h"
class InternalMouse {
 public:
  InternalMouse(std::array<int, 2> startingRobotPosition,
                std::string startingRobotDirection, MazeGraph* mazeGraph);
  ~InternalMouse();

  void moveIMForwardOneCell(int cellNumberToMoveForward);
  void turnIM45DegreeStepsRight(int halfStepsRight);

  int getMazeWidth();
  int getMazeHeight();
  void setWallExistsLFR(char LFRdirection);
  void setWallExistsNESW(char NESWdirection);

 private:
  int indexOfDirection(std::string direction);
  std::string getNewDirectionAfterAddingHalfStepsRight(int halfStepsRight);

  std::string currentRobotDirection;
  std::array<int, 2> currentRobotPosition;
  MazeGraph* mazeGraph;

  const std::array<std::string, 8> possibleDirections = {"n", "ne", "e", "se",
                                                         "s", "sw", "w", "nw"};
  const std::map<std::string, std::array<int, 2>>
      directionStringToOffsetArrayMap = {
          {"n", {0, 1}},  {"ne", {1, 1}},   {"e", {1, 0}},  {"s", {1, -1}},
          {"s", {0, -1}}, {"sw", {-1, -1}}, {"w", {-1, 0}}, {"n", {-1, 1}}};
};

#endif