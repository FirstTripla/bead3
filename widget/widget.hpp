#ifndef WIDGET_HPP
#define WIDGET_HPP
#include "graphics.hpp"

class widget{
protected:
    int x,y;    ///pozicioja
    int ax,ay;  ///merete
    int r,g,b;  ///szine
    int id;     ///sorszama
public:
    widget(int x_, int y_, int ax_, int ay_, int id_): x(x_),y(y_),ax(ax_), ay(ay_), id(id_){
        r=255;
        g=255;
        b=255;
    }
    bool kijelolt(int posx, int posy);
    virtual void rajzol(int cel) = 0;
    virtual void muvelet(genv::event ev,int &cel) = 0;
    void setrgb(int rr, int gg, int bb);
};
#endif // WIDGET_HPP
