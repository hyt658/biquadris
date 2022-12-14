#include "block.h"
#include <iostream>

Block::Block(std::string new_type, bool heavy1, bool heavy2, int lv): 
    generateLv{lv}, type{new_type}, level_heavy{heavy1}, debuff_heavy{heavy2} {}

bool Block::contain(int idx, int ver, int hor) {
    for (size_t i = 0; i < locations.size(); i++) {
        if(locations[idx][0]+ver == locations[i][0] && locations[idx][1]+hor == locations[i][1]) {
            return true;
        }
    }
    return false;
}

bool Block::down(vector<vector<Cell>> board, int multiplier) {
    bool moved = false;
    bool success = true;
    for(int m = 0; m < multiplier && success; m++) {
        for (size_t i = 0; i < locations.size(); i++) {
            if (locations[i][0]+1 > 17 || (board[locations[i][0]+1][locations[i][1]].getName() != "empty")) {
                isdropped = true;
                if(!moved) {
                    return moved;
                }
                success = false;
                break;
            }
            else {
                moved = true;
            }
        }
        for (size_t i = 0; i < locations.size() && success; i++) {
            locations[i][0]+=1;
            if (locations[i][0]+1 > 17 || (board[locations[i][0]+1][locations[i][1]].getName() != "empty")) {
                isdropped = true;
            }
        }
    }
    return moved;
}

bool Block::moveRight(vector<vector<Cell>> board, int multiplier) {
    bool movable = true;
    bool moved = false;
    bool success = true;
    for(int i = 0; i < multiplier; i++) {
        for (size_t i = 0; i < locations.size(); i++) {
            if (locations[i][1] >= 10 || board[locations[i][0]][locations[i][1]+1].getName() != "empty") {
                if(!moved) {
                    movable = false;
                    return movable;
                }
                success = false;
                break;
            }
            else {
                moved = true;
            }
        }
        for (size_t i = 0; i < locations.size() && success; i++) {
            locations[i][1]+=1;
        }
    }
    if (level_heavy) {
        down(board, 1);
    }
    if (debuff_heavy) {
        down(board, 2);
    }
    return movable;
}

bool Block::moveLeft(vector<vector<Cell>> board, int multiplier) {
    bool movable = true;
    bool moved = false;
    bool success = true;
    for(int i = 0; i < multiplier; i++) {
        for (size_t i = 0; i < locations.size() && success; i++) {
            if (locations[i][1] < 1 || board[locations[i][0]][locations[i][1]-1].getName() != "empty") {
                if(!moved) {
                   movable = false;
                   return movable;
                }
                success = false;
                break;
            }
            else {
                moved = true;
            }
        }
        for(size_t i = 0; i < locations.size() && success; i++) {
            locations[i][1]-=1;
        }
    }
    if (level_heavy) {
        down(board, 1);
    }
    if (debuff_heavy) {
        down(board, 2);
    }
    return movable;
}

bool Block::drop(vector<vector<Cell>> board) {
    down(board, 15);
    return true;
}

std::string Block::getBlockType() {
    return type;
}

vector<vector<int>> Block::getLocation() {
    return locations;
}

bool Block::isEmpty() {
    return locations.size() == 0;
}

void Block::notify(int n, int m) {
    int idx = 0;
    for(size_t i = 0; i < locations.size(); i++) {
        if (locations[i][0] == n && locations[i][1] == m) {
            locations.erase(locations.begin() + idx);
            break;
        }
        idx++;
    }
    if (locations.size() == 0) {
        notifyObservers();
    }
}

void Block::notifyObservers() {
    for(auto i : observers) {
        i->notify(generateLv);
    }
}

// This is a helper function that is used to determine whether the idx+1th points exists and is empty after adding a unit in its row and b units in its column.
bool Block::isFull(int idx, int a, int b, vector<vector<Cell>> board) {
    int row = locations[idx][0] + a;
    int col = locations[idx][1] + b;
    if(row < 0 || row > 17 || col < 0 || col > 10 || (board[row][col].getName() != "empty")) {
        return false;
    }
    return true;
}

bool Block::tryRotate(int a, int b, int c, int d, int e, int f, int g, int h, vector<vector<Cell>> board) {
    if(isFull(0,a,b,board) && isFull(1,c,d,board) && isFull(2,e,f,board) && isFull(3,g,h,board)) {
        locations[0][0]+=a;
        locations[0][1]+=b;
        locations[1][0]+=c;
        locations[1][1]+=d;
        locations[2][0]+=e;
        locations[2][1]+=f;
        locations[3][0]+=g;
        locations[3][1]+=h;
        return true;
    }
    else {
        return false;
    }
}

bool Block::isDropped() {
    return isdropped;
}
