#include "../jatek/game_engine.hpp"
#include "../widget/gomb.hpp"
#include "../widget/statictext.hpp"
#include <iostream>

void game_engine::engine(int i, int j, funcbutton* me){
    if(gover==false){


    }

}

game_engine::game_engine(int _XX, int _YY, std::string _cim, int _n) : game(_XX, _YY,_cim){
    n=_n;
    int x=40;
    int y=40;
    int m=20; //meret
    for(int i=0;i<n;i++){
        for(int j=0; j<n;j++){
            funcbutton* fb=new funcbutton(x+i*(m+2),y+j*(m+2),m,m,"",i+j,[i,j,this](funcbutton* me){
                        engine(i,j,me);
                        std::cout<<"lol"<<i<<std::endl;
            });
            fb->setrgb(100-(i+j)*2,i*10,j*5);
            hozzaad(fb);

            std::cout << i+j<<std::endl;
        }
    }
    st1 = new stext(250,10,400,20,"A piros (X) játékos kezd.",1);
    st1->setrgb(200,200,0);
    hozzaad(st1);
};


