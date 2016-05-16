#ifndef STATICTEXT_HPP
#define STATICTEXT_HPP

#include "widget.hpp"

class stext : public widget{
protected:
    std::string szoveg1;
public:
    stext(int x_,  int y_, int ax_, int ay_, std::string szoveg_, int id_): widget(x_, y_, ax_, ay_, id_),szoveg1(szoveg_){}
    void rajzol(int cel);
    void muvelet(genv::event ev,int &cel){};
    std::string get_text();
    void set_text(std::string szo);
};

#endif // STATICTEXT_HPP
