#include "../jatek/game_engine.hpp"
#include "../widget/gomb.hpp"
#include "../widget/statictext.hpp"
#include <iostream>
#include <vector>

void game_engine::engine(funcbutton* ez){
    std::string rakta="";
    if(gover==false){
        if(ez->get_text()=="" && x_jon==true){
            rakta="X";
            ez->set_text("X");
            st1->set_text("A k�k (O) j�t�kos j�n.");
            x_jon=false;
            o_jon=true;
        }
        else if(ez->get_text()=="" && o_jon==true){
            rakta="O";
            ez->set_text("O");
            st1->set_text("A piros (X) j�t�kos j�n.");
            o_jon=false;
            x_jon=true;
        }
        int ures=0; //szabad hely a mezon
        for(int i=0;i<n*n;i++){
            if(((funcbutton*)w[i])->get_text()==""){
                ures++;
            }
        }
        if(ures==0){
            rakta="";
            gover=true;
            st1->set_text("D�ntetlen, a p�lya betelt.");
        }
        std::vector<funcbutton*> tmp_sor;
        std::vector<funcbutton*> tmp_oszlop;
        tmp_sor.clear();
        tmp_oszlop.clear();
        for(int k=0;k<n-5;k++){
            for(int l=0;l<n-5;l++){
                for(int i=k;i<k+5;i++){ //sor
                    if(((funcbutton*)w[i*n+l])->get_text()==rakta){
                        tmp_sor.push_back(((funcbutton*)w[i*n+l]));
                    }
                }

                for(int j=l;j<l+5;j++){ //oszlop
                    if(((funcbutton*)w[j*n+k])->get_text()==rakta){
                        tmp_sor.push_back(((funcbutton*)w[j*n+k]));
                    }
                }
                if(tmp_sor.size()>=5){
                    gover=true;
                    tmp_sor.clear();
                    st1->set_text("A "+rakta+" j�t�kos nyert.");
                    break;
                }
                if(tmp_oszlop.size()>=5){
                    gover=true;
                    tmp_oszlop.clear();
                    st1->set_text("A(z) "+rakta+" j�t�kos nyert.");
                    break;
                }
                tmp_sor.clear();
                tmp_oszlop.clear();
            }
        }
    }
}

game_engine::game_engine(int _XX, int _YY, int _n) : game(_XX, _YY){
    n=_n;
    int x=40;  //kezdo hely
    int y=40;
    int m=20;  //meret
    for(int i=0;i<n;i++){
        for(int j=0; j<n;j++){
            funcbutton* fb=new funcbutton(x+i*(m+1),y+j*(m+1),m,m,"",i+j,[&](funcbutton* ez)
            {
                engine(ez);
            });
            fb->setrgb(100,100,100);
            hozzaad(fb);
        }
    }
    funcbutton* exit=new funcbutton(XX-70,10,60,30,"Kil�p�s",1,[&](funcbutton* ez)
    {
        kilepes();
    });
    exit->setrgb(0,0,220);
    hozzaad(exit);
    st1 = new stext(250,10,400,20,"A piros (X) j�t�kos kezd.",2);
    st1->setrgb(200,200,0);
    hozzaad(st1);
};


