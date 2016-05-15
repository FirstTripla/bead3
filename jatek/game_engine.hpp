#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include "../jatek/game.hpp"
#include "../widget/gomb.hpp"
#include "../widget/statictext.hpp"

class game_engine: public game{
protected:
    int n;
    stext * st1;
    bool gover=false; // ha valaki nyer vagy elfogy az üres mezõ akkor true lesz
    bool o_jon=false;  // ha true akkor a O rak, ha false akkor X rak
    void engine(int i, int j, funcbutton* me);
public:
    game_engine(int _XX, int _YY, int n);
};

#endif // GAME_ENGINE_HPP
