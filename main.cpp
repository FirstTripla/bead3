/// Halmai Levente RS7P1M ///
#include "../jatek/game_engine.hpp"
int main()
{
    //game_engine amoba(600,450,20);
    //game_engine amoba(1000,900,40);
        //mukodik vele, viszont a monitorom felbontasa csak 1366x768, de teszteltem ideiglenes gepen 1920x1080-n
    game_engine amoba(800,680,30);
    amoba.run();
	return 0;
}
