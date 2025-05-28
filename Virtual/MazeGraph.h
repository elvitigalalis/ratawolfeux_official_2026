#ifndef MAZEGRAPH_H
#define MAZEGRAPH_H

#include <vector>

#include "MazeNode.h"

class MazeGraph {
 public:
  MazeGraph(int mazeNumRows, int mazeNumCols);
  ~MazeGraph();

  MazeNode* getNode(int nodePosX, int nodePosY);
  void printASCIIMaze();

 private:
  void createCellsInMaze();
  void linkNeighboringCellsInMaze();

  std::string stringifyTopMazeEdge();
  std::string stringifyMazeRow(int rowIndex);

  std::vector<std::vector<MazeNode*>> cellMaze;
};

#endif