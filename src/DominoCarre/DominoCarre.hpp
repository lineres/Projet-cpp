#ifndef DOMINOCARRE_HPP
#define DOMINOCARRE_HPP

#include "Terrain.hpp"
#include "Main.hpp"
#include "TuileDomino.hpp"
#include "Common.hpp"
using namespace sf;
using namespace std;

class DominoCarre {
    public:
        DominoCarre(int h, int w);
        void start();

    private:
        int height;
        int width;
        Terrain<TuileDomino> terrain;
        int player = 0;
        int score1 = 0;
        int score2 = 0;
        int bag;
        int tryPlaceTuile(int y, int x, TuileDomino *tuile);
        vector<vector<int>> getPossiblePlacements(TuileDomino *tuile);
        int placeTuile(int y, int x, TuileDomino* tuile);
};

#endif