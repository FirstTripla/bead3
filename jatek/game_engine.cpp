#include "../jatek/game_engine.hpp"
#include "../widget/gomb.hpp"
#include "../widget/statictext.hpp"
#include <iostream>

void game_engine::engine(int i, int j, funcbutton* me){


}

game_engine::game_engine(int _XX, int _YY, std::string _cim, int _n) : game(_XX, _YY,_cim){
    n=_n;
    int x=30;
    int y=60;
    int m=20; //meret
    for(int i=0;i<n;i++){
        for(int j=0; j<n;j++){
            hozzaad(new funcbutton(x+i*m,y+j*m,m,m,"",i+j,[i,j,this](funcbutton* me){engine(i,j,me);}));
        }
    }
};


