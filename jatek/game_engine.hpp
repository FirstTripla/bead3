#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include "../jatek/game.hpp"
#include "../widget/gomb.hpp"
#include "../widget/statictext.hpp"

class game_engine: public game{
protected:
    int n;
    //std::string nyert()
    stext * st1;
    bool gover=false; // ha valaki nyer vagy elfogy az üres mezõ akkor true lesz
    bool o_jon=false;
    bool x_jon=true;
    void engine(funcbutton* ez);
public:
    game_engine(int _XX, int _YY, int n);
};

#endif // GAME_ENGINE_HPP
