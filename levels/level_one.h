#ifndef __LEVEL_ONE_H__
#define __LEVEL_ONE_H__
#include "level.h"
#include <string>

class Level1:public Level {
    public:
        Level1(int n);
        Block* createRandBlock(Observer* board) override;
        Block* createCertainBlock(std::string type, Observer* board) override;
};

#endif