/// Halmai Levente RS7P1M ///
#include "../jatek/game_engine.hpp"
int main()
{
    /// elore beallitott beallitasok tobb merethez, hogy kiferjen kisebb kijelzokon is. :)
    ///n*n-es eseten is mukodik
    //game_engine amoba(600,450,20);
    //game_engine amoba(800,680,30);
    game_engine amoba(1000,900,40);
    amoba.run();
	return 0;
}
