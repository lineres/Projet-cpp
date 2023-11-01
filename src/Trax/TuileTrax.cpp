#include "TuileTrax.hpp"

TuileTrax::TuileTrax(const vector<BordColor> &bords) : bords{bords} {}

TuileTrax* getRandomTuileTrax(){
    if(rand() % 2 == 0){  
        return new TuileTrax{vector<BordColor>{white,red,white,red}};
    } else { 
        return new TuileTrax{vector<BordColor>{white,white,red,red}};
    }
}

String TuileTrax::toTexturePath() {
    String path = "resources/trax/";
    for(int i = 0; i < 4; i++) {
        if(bords[i] == 0)
            path += "B";
        else
            path += "R";
    }
    return path + ".png";
}


void TuileTrax::draw(RenderWindow *app, int start_x, int start_y, int ZONE_WIDTH, int ZONE_HEIGHT){
    Texture texture;
    texture.loadFromFile(toTexturePath());
    Sprite sprite;
    sprite.setTexture(texture);
    sprite.scale(1,1);
    sprite.move(start_x, start_y);
    app->draw(sprite);
}

void TuileTrax::turn() {
    BordColor tmp = bords[LEFT];
    bords[LEFT] = bords[BOTTOM];
    bords[BOTTOM] = bords[RIGHT];
    bords[RIGHT] = bords[TOP];
    bords[TOP] = tmp;
}