#ifndef __ZBLOCK_H__
#define __ZBLOCK_H__
#include "block.h"
#include <string>

using std::vector;

class ZBlock:public Block {
    public:
        ZBlock(bool heavy1, bool heavy2, int lv);
        virtual bool rotate(bool clockwise, vector<vector<Cell>> board, int multiplier) override;
};

#endif
