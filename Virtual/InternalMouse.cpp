#include "InternalMouse.h"

#include <map>

InternalMouse::InternalMouse(std::array<int, 2> startingRobotPosition,
                             std::string startingRobotDirection)
    : currentRobotPosition(startingRobotPosition),
      currentRobotDirection(startingRobotDirection) {}

void InternalMouse::moveIMForwardOneCell(int cellNumberToMoveForward) {
  std::array<int, 2> directionOffsetToAdd =
      directionStringToOffsetArrayMap.at(currentRobotDirection);
  currentRobotPosition[0] += directionOffsetToAdd[0];
  currentRobotDirection[1] += directionOffsetToAdd[1];
}

void InternalMouse::turnIM45DegreeStepsRight(int halfStepsRight) {
  int currentDirectionIndex = indexOfDirection(currentRobotDirection);

  // Adding one to index = turning right half step in cardinal directions.
  int newDirectionIndex =
      (currentDirectionIndex + halfStepsRight) % possibleDirections.size();

  currentRobotDirection = possibleDirections[newDirectionIndex];
}

int InternalMouse::indexOfDirection(std::string direction) {
  for (int i = 0; i < possibleDirections.size(); i++) {
    if (possibleDirections[i] == direction) {
      return i;
    }
  }

  return -1;
}
