#include "graphics.hpp"
#include "../jatek/game.hpp"
#include <vector>
#include <iostream>
#include "../widget/widget.hpp"
using namespace std;
using namespace genv;

game::game(int _XX, int _YY) : XX(_XX),YY(_YY){
    kilep=false;
    R=0;
    G=0;
    B=0;
    w.clear();
}

void game::kilepes(){
    kilep=true;
}

void game::set_color(int _r, int _g, int _b){
    R=_r;
    G=_g;
    B=_b;
}

void game::hozzaad(widget* _w){
    w.push_back(_w);
}

void game::run(){
    gout.open(XX,YY);
    gout.set_title("Amõba játék");
    int cel=0;
    event ev;
    while(gin >> ev && kilep==false){
        gout<<move_to(0,0)<<color(R,G,B)<<box(XX,YY);
        for(size_t i=0; i<w.size();i++){
            w[i]->muvelet(ev,cel);
            w[i]->rajzol(cel);
        }
        gout<<refresh;
    }
}

