#ifndef TUILE_CARCASSONNE_HPP
#define TUILE_CARCASSONNE_HPP

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Common.hpp"

using namespace std;
using namespace sf;

enum Tile {
    T_CITY_GATE_AT_BOTTOM = 0,
    T_PATH_TOP_BOTTOM = 1,
    T_CITY_ON_TOP_JUNCTION = 2,
    T_CITY_DIAGONAL = 3,
    T_CITY_ON_TOP_PATHS_LEFT_RIGHT = 4,
    T_CITY_ON_TOP_PATHS_BOTTOM_RIGHT = 5,
    T_CITY_DIAGONAL_PATH_BOTTOM_RIGHT = 6,
    T_CITY_GATE_AT_BOTTOM_PROTECTED = 7,
    T_CITY_ON_TOP = 8,
    T_CITY_ON_TOP_OTHER_LEFT = 9,
    T_CITY_ON_LEFT_RIGHT_PROTECTED = 10,
    T_CITY_ON_TOP_PATH_BOTTOM_LEFT = 11,
    T_JUNCTION = 12,
    T_CITY_ON_TOP_OTHER_BOTTOM= 13,
    T_CITY_PROTECTED = 14,
    T_PATH_BOTTOM_LEFT = 15,
    T_JUNCTION_BOTTOM_LEFT_RIGHT = 16,
    T_ABBEY = 17,
    T_ABBEY_PATH_BOTTOM = 18,
    T_FULL_CITY_PROTECTED = 19,
    T_CITY_ON_LEFT_RIGHT = 20,
    T_CITY_DIAGONAL_PROTECTED = 21,
    T_CITY_DIAGONAL_PATH_BOTTOM_RIGHT_PROTECTED = 22,
    T_CITY = 23
};

enum Tile_Bord {
    GRASS, PATH, START_PATH, ABBEY, CITY, PROT_CITY, SOLO_CITY 
};


enum CarColor { RED = 0, YELLOW = 1, GREEN = 2, BLUE = 3, NONE = 4 };
string carColorToString(CarColor c);


class BordCarcassonne {
    public:
        Tile_Bord tile;
        CarColor partisant = NONE;
        bool marque = false;
        BordCarcassonne(Tile_Bord tile);
};

class TuileCarcassonne {
    public :
        int x = 0;
        int y = 0;
        int rotation = 0; // *90°, 0 = pas de rotation, max 3 par ordre chronologique
        Tile tile;
        vector<BordCarcassonne> bords;
        TuileCarcassonne(Tile tile);
        void turn(); 
        void initBords(vector<Tile_Bord> v);
};

#endif 