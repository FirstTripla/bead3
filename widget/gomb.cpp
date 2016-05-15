#include "graphics.hpp"
#include "gomb.hpp"

using namespace genv;
using namespace std;

void Gomb::rajzol(int cel){
    gout<<move_to(x,y)<<color(r,g,b)<<box(ax,ay);
    if(felirat=="fel"){
        gout<<move_to(x+6,y+ay-6)<<color(255,255,255)<<line_to(x+ax/2,y+6)<<line_to(x+ax-6,y+ay-6);
        gout<<move_to(x+7,y+ay-6)<<color(255,255,255)<<line_to(x+ax/2,y+8)<<line_to(x+ax-7,y+ay-6);
    }
    else if(felirat=="le"){
        gout<<move_to(x+6,y+6)<<color(255,255,255)<<line_to(x+ax/2,y+ay-6)<<line_to(x+ax-6,y+6);
        gout<<move_to(x+7,y+6)<<color(255,255,255)<<line_to(x+ax/2,y+ay-8)<<line_to(x+ax-7,y+6);
    }
    else{
        gout<<move_to(x-gout.twidth(felirat)/2+ax/2,y+ay/2+(gout.cascent()+gout.cdescent())/4)<<color(255,255,255)<<text(felirat);
    }
}

void Gomb::set_text(std::string szo){
    felirat=szo;
}

void funcbutton::rajzol(int cel){
    gout<<move_to(x,y)<<color(r,g,b)<<box(ax,ay);
    gout<<move_to(x-gout.twidth(felirat)/2+ax/2,y+ay/2+(gout.cascent()+gout.cdescent())/4)<<color(255,255,255)<<text(felirat);
}

void funcbutton::muvelet(genv::event ev,int &cel){
    if(kijelolt(ev.pos_x, ev.pos_y) && ev.button==btn_left){
        f();
    }
}