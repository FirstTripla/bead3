#include "../jatek/game_engine.hpp"
#include "../widget/gomb.hpp"
#include "../widget/statictext.hpp"
#include <iostream>
#include <vector>

void game_engine::engine(funcbutton* ez){
    std::string rakta="";
    if(gover==false){
        if(ez->get_text()==" " && x_jon==true){
            rakta="X";
            ez->set_text("X");
            st1->set_text("A kék (O) játékos jön.");
            x_jon=false;
            o_jon=true;
        }
        else if(ez->get_text()==" " && o_jon==true){
            rakta="O";
            ez->set_text("O");
            st1->set_text("A piros (X) játékos jön.");
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
            rakta="";
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
                if(tmp_oszlop.size()>=limit){
                    gover=true;
                    tmp_oszlop.clear();
                    st1->set_text("A(z) "+rakta+" játékos nyert.");
                    break;
                }
                tmp_oszlop.clear();
                if(tmp_sor.size()>=limit){
                    gover=true;
                    tmp_sor.clear();
                    st1->set_text("A(z) "+rakta+" játékos nyert.");
                    break;
                }
                tmp_sor.clear();

            }
        }
        for(int k=0;k<n-limit+1;k++){
            for(int l=0;l<n-limit+1;l++){
                //atlo job le iranyba
                for(int m=0;m<5;m++){
                    if(((funcbutton*)w[(k+m)*n+l+m])->get_text()==rakta){
                        tmp_atlo1.push_back(((funcbutton*)w[(k+m)*n+l+m]));
                    }
                    if(((funcbutton*)w[(k+limit-1-m)*n+l+m])->get_text()==rakta){
                        tmp_atlo2.push_back(((funcbutton*)w[(k+limit-1-m)*n+l+m]));
                    }
                   // std::cout<<(k+limit-1-m)*n+l+m<<" ";
                }
                if(tmp_atlo1.size()>=5){
                    gover=true;
                    for(int b=0;b<tmp_atlo1.size();b++){
                        tmp_atlo1[b]->setrgb(200,0,200);
                    }
                    tmp_atlo1.clear();
                    st1->set_text("A(z) "+rakta+" játékos nyert.(atlo)");
                    break;
                }
                tmp_atlo1.clear();
                if(tmp_atlo2.size()>=5l){
                    gover=true;
                    tmp_atlo2.clear();
                    st1->set_text("A(z) "+rakta+" játékos nyert.");
                    break;
                }
                tmp_atlo2.clear();
                //std::cout<<std::endl;
            }
            //std::cout<<std::endl;
        }

        /*for(int k=0;k<n-5;k++){
            for(int l=0;l<n-5;l++){
                //oszlop vizsgalat [i*n+l]
                for(int i=k;i<k+5;i++){
                    if(((funcbutton*)w[i+l*n])->get_text()==rakta){
                        tmp_oszlop.push_back(((funcbutton*)w[i+l*n]));
                    }
                    //std::cout<<i+l*n<<" ";
                }
                if(tmp_oszlop.size()>=5){
                    gover=true;
                    tmp_oszlop.clear();
                    st1->set_text("A(z) "+rakta+" játékos nyert.");
                    break;
                }
                tmp_oszlop.clear();
                //sor vizsgalat     [j+k*n]
                for(int j=l;j<l+5;j++){
                    if(((funcbutton*)w[j+k*n])->get_text()==rakta){
                        tmp_sor.push_back(((funcbutton*)w[j+k*n]));
                    }
                                    std::cout<<j+k*n<<" ";

                }
                if(tmp_sor.size()>=5){
                    gover=true;
                    tmp_sor.clear();
                    st1->set_text("A(z) "+rakta+" játékos nyert.");
                    break;
                }
                tmp_sor.clear();
                //atlo jobb le iranyba
                for(int m1=0;m1<5;m1++){
                    if(((funcbutton*)w[(k+m1)*n+l+m1])->get_text()==rakta){
                        tmp_atlo1.push_back(((funcbutton*)w[(k+m1)*n+l+m1]));
                    }
                    //std::cout<<(k+m1)*n+l+m1<<" ";
                }
                if(tmp_atlo1.size()>=5){
                    gover=true;
                    tmp_atlo1.clear();
                    st1->set_text("A(z) "+rakta+" játékos nyert.");
                    break;
                }
                tmp_atlo1.clear();
                //atlo jobb fel iranyba
                for(int m2=0;m2<5;m2++){
                    if(((funcbutton*)w[(k+5-1-m2)*n+l+m2])->get_text()==rakta){
                        tmp_atlo2.push_back(((funcbutton*)w[(k+5-1-m2)*n+l+m2]));
                    }
                }
                if(tmp_atlo2.size()>=5l){
                    gover=true;
                    tmp_atlo2.clear();
                    st1->set_text("A(z) "+rakta+" játékos nyert.");
                    break;
                }
                tmp_atlo2.clear();
                std::cout<<std::endl;
            }
            std::cout<<std::endl;
        }*/
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
           // std::cout<<i<<j<<" ";
        }
        //std::cout<<std::endl;
    }
    funcbutton* exit=new funcbutton(XX-70,10,60,30,"Exit",1,[&](funcbutton* ez)
    {
        kilepes();
    });
    exit->setrgb(0,0,220);
    hozzaad(exit);

    st1 = new stext(250,10,400,20,"A piros (X) játékos kezd.",2);
    st1->setrgb(200,200,0);
    hozzaad(st1);

    funcbutton* rst=new funcbutton(XX-70,50,60,30,"Restart",3,[&](funcbutton* ez)
    {
        st1->set_text("A piros (X) játékos kezd.");
        for(int i=0;i<n*n;i++){
            ((funcbutton*)w[i])->set_text(" ");
        }
        x_jon=true;
        o_jon=false;
        gover=false;
    });
    rst->setrgb(200,0,0);
    hozzaad(rst);
};


