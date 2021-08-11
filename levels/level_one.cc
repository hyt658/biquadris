#include "level_one.h"
#include "level.h"

Level1::Level1(int n): Level{n} {}

Block* Level1::createCertainBlock(std::string type, Observer* board) {
    Block *NB;
    if (type == I) {
        NB = new IBlock(heavy);
    } else if (type == J) {
        NB = new JBlock(heavy);
    } else if (type == L) {
        NB = new LBlock(heavy);
    } else if (type == O) {
        NB = new OBlock(heavy);
    } else if (type == S) {
        NB = new SBlock(heavy);
    } else if (type == T) {
        NB = new TBlock(heavy);
    } else if (type == Z) {
        NB = new ZBlock(heavy);
    }
    NB->attach(board);
    return NB;
}

Block* Level1::createRandBlock(Observer* board) {
    int ranum = rand() % (12-1+1) + 1;   // rand num in [1, 12]
    Block *NB;
    if (ranum == 3 || ranum == 4) {
        NB = createCertainBlock(I, board);
    } else if (ranum == 5 || ranum == 6) {
        NB = createCertainBlock(J, board);
    } else if (ranum == 7 || ranum == 8) {
        NB = createCertainBlock(L, board);
    } else if (ranum == 9 || ranum == 10) {
        NB = createCertainBlock(O, board);
    } else if (ranum == 1) {
        NB = createCertainBlock(S, board);
    } else if (ranum == 11 || ranum == 12) {
        NB = createCertainBlock(T, board);
    } else if (ranum == 2) {
        NB = createCertainBlock(Z, board);
    }
    return NB;
}
