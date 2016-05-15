#include "graphics.hpp"
#include "../widget/widget.hpp"
#include "../jatek/game.hpp"
#include <vector>

game::game(int _XX, int _YY, std::string _cim) : XX(_XX),YY(_YY),cim(_cim){
    kilep=false;
}

void game::kilepes(){
    kilep=true;
}
 void game::set_color(int _r, int _g, int _b){
    R=_r;
    G=_g;
    B=_b;
 }
