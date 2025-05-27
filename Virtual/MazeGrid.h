#ifndef MAZEGRID_H
#define MAZEGRID_H

class MazeGrid {
 public:
  MazeGrid(int mazeXPos, int mazeYPos);
  ~MazeGrid();

  void addWallInDirection(char NESWdirection);

  int getCellXPos();
  int getCellYPos();

  bool getCellIsExplored();
  void markAsExplored();

 private:
  void setThereIsWall(char NESWdirection);

  int mazeXPos, mazeYPos;
  MazeGrid* NCell;
  MazeGrid* ECell;
  MazeGrid* SCell;
  MazeGrid* WCell;
  bool isThereNWall, isThereEWall, isThereSWall, isThereWWall;
  bool cellIsExplored;
};

#endif