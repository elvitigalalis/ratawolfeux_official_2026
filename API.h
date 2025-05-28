#ifndef API_H
#define API_H

#include <Robot/Drivetrain.h>
#include <Virtual/InternalMouse.h>

#include <string>
class API {
 public:
  API(Drivetrain* drivetrain, InternalMouse* internalMouse,
      bool runOnSimulator = false);
  ~API();

  int mazeWidth();
  int mazeHeight();

  bool wallLeft();
  bool wallFront();
  bool wallRight();

  void moveForwardHalf();
  void moveForward();
  void moveForward(int steps);

  void turnLeft45();
  void turnLeft90();
  void turnRight45();
  void turnRight90();
  void turn(int degreesDivisibleBy45);

  void setWall(int x, int y, const std::string& direction);
  void clearWall(int x, int y, const std::string& direction);

  void setColor(int x, int y, char color);
  void clearColor(int x, int y);
  void clearAllColor();

  void setText(int x, int y, const std::string& text);
  void clearText(int x, int y);
  void clearAllText();

 private:
  Drivetrain* drivetrain;
  InternalMouse* internalMouse;
  bool runOnSimulator;

  std::string getSimulatorResponse(std::string commandUsed);
  int getSimulatorIntegerResponse(std::string commandUsed);
  bool getSimulatorBoolResponse(std::string commandUsed);
};
#endif