#include "../jatek/game_engine.hpp"
#include "../widget/gomb.hpp"
#include "../widget/statictext.hpp"
#include <iostream>

void game_engine::engine(funcbutton* ez){
    std::string rakta="";
    if(gover==false){
        if(ez->get_text()=="" && x_jon==true){
            rakta="X";
            ez->set_text("X");
            st1->set_text("A kék (O) játékos jön.");
            x_jon=false;
            o_jon=true;
        }
        else if(ez->get_text()=="" && o_jon==true){
            rakta="O";
            ez->set_text("O");
            st1->set_text("A piros (X) játékos jön.");
            o_jon=false;
            x_jon=true;
        }
        int ures=0; //szabad hely a
        for(int i=0;i<n*n;i++){
            if(((funcbutton*)w[i])->get_text()==""){
                ures++;
            }
        }
        if(ures==0){
            rakta="";
            x_jon=false;
            o_jon=false;
            gover=true;
            st1->set_text("Döntetlen, a pálya betelt.");
        }
    }

}

game_engine::game_engine(int _XX, int _YY, int _n) : game(_XX, _YY){
    n=_n;
    int x=40;   //kezdo hely
    int y=40;
    int m=20; //meret
    for(int i=0;i<n;i++){
        for(int j=0; j<n;j++){
            funcbutton* fb=new funcbutton(x+i*(m+2),y+j*(m+2),m,m,"",i+j,[&](funcbutton* ez){
                        engine(ez);
            });
            //fb->setrgb(200-(i+j)*2,i*5,j*6);
            fb->setrgb(100,100,100);
            hozzaad(fb);
        }
    }
    funcbutton* exit=new funcbutton(XX-70,10,60,30,"Kilépés",1,[&](funcbutton* ez){
        kilepes();
    });
    exit->setrgb(0,0,220);
    hozzaad(exit);
    st1 = new stext(250,10,400,20,"A piros (X) játékos kezd.",2);
    st1->setrgb(200,200,0);
    hozzaad(st1);
};


