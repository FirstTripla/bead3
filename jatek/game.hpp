#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "../widget/widget.hpp"
class game{
private:
    int XX,YY;
    int R,G,B;
    std::vector<widget *> w;
    std::string cim;
    bool kilep;
public:
    game(int _XX, int _YY, std::string _cim);
    void kilepes();
    void set_color(int _r, int _g, int _b);
    void run();
    void addwidget(widget* _w);
};

#endif // GAME_HPP
