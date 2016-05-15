#include "graphics.hpp"
#include "../widget/widget.hpp"
#include "../jatek/game.hpp"
#include <vector>
#include <iostream>

using namespace std;
using namespace genv;

game::game(int _XX, int _YY, std::string _cim) : XX(_XX),YY(_YY),cim(_cim){
    kilep=false;
    R=0;
    G=0;
    B=0;
}

void game::kilepes(){
    kilep=true;
}

void game::set_color(int _r, int _g, int _b){
    R=_r;
    G=_g;
    B=_b;
}

void game::addwidget(widget* _w){
    w.push_back(_w);
}

void game::run(){
    gout.open(XX,YY);
    gout.set_title(cim);
    int cel=0;
    event ev;
    while(gin >> ev && ev.keycode != key_escape){
        gout<<move_to(0,0)<<color(R,G,B)<<box(XX,YY);
        for(size_t i=0; i<w.size();i++){
            w[i]->muvelet(ev,cel);
            w[i]->rajzol(cel);
        }
        gout<<refresh;
    }
}
