
#include "Main.hpp"


static int domino_carre_h = 5;
static int domino_carre_w = 5;

void openMenuPrincipal(){

    Font font;
    font.loadFromFile("./resources/arial.ttf");
    Text text;
    text.setFont(font);
    text.setString("Projet Langage Objet Avance");
    text.setCharacterSize(50);
    text.setFillColor(Color::Red);


    Texture texture;
    texture.loadFromFile("./resources/Domino.jpg");
    Sprite menuDomino;
    menuDomino.setTexture(texture);
    menuDomino.setScale(Vector2f(2,2));
    menuDomino.move(Vector2f(25, 125));
    FloatRect domino_bounds = menuDomino.getGlobalBounds(); 

    Texture texture2;
    texture2.loadFromFile("./resources/Trax.jpg");
    Sprite menuTrax;
    menuTrax.setTexture(texture2);
    menuTrax.setScale(Vector2f(2,2));
    menuTrax.move(Vector2f(25, 275));
    FloatRect trax_bounds = menuTrax.getGlobalBounds(); 

    Texture texture3;
    texture3.loadFromFile("./resources/Carcassonne.png");
    Sprite menuCarcassonne;
    menuCarcassonne.setTexture(texture3);
    menuCarcassonne.setScale(Vector2f(2,2));
    menuCarcassonne.move(Vector2f(25, 425));
    FloatRect carcassonne_bounds = menuCarcassonne.getGlobalBounds(); 


    RenderWindow app(VideoMode(800, 600, 32), "Projet 2022 CPP ");
    while (app.isOpen()){
        Event event;
        while (app.pollEvent(event)){
            switch (event.type) {
                case Event::Closed:
                app.close(); break;
                default: break;
                case Event::MouseButtonPressed: {
                if (event.mouseButton.button == sf::Mouse::Left) {
                        Vector2f mouse = app.mapPixelToCoords(Mouse::getPosition(app));
                        if (domino_bounds.contains(mouse)) {
                            app.close();
                            DominoCarre c{domino_carre_h,domino_carre_w};
                            c.start();
                        } else if(trax_bounds.contains(mouse)){
                            app.close();
                            Trax c{};
                            c.start();
                        } else if(carcassonne_bounds.contains(mouse)){
                            app.close();
                            Carcassonne c{};
                            c.start();
                        }
                    }
                }
        }}
        app.clear(); 
        app.draw(text);
        app.draw(menuDomino);
        app.draw(menuTrax);
        app.draw(menuCarcassonne);
        app.display(); 
    } 
}



int main(int argc, char *argv[]) {
    srand(time(NULL));

    if(argc >= 2) {
        domino_carre_h = stoi(argv[1]);
        domino_carre_w = stoi(argv[2]);
        if(domino_carre_h < 5) domino_carre_h = 5;
        if(domino_carre_w < 5) domino_carre_w = 5;
    }

    openMenuPrincipal();
    return EXIT_SUCCESS;
}



