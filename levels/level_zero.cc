#include "level_zero.h"
#include <fstream>
using namespace std;

Level0::Level0(int n, string path): Level{n}, path{path}, count{0} {
   (this->infile).open(this->path);
}

Block* Level0::createCertainBlock(std::string type, Observer* board) {
   Block *NB;
   if (type == I) {
      Block *NB = new IBlock(false);
   } else if (type == J) {
      Block *NB = new JBlock(false);
   } else if (type == L) {
      Block *NB = new LBlock(false);
   } else if (type == O) {
      Block *NB = new OBlock(false);
   } else if (type == S) {
      Block *NB = new SBlock(false);
   } else if (type == T) {
      Block *NB = new TBlock(false);
   } else if (type == Z) {
      Block *NB = new ZBlock(false);
   } else {
      throw("WRONG COMMAND");
   }
   NB->attach(board);
   return NB;
}

Block* Level0::createRandBlock(Observer* board) {
   string next;
   infile >> next;
   Block *NB;
   NB = createCertainBlock(next, board);
   return NB;
}