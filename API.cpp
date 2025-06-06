#include <API.h>

#include <iostream>
#include <sstream>

API::API(Drivetrain* drivetrain, InternalMouse* internalMouse,
         bool runOnSimulator)
    : drivetrain(drivetrain),
      internalMouse(internalMouse),
      runOnSimulator(runOnSimulator) {}

int API::mazeWidth() { return internalMouse->getMazeWidth(); }

int API::mazeHeight() { return internalMouse->getMazeHeight(); }

bool API::wallLeft() {
  if (runOnSimulator) return getSimulatorBoolResponse("wallLeft");
}
bool API::wallFront() {
  if (runOnSimulator) return getSimulatorBoolResponse("wallFront");
}
bool API::wallRight() {
  if (runOnSimulator) return getSimulatorBoolResponse("wallFront");
}

void API::moveForwardHalf() {
  if (runOnSimulator) getSimulatorResponse("moveForwardHalf");
}
void API::moveForward() {
  if (runOnSimulator) getSimulatorResponse("moveForward");
  internalMouse->moveIMForwardOneCell(1);
}
void API::moveForward(int steps) {
  if (runOnSimulator) {
    std::ostringstream commandStream;
    commandStream << "moveForward" << steps;

    getSimulatorResponse("moveForwardHalf");
  }
  internalMouse->moveIMForwardOneCell(steps);
}

void API::turnLeft45() {
  if (runOnSimulator) getSimulatorResponse("turnLeft45");
  internalMouse->turnIM45DegreeStepsRight(-1);
}
void API::turnLeft90() {
  if (runOnSimulator) getSimulatorResponse("turnLeft");
  internalMouse->turnIM45DegreeStepsRight(-2);
}
void API::turnRight45() {
  if (runOnSimulator) getSimulatorResponse("turnRight45");
  internalMouse->turnIM45DegreeStepsRight(1);
}
void API::turnRight90() {
  if (runOnSimulator) getSimulatorResponse("turnRight");
  internalMouse->turnIM45DegreeStepsRight(2);
}
void API::turn(int degreesDivisibleBy45) {
  int turnsNeeded = (int)(degreesDivisibleBy45 / 45);
  if (runOnSimulator) {
    for (int i = 0; i < abs(turnsNeeded); i++) {
      if (degreesDivisibleBy45 > 0)
        turnRight45();
      else
        turnLeft45();
    }
  }

  internalMouse->turnIM45DegreeStepsRight(turnsNeeded);
}

void API::setWall(int x, int y, const std::string& direction) {
  bool isFourCardinal = direction == "n" || direction == "e" ||
                        direction == "s" || direction == "w";

  bool isNonFourCardinal = direction == "ne" || direction == "se" ||
                           direction == "sw" || direction == "nw";
  if (runOnSimulator) {
    if (isFourCardinal) {
      std::cout << "setWall " << x << " " << y << " " << direction << '\n';
    } else if (isNonFourCardinal) {
      std::cout << "setWall " << x << " " << y << " " << direction[0] << '\n';
      std::cout << "setWall " << x << " " << y << " " << direction[1] << '\n';
    }
  }

  if (isFourCardinal)
    internalMouse->setWallExistsNESW(direction[0]);
  else if (isNonFourCardinal) {
    internalMouse->setWallExistsNESW(direction[0]);
    internalMouse->setWallExistsNESW(direction[1]);
  }
}
void API::clearWall(int x, int y, const std::string& direction) {
  if (runOnSimulator)
    std::cout << "clearWall " << x << " " << y << " " << direction << '\n';

  // FIXME: Add support for next few methods for internal mouse after everything
  // works. Don't overcomplicate now.
}

void API::setColor(int x, int y, char color) {
  if (runOnSimulator)
    std::cout << "setColor " << x << " " << y << " " << color << '\n';
}
void API::clearColor(int x, int y) {
  if (runOnSimulator) std::cout << "clearColor " << x << " " << y << '\n';
}
void API::clearAllColor() {
  if (runOnSimulator) std::cout << "clearAllColor" << '\n';
}

void API::setText(int x, int y, const std::string& text) {
  if (runOnSimulator)
    std::cout << "setText " << x << " " << y << " " << text << '\n';
}
void API::clearText(int x, int y) {
  if (runOnSimulator) std::cout << "clearText " << x << " " << y << '\n';
}
void API::clearAllText() {
  if (runOnSimulator) std::cout << "clearAllText" << '\n';
}

std::string API::getSimulatorResponse(std::string commandUsed) {
  std::cout << commandUsed << '\n';
  std::string simulatorResponse;
  std::getline(std::cin, simulatorResponse);

  return simulatorResponse;
}

int API::getSimulatorIntegerResponse(std::string commmandUsed) {
  return std::stoi(getSimulatorResponse(commmandUsed));
}

bool API::getSimulatorBoolResponse(std::string commandUsed) {
  return getSimulatorResponse(commandUsed) == "true";
}