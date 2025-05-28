#include "MazeNode.h"

#include <cctype>

MazeNode::MazeNode(int mazeXPos, int mazeYPos)
    : mazeXPos(mazeXPos), mazeYPos(mazeYPos) {}

void MazeNode::addWallInDirection(char NESWdirection) {
  switch (tolower(NESWdirection)) {
    // Adds shared walls between two cells.
    case 'n':
      setThereIsWall('n');
      if (NCell != nullptr) NCell->setThereIsWall('s');

    case 'e':
      setThereIsWall('e');
      if (ECell != nullptr) ECell->setThereIsWall('w');

    case 's':
      setThereIsWall('s');
      if (SCell != nullptr) SCell->setThereIsWall('n');

    case 'w':
      setThereIsWall('w');
      if (WCell != nullptr) WCell->setThereIsWall('e');
  }
}

bool MazeNode::getIsWall(char NESWdirection) {
  switch (tolower(NESWdirection)) {
    case 'n':
      return isThereNWall;
    case 'e':
      return isThereEWall;
    case 's':
      return isThereSWall;
    case 'w':
      return isThereWWall;
  }
}

void MazeNode::setThereIsWall(char NESWdirection) {
  switch (tolower(NESWdirection)) {
    case 'n':
      isThereNWall = true;
    case 'e':
      isThereEWall = true;
    case 's':
      isThereSWall = true;
    case 'w':
      isThereWWall = true;
  }
}

void MazeNode::setCellInDirection(MazeNode* node, char NESWdirection) {
  switch (tolower(NESWdirection)) {
    case 'n':
      NCell = node;
    case 'e':
      ECell = node;
    case 's':
      SCell = node;
    case 'w':
      WCell = node;
  }
}

int MazeNode::getCellXPos() { return mazeXPos; }
int MazeNode::getCellYPos() { return mazeYPos; }

bool MazeNode::getCellIsExplored() { return cellIsExplored; }
void MazeNode::markAsExplored() { cellIsExplored = true; }