#ifndef __OBLOCK_H__
#define __OBLOCK_H__
#include "block.h"
#include <string>

using std::vector;

class OBlock:public Block {
    public:
        OBlock(bool heavy1, bool heavy2, int lv);
        virtual bool rotate(bool clockwise, vector<vector<Cell>> board, int multiplier) override;
};

#endif