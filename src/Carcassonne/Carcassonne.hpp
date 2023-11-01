#ifndef CARCASSONNE_HPP
#define CARCASSONNE_HPP

#include <random>

#include "Terrain.hpp"
#include "TuileCarcassonne.hpp"
#include "Main.hpp"

using namespace sf;
using namespace std;


class Carcassonne {
    public :
        Carcassonne();
        void start();

    private:
        map<Tile, int> available_tiles{};
        vector<TuileCarcassonne *> tuiles{};
        CarColor player = RED;
        vector<int> scores;
        vector<int> nb_partisants;
        TuileCarcassonne* getRandomTuileCarcassonne();
        TuileCarcassonne * getTuile(int y, int x);
        bool tryPlaceTuile(int y, int x, TuileCarcassonne *tuile);
        bool placeTuile(int y, int x, TuileCarcassonne* tuile);
        int calculScore_rec(TuileCarcassonne *tuile, Tile_Bord bord, Direction direction);
        void calculScore(int y, int x, TuileCarcassonne *tuile);
};


#endif