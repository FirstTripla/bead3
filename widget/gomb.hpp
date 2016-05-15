#ifndef GOMB_HPP
#define GOMB_HPP

#include <functional>
#include "widget.hpp"

class Gomb : public widget{
private:
    std::string felirat;
public:
    Gomb(int x_,  int y_, int ax_, int ay_, std::string felirat_, int id_): widget(x_, y_, ax_, ay_, id_),felirat(felirat_){}
    void rajzol(int cel);
    void muvelet(genv::event ev,int &cel){};
    void set_text(std::string szo);
};

class funcbutton : public widget{
private:
    std::string felirat;
    std::function<void(funcbutton*)> f;
public:
    funcbutton(int x_, int y_, int ax_, int ay_, std::string felirat_, int id_, std::function<void(funcbutton*)> fv_): widget(x_, y_, ax_, ay_, id_),felirat(felirat_),f(fv_){}
    void rajzol(int cel);
    void muvelet(genv::event ev,int &cel);
    void set_text(std::string szo);
    std::string get_text();
};

#endif // GOMB_HPP
