#ifndef _CELL_H_
#define _CELL_H_
#include "commands.h"
#include <string>
#include "subject.h"

class Cell: public Subject {
    int r, c;
    bool blind = false;
    std::string name = EMPTY;

    public:
        Cell(int row, int col);
        void setBlind(bool state);
        bool isBlind();
        void setName(std::string name_);
        std::string getName();
        void notifyObservers() override;
};

#endif