#ifndef TERRAIN_HPP
#define TERRAIN_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

template <typename T> class Terrain {
    public:
        int height;
        int width;
        vector<vector<T *>> terrain;
        Terrain(int height, int width);
        T * getTuile(int y, int x) const;
        bool isEmpty();
        void draw(RenderWindow *app, int WIDTH, int HEIGHT);
};

template <typename T> 
Terrain<T>::Terrain(int height, int width) : height{height}, width{width} {
    vector <vector<T *>> plateau;
    for (int i = 0; i < height; i++) {
        vector < T *> tmp{};
        for (int j = 0; j < width; j++)
            tmp.push_back(nullptr);
        plateau.push_back(tmp);
    }
    terrain = plateau;
}


template <typename T>
T * Terrain<T>::getTuile(int y, int x) const {
    if( 0<= y && y < height && 0 <= x && x < width)
        return terrain[y][x];
    return nullptr;
}


template <typename T>
bool Terrain<T>::isEmpty() {
    for(int y = 0 ; y < height; y++ )
        for(int x= 0; x < width; x++)
            if(getTuile(y,x) != nullptr)
                return false;
    return true;
}


template <typename T>
void Terrain<T>::draw(RenderWindow *app, int ZONE_WIDTH, int ZONE_HEIGHT) {
    int block_width = ZONE_WIDTH/width;
    int block_height = ZONE_HEIGHT/height;
    for( int y = 0; y < height; y++) {
        for( int x = 0; x < width; x++) {
            RectangleShape rectangle(Vector2f(block_width, block_height));
            rectangle.move(block_width*x, block_height*y );
            T * tuile = getTuile(y,x);
            if( tuile != nullptr) {
                tuile->draw(app, block_width*x, block_height*y, block_width, block_height);
            } 
            else
                app->draw(rectangle);
        }
    }
}

// bool allerDroite(Terrain *terrain,int x,int y){
//     Tuile *tuile = terrain->getTuile(y,x);
//     bool check = false;



// bool allerBas(Terrain *terrain,int x,int y){ // x = ligne y = colonne ? 
//     Tuile *tuile = terrain->getTuile(y,x);
//     bool check = false;

//     if(y == terrain->getWidth()){return true;} // si on arrive au dernier alors tout se suit
//     if(tuile->getBord("ouest").x[0] == 0 && terrain->getTuile(y,x+1)->getBord("est").x[0] == 0 ){ // chemin vers la droite
//         check = allerGauche(terrain,x-1,y);
//         return check;  
//     } else if(tuile->getBord("est").x[0] == 0 && terrain->getTuile(y,x+1)->getBord("ouest").x[0] == 0 ){ // on va vers le haut
//         check = allerDroite(terrain,x+1,y);
//         return check;  
//     } else if(tuile->getBord("sud").x[0] == 0 && terrain->getTuile(y,x+1)->getBord("nord").x[0] == 0 ){
//        check = allerBas(terrain,x,y+1);   
//         return check;
//     }
//     return false;
// }


// bool allerHaut(Terrain *terrain,int x,int y){
//     Tuile *tuile = terrain->getTuile(y,x);
//     bool check = false;

//     if(y == 0){return true;} // si on arrive au dernier alors tout se suit
//     if(tuile->getBord("ouest").x[0] == 0 && terrain->getTuile(y,x+1)->getBord("est").x[0] == 0 ){ // chemin vers la droite
//         check = allerGauche(terrain,x-1,y);
//         return check;  
//     } else if(tuile->getBord("est").x[0] == 0 && terrain->getTuile(y,x+1)->getBord("ouest").x[0] == 0 ){ // on va vers le haut
//         check = allerDroite(terrain,x+1,y);
//         return check;  
//     } else if(tuile->getBord("nord").x[0] == 0 && terrain->getTuile(y,x+1)->getBord("sud").x[0] == 0 ){
//        check = allerHaut(terrain,x,y-1);   
//         return check;
//     }
//     return false;
// }



#endif //TERRAIN_HPP