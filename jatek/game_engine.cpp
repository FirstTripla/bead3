#include "../jatek/game_engine.hpp"

void nyero_szin(std::vector<funcbutton*>& fbt){
    for(size_t i=0;i<fbt.size();i++){
        if(fbt[i]->get_text()=="X")fbt[i]->setrgb(200,100,10+20*i);
        else fbt[i]->setrgb(100,30+i*20,200);
    }
}

void game_engine::engine(funcbutton* ez){
    std::string rakta="";
    if(gover==false){
        if(ez->get_text()==" " && x_jon==true){
            rakta="X";
            ez->set_text("X");
            st1->set_text("A kék O játékos jön.");
            x_jon=false;
            o_jon=true;
        }
        else if(ez->get_text()==" " && o_jon==true){
            rakta="O";
            ez->set_text("O");
            st1->set_text("A piros X játékos jön.");
            o_jon=false;
            x_jon=true;
        }
        int ures=0; //szabad hely a mezon
        for(int i=0;i<n*n;i++){
            if(((funcbutton*)w[i])->get_text()==" "){
                ures++;
            }
        }
        if(ures==0){
            rakta=" ";
            gover=true;
            st1->set_text("Döntetlen, a pálya betelt.");
        }
        std::vector<funcbutton*> tmp_sor;
        std::vector<funcbutton*> tmp_oszlop;
        std::vector<funcbutton*> tmp_atlo1;
        std::vector<funcbutton*> tmp_atlo2;
        tmp_sor.clear();
        tmp_oszlop.clear();
        tmp_atlo1.clear();
        tmp_atlo2.clear();
        int limit=5;
        for(int k=0;k<n-limit+1;k++){
            for(int l=0;l<n;l++){
                for(int i=k;i<k+limit;i++){
                    if(((funcbutton*)w[i*n+l])->get_text()==rakta){//oszlop
                        tmp_oszlop.push_back(((funcbutton*)w[i*n+l]));
                    }
                    if(((funcbutton*)w[i+l*n])->get_text()==rakta){//sor
                        tmp_sor.push_back(((funcbutton*)w[i+l*n]));
                    }
                }
                if(tmp_oszlop.size()>=(unsigned)limit && (mit=="oszlop" || mit==" ")){
                    gover=true;
                    mit="oszlop";
                    nyero_szin(tmp_oszlop);
                    tmp_oszlop.clear();
                    st1->set_text("A(z) "+rakta+" játékos nyert.");
                    break;
                }
                tmp_oszlop.clear();
                if(tmp_sor.size()>=(unsigned)limit && (mit=="sor" || mit==" ")){
                    gover=true;
                    mit="sor";
                    nyero_szin(tmp_sor);
                    tmp_sor.clear();
                    st1->set_text("A(z) "+rakta+" játékos nyert.");
                    break;
                }
                tmp_sor.clear();

            }
            for(int l=0;l<n-limit+1;l++){
                for(int m=0;m<5;m++){
                    if(((funcbutton*)w[(k+m)*n+l+m])->get_text()==rakta){//atlo jobb le iranyba
                        tmp_atlo1.push_back(((funcbutton*)w[(k+m)*n+l+m]));
                    }
                    if(((funcbutton*)w[(k+limit-1-m)*n+l+m])->get_text()==rakta){//atlo jobb fel iranyba
                        tmp_atlo2.push_back(((funcbutton*)w[(k+limit-1-m)*n+l+m]));
                    }
                }
                if(tmp_atlo1.size()>=(unsigned)limit && (mit=="atlo1" || mit==" ")){
                    gover=true;
                    mit="atlo1";
                    nyero_szin(tmp_atlo1);
                    tmp_atlo1.clear();
                    st1->set_text("A(z) "+rakta+" játékos nyert.");
                    break;
                }
                tmp_atlo1.clear();
                if(tmp_atlo2.size()>=(unsigned)limit && (mit=="atlo2" || mit==" ")){
                    gover=true;
                    mit="atlo2";
                    nyero_szin(tmp_atlo2);
                    tmp_atlo2.clear();
                    st1->set_text("A(z) "+rakta+" játékos nyert.");
                    break;
                }
                tmp_atlo2.clear();
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
            funcbutton* fb=new funcbutton(x+j*(m+1),y+i*(m+1),m,m," ",i+j,[&](funcbutton* ez)
            {
                engine(ez);
            });
            fb->setrgb(100,100,100);
            hozzaad(fb);
        }
    }
    funcbutton* exit=new funcbutton(XX-70,10,60,30,"Exit",1,[&](funcbutton* ez)
    {
        kilepes();
    });
    exit->setrgb(0,0,220);
    hozzaad(exit);

    st1 = new stext(10,10,XX-90,20,"A piros X játékos kezd.",2);
    st1->setrgb(0,200,200);
    hozzaad(st1);

    funcbutton* rst=new funcbutton(XX-70,50,60,30,"Restart",3,[&](funcbutton* ez)
    {
        st1->set_text("A piros X játékos kezd.");
        for(int i=0;i<n*n;i++){
            ((funcbutton*)w[i])->set_text(" ");
            ((funcbutton*)w[i])->setrgb(100,100,100);
        }
        x_jon=true;
        o_jon=false;
        gover=false;
        mit=" ";
    });
    rst->setrgb(200,0,0);
    hozzaad(rst);
};
