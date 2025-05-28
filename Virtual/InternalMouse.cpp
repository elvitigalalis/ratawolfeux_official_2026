#include "InternalMouse.h"

InternalMouse::InternalMouse(std::array<int, 2> startingRobotPosition,
                             std::string startingRobotDirection,
                             MazeGraph* mazeGraph)
    : currentRobotPosition(startingRobotPosition),
      currentRobotDirection(startingRobotDirection),
      mazeGraph(mazeGraph) {}

void InternalMouse::moveIMForwardOneCell(int cellNumberToMoveForward) {
  std::array<int, 2> directionOffsetToAdd =
      directionStringToOffsetArrayMap.at(currentRobotDirection);
  currentRobotPosition[0] += directionOffsetToAdd[0];
  currentRobotDirection[1] += directionOffsetToAdd[1];
}

void InternalMouse::turnIM45DegreeStepsRight(int halfStepsRight) {
  currentRobotDirection =
      getNewDirectionAfterAddingHalfStepsRight(halfStepsRight);
}

int InternalMouse::indexOfDirection(std::string direction) {
  for (int i = 0; i < possibleDirections.size(); i++) {
    if (possibleDirections[i] == direction) {
      return i;
    }
  }

  return -1;
}

std::string InternalMouse::getNewDirectionAfterAddingHalfStepsRight(
    int halfStepsRight) {
  if (halfStepsRight == 0) return currentRobotDirection;

  int currentDirectionIndex = indexOfDirection(currentRobotDirection);

  // Adding one to index = turning right half step in cardinal directions.
  int newDirectionIndex =
      (currentDirectionIndex + halfStepsRight) % possibleDirections.size();

  return possibleDirections[newDirectionIndex];
}

void InternalMouse::setWallExistsLFR(char LFRdirection) {
  int halfStepsToAdd = 0;
  if (tolower(LFRdirection) == 'l') halfStepsToAdd = -2;
  if (tolower(LFRdirection) == 'r') halfStepsToAdd = 2;

  std::string directionStringToAddWall =
      getNewDirectionAfterAddingHalfStepsRight(halfStepsToAdd);
  std::array<int, 2> directionArrayToAddWall =
      directionStringToOffsetArrayMap.at(directionStringToAddWall);
  MazeNode* currentNode =
      mazeGraph->getNode(currentRobotPosition[0], currentRobotPosition[1]);

  // N
  if (directionArrayToAddWall[1] == 1) currentNode->setWallInDirection('N');
  // E
  if (directionArrayToAddWall[0] == 1) currentNode->setWallInDirection('E');
  // S
  if (directionArrayToAddWall[1] == -1) currentNode->setWallInDirection('S');
  // W
  if (directionArrayToAddWall[0] == -1) currentNode->setWallInDirection('W');
}

void InternalMouse::setWallExistsNESW(char NESWdirection) {
  MazeNode* currentNode =
      mazeGraph->getNode(currentRobotPosition[0], currentRobotPosition[1]);
  currentNode->setWallInDirection(NESWdirection);
}

int InternalMouse::getMazeWidth() { return mazeGraph->getMazeWidth(); }

int InternalMouse::getMazeHeight() { return mazeGraph->getMazeHeight(); }