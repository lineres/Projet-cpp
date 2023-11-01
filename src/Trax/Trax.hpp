#ifndef TRAX_HPP
#define TRAX_HPP


#include "Terrain.hpp"
#include "TuileTrax.hpp"
#include "Main.hpp"

using namespace sf;
using namespace std;

class Trax{
    public :
        Trax();
        void start();

    private:
        int height = 8;
        int width = 8; 
        Terrain<TuileTrax> terrain{8,8};
        int player = 0;
        bool tryPlaceTuile(int y, int x, TuileTrax *tuile);
        vector<vector<bool>> getPossiblePlacements(TuileTrax *tuile);
        bool placeTuile(int y, int x, TuileTrax* tuile);
        void doAllForcedPlays(vector<tuple<int,int>> liste);
        void angleForcedPlays(int y, int x);
        void lineForcedPlays(int y, int x);

        tuple <bool, vector<tuple<int, TuileTrax *>>> checkVictoryOnPath(
                vector<tuple<int, TuileTrax *>> visited,
                int player,
                tuple<int, TuileTrax *> current
            );
        int checkVictory(vector<tuple<int,int>> listeA,BordColor couleur);
        int victoireParLigne(vector<tuple<int,int>> liste);
        int allerDirection(vector<tuple<int,int>> positionDejaParcourue,int i,int j,BordColor couleur);
};

#endif