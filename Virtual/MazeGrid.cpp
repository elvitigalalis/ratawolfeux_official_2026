#include "MazeGrid.h"

#include <cctype>

MazeGrid::MazeGrid(int mazeXPos, int mazeYPos)
    : mazeXPos(mazeXPos), mazeYPos(mazeYPos) {}

void MazeGrid::addWallInDirection(char NESWdirection) {
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

void MazeGrid::setThereIsWall(char NESWdirection) {
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

int MazeGrid::getCellXPos() { return mazeXPos; }
int MazeGrid::getCellYPos() { return mazeYPos; }

bool MazeGrid::getCellIsExplored() { return cellIsExplored; }
void MazeGrid::markAsExplored() { cellIsExplored = true; }