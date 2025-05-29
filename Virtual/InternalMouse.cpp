#include "InternalMouse.h"

InternalMouse::InternalMouse(std::array<int, 2> startingRobotPosition,
                             std::string startingRobotDirection,
                             std::vector<std::array<int, 2>> goalCells,
                             MazeGraph* mazeGraph)
    : currentRobotPosition(startingRobotPosition),
      currentRobotDirection(startingRobotDirection),
      goalCells(goalCells),
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
  MazeNode* currentNode = getCurrentRobotNode();
  // N
  if (directionArrayToAddWall[1] == 1) currentNode->setWallInDirection('N');
  // E
  if (directionArrayToAddWall[0] == 1) currentNode->setWallInDirection('E');
  // S
  if (directionArrayToAddWall[1] == -1) currentNode->setWallInDirection('S');
  // W
  if (directionArrayToAddWall[0] == -1) currentNode->setWallInDirection('W');
}

MazeNode* InternalMouse::getCurrentRobotNode() {
  return mazeGraph->getNode(currentRobotPosition[0], currentRobotPosition[1]);
}

void InternalMouse::setWallExistsNESW(char NESWdirection) {
  MazeNode* currentNode = getCurrentRobotNode();
  currentNode->setWallInDirection(NESWdirection);
}

std::vector<MazeNode*> InternalMouse::getNodeNeighbors(
    MazeNode* node, bool includeDiagNeighbors) {
  return mazeGraph->getNodeNeighbors(node, includeDiagNeighbors);
}

bool InternalMouse::getCanMoveBetweenNodes(MazeNode* from, MazeNode* to,
                                           bool diagonalsAllowed) {
  int diffX = to->getCellXPos() - from->getCellXPos();
  int diffY = to->getCellYPos() - from->getCellYPos();

  // Disallow diagonals if not allowed.
  if (diffX == 0 && diffY == 1) return !from->getIsWall('N');
  if (diffX == 1 && diffY == 0) return !from->getIsWall('E');
  if (diffX == 0 && diffY == -1) return !from->getIsWall('S');
  if (diffX == -1 && diffY == 0) return !from->getIsWall('W');

  // Check if diagonal movement is allowed.
  int fromXPos = from->getCellXPos(), fromYPos = from->getCellYPos();

  if (diagonalsAllowed) {
    if (diffX == 1 && diffY == 1)
      return !from->getIsWall('N') &&
             !mazeGraph->getNode(fromXPos, fromYPos + 1)->getIsWall('E');
    if (diffX == -1 && diffY == 1)
      return !from->getIsWall('N') &&
             !mazeGraph->getNode(fromXPos, fromYPos + 1)->getIsWall('W');
    if (diffX == 1 && diffY == -1)
      return !from->getIsWall('S') &&
             !mazeGraph->getNode(fromXPos, fromYPos - 1)->getIsWall('E');
    if (diffX == -1 && diffY == -1)
      return !from->getIsWall('S') &&
             !mazeGraph->getNode(fromXPos, fromYPos - 1)->getIsWall('W');
  }

  return false;
}

bool InternalMouse::isAGoalCell(MazeNode* node) {
  for (std::array<int, 2> goalCell : goalCells) {
    if (MazeNode::areNodesEqual(node,
                                mazeGraph->getNode(goalCell[0], goalCell[1]))) {
      return true;
    }
  }
  return false;
}

void InternalMouse::resetSolverVariables() {
  for (int col = 0; col < getMazeWidth(); col++) {
    for (int row = 0; row < getMazeHeight(); row++) {
      mazeGraph->getNode(col, row)->clearParentAndProcessed();
    }
  }
}

int InternalMouse::getMazeWidth() { return mazeGraph->getMazeWidth(); }

int InternalMouse::getMazeHeight() { return mazeGraph->getMazeHeight(); }