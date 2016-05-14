/// Halmai Levente RS7P1M ///
#include "graphics.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <functional>

#include "./widget/widget.hpp"
#include "./widget/statictext.hpp"
#include "./widget/gomb.hpp"

using namespace std;
using namespace genv;

const int XX=800;
const int YY=600;

int main()
{
    gout.open(XX,YY);

    int cel=0;
    int i=1;
    string szo="Ide írj...";
    vector<widget*> w;
    vector<string> s={"1.elem","2.elem","3.elem","4.elem","5.elem","6.elem","7.elem","8.elem","9.elem","10.elem"};
   /* dlist * dl1 = new dlist(10, 200, 200, 40, 4, s, i++);
    dlist * dl2 = new dlist(320, 200, 200, 40, 7, s, i++);
    funcbutton * fbt1 = new funcbutton(180,10,70,35,"Hozzáad",i++,[&](){
        dl1->add(dt1->get_text());
    });
    funcbutton * fbt3 =new funcbutton(180,100,90,35,"Hozzáad 2",i++,[&](){
        dl2->add(dt2->get_text());
    });
    funcbutton * fbt2 = new funcbutton(720,10,70,50,"Mentés",i++,[&](){
        ofstream ki("mentes.txt");
        ki<<"1. számbeállító értéke: "<<dsz1->get_szam()<<endl;
        ki<<"2. számbeállító értéke: "<<dsz2->get_szam()<<endl;
        ki<<"1. listában kiválasztott elem: "<<dl1->get_text()<<endl;
        ki<<"2. listában kiválasztott elem: "<<dl2->get_text()<<endl;
        ki.close();
        cout<<"Kiiras befejezve!"<<endl;
    });
    funcbutton * jobbra =new funcbutton(220,200,90,35,"-->",i++,[&](){
        if(dl1->get_text()!=" "){
            dl2->add(dl1->get_text());
        }
        dl1->remove_elem(dl1->get_valaszt());
    });
    funcbutton * balra =new funcbutton(220,245,90,35,"<--",i++,[&](){
        if(dl2->get_text()!=" "){
            dl1->add(dl2->get_text());
        }
        dl2->remove_elem(dl2->get_valaszt());
    });
    w.push_back(dt1);
    w.push_back(dt2);
    w.push_back(dsz1);
    w.push_back(dsz2);
    w.push_back(dl1);
    w.push_back(dl2);
    w.push_back(fbt1);
    w.push_back(fbt2);
    w.push_back(fbt3);
    w.push_back(jobbra);
    w.push_back(balra);

    for(size_t i=0;i<w.size();i++){
        w[i]->setrgb(200,0,0);
    }
    fbt1->setrgb(0,0,200);
    fbt2->setrgb(180,0,0);
    fbt3->setrgb(0,200,0);
    */
	event ev;

	while(gin >> ev && ev.keycode != key_escape)
    {
        gout<<move_to(0,0)<<color(0,0,0)<<box(XX,YY);
        /*if(ev.keycode == key_tab){
            cel++;
            if((unsigned)cel>w.size()){
                cel=0;
            }
        }
        for(size_t i=0;i<w.size();i++){
            w[i]->muvelet(ev,cel);
            w[i]->rajzol(cel);
        }
        if(cel!=0){
            w[cel-1]->rajzol(cel);
        }*/
        //df
        gout<< refresh;
    }
	return 0;
}
