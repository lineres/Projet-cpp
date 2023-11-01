#ifndef TUILE_DOMINO_HPP
#define TUILE_DOMINO_HPP

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Common.hpp"

using namespace std;
using namespace sf;

class TuileDomino {
    public :
        vector<vector<int>> bords;
        TuileDomino(const vector<vector<int>> &bords);
        void draw(sf::RenderWindow *app, int start_x, int start_y, int ZONE_WIDTH, int ZONE_HEIGHT ); 
        void turn(); 
};
TuileDomino* getRandomTuileDomino();


#endif 