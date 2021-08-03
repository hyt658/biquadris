#inlcude "tblock.h"
#include "block.h"
#include <vector>

TBlock::TBlock(bool isheavy) {
    vector<int> first;
    first.emplace_back(0);
    first.emplace_back(0);
    locations.emplace_back(first);
    vector<int> second;
    second.emplace_back(0);
    second.emplace_back(1);
    locations.emplace_back(second);
    vector<int> thrid;
    third.emplace_back(0);
    third.emplace_back(2);
    locations.emplace_back(third);
    vector<int> fourth;
    fourth.emplace_back(1);
    fourth.emplace_back(1);
    locations.emplace_back(fourth);
}

void TBlock::rotate(bool clockwise, vector<vector<Cell>> board) {
    if(clockwise) {
        if(locations[0][0] == locations[1][0]) {
            if(locations[0][0] + 1 == locations[1][0]) {
                tryRotate(-1, 1, 0, 0, 1, -1, -1, -1, board);
            }
            else {
                tryRotate(1, -1, 0, 0, -1, 1, 1, 1, board);
            }
        }
        else {
            if(locations[0][1] + 1 == locations[1][1]) {
                tryRotate(-1, 1, 0, 0, 1, 1, 1, -1, board);
            }
            else {
                tryRotate(1, -1, 0, 0, -1, 1, 1, 1, board);
            }
        }
    }
    else {
        if(locations[0][0] == locations[1][0]) {
            if(locations[0][0] + 1 == locations[1][0]) {
                tryRotate(1, -1, 0, 0, -1, 1, 1, 1, board);
            }
            else {
                tryRotate(-1, 1, 0, 0, 1, 1, 1, -1, board);
            }
        }
        else {
            if(locations[0][1] + 1 == locations[1][1]) {
                tryRotate(1, -1, 0, 0, -1, 1, 1, 1, board);
            }
            else {
                tryRotate(-1, 1, 0, 0, 1, -1, -1, -1, board);
            }
        }
    }
}