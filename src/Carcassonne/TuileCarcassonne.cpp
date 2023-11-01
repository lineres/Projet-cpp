#include "TuileCarcassonne.hpp"

string carColorToString(CarColor c) {
    switch(c){
        case BLUE : return "blue"; break;
        case YELLOW : return "yellow"; break;
        case GREEN : return "green"; break;
       default: return "red"; break;
    }
    return "";
}


BordCarcassonne::BordCarcassonne(Tile_Bord tile) : tile{tile} {

}

TuileCarcassonne::TuileCarcassonne(Tile tile) : tile{tile} {
}


void TuileCarcassonne::initBords(vector<Tile_Bord> v) {
    for(int i = 0; i<4; i++) {
        bords.push_back(BordCarcassonne{v[i]});
    }
}

void TuileCarcassonne::turn() {
    rotation = (rotation+1)%4;
    BordCarcassonne tmp = bords[LEFT];
    bords[LEFT] = bords[BOTTOM];
    bords[BOTTOM] = bords[RIGHT];
    bords[RIGHT] = bords[TOP];
    bords[TOP] = tmp;
}
