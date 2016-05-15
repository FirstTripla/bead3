#include "widget.hpp"

void widget::setrgb(int rr, int gg, int bb){
    r=rr;
    g=gg;
    b=bb;
}

bool widget::kijelolt(int posx, int posy){
    return (posx <= x+ax && posx >= x) && (posy < y+ay && posy >= y);
}
