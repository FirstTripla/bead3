#ifndef GAME_HPP
#define GAME_HPP

#include "../widget/widget.hpp"
#include <vector>

class game{
protected:
    int XX,YY;
    int R,G,B;
    std::vector<widget *> w;
    std::string cim;
    bool kilep;
public:
    game(int _XX, int _YY);
    void kilepes();
    void set_color(int _r, int _g, int _b);
    void run();
    void hozzaad(widget* _w);
};

#endif // GAME_HPP
