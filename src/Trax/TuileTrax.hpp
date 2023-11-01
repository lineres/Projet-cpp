#ifndef TUILE_TRAX_HPP
#define TUILE_TRAX_HPP

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>


#include "Common.hpp"

using namespace std;
using namespace sf;

enum BordColor { white, red };

class TuileTrax {
    public :
        vector<BordColor> bords;
        TuileTrax(const vector<BordColor> &bords);
        void draw(RenderWindow *app, int start_x, int start_y, int ZONE_WIDTH, int ZONE_HEIGHT );
        void turn();
        String toTexturePath();
};
TuileTrax* getRandomTuileTrax();

#endif 