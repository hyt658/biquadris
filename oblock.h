#ifndef __OBLOCK_H__
#define __OBLOCK_H__
#include "block.h"
#include <string>

using std::vector;

class OBlock:public Block {
    public:
        OBlock(bool isheavy);
        virtual void rotate(bool clockwise, vector<vector<Cell>> board) override;
        void notify(int n=0, int m=0) override;
};

#endif