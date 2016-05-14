#include "graphics.hpp"
#include "statictext.hpp"

using namespace genv;
using namespace std;

void stext::rajzol(int cel){
    gout << move_to(x,y) << color(r,g,b) << box(ax,ay);
    gout << move_to(x-gout.twidth(szoveg1)/2+ax/2,y+ay/2+(gout.cascent()+gout.cdescent())/4) << color(0,0,0)<< text(szoveg1);
}

std::string stext::get_text(){
    return szoveg1;
}

void stext::set_text(std::string szo){
    szoveg1=szo;
}
