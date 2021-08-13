#ifndef _GRAPHICS_
#define _GRAPHICS_
#include "window.h"
#include "board.h"
using std::vector;

class Graphics {
    Board* b1;
    Board* b2;
    shared_ptr<Xwindow> w;
    public:
        Graphics(Board* b1, Board* b2);
        void Overwrite(int hiScore);
};


#endif