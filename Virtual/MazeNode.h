#ifndef MAZENODE_H
#define MAZENODE_H

class MazeNode {
 public:
  MazeNode(int mazeXPos, int mazeYPos);
  ~MazeNode();

  void addWallInDirection(char NESWdirection);
  void markAsExplored();

  int getCellXPos();
  int getCellYPos();
  bool getCellIsExplored();
  bool getIsWall(char NESWdirection);

  void setCellInDirection(MazeNode* node, char NESWdirection);

 private:
  void setThereIsWall(char NESWdirection);

  int mazeXPos, mazeYPos;
  MazeNode* NCell;
  MazeNode* ECell;
  MazeNode* SCell;
  MazeNode* WCell;
  bool isThereNWall, isThereEWall, isThereSWall, isThereWWall;
  bool cellIsExplored;
};

#endif