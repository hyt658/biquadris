#include "level_two.h"

Level2::Level2(int n): Level{n, false} {}

shared_ptr<Block> Level2::createCertainBlock(std::string type, Observer* board) {
    shared_ptr<Block> NB;
    if (type == "I") {
        NB = make_shared<IBlock> (lv_heavy, debuff_heavy, 2);
    } else if (type == "J") {
        NB = make_shared<JBlock> (lv_heavy, debuff_heavy, 2);
    } else if (type == "L") {
        NB = make_shared<IBlock> (lv_heavy, debuff_heavy, 2);
    } else if (type == "O") {
        NB = make_shared<OBlock> (lv_heavy, debuff_heavy, 2);
    } else if (type == "S") {
        NB = make_shared<SBlock> (lv_heavy, debuff_heavy, 2);
    } else if (type == "T") {
        NB = make_shared<TBlock> (lv_heavy, debuff_heavy, 2);
    } else if (type == "Z") {
        NB = make_shared<ZBlock> (lv_heavy, debuff_heavy, 2);
    }
    NB->attach(board);
    return NB;
}

shared_ptr<Block> Level2::createRandBlock(Observer* board) {
    int ranum = rand() % (7-1+1) + 1;   // rand num in [1, 7]
    shared_ptr<Block> NB;
    if (ranum == 1) {
        NB = createCertainBlock("I", board);
    } else if (ranum == 2) {
        NB = createCertainBlock("J", board);
    } else if (ranum == 3) {
        NB = createCertainBlock("L", board);
    } else if (ranum == 4) {
        NB = createCertainBlock("O", board);
    } else if (ranum == 5) {
        NB = createCertainBlock("S", board);
    } else if (ranum == 6) {
        NB = createCertainBlock("T", board);
    } else if (ranum == 7) {
        NB = createCertainBlock("Z", board);
    }
    return NB;
}