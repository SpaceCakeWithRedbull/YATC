#pragma once
#include <SFML/Graphics.hpp>

class block {
    public:
        block();
        block(sf::Color COLOR);
        block(block &Block);
        int getX();
        int getY();
        void setX(int newX);
        void setY(int newY);
        bool getCollidable();
    private:
        bool collidable;
        int x, y;
        sf::Color color;
        sf::RectangleShape rect; 

    public: 
        void draw(sf::RenderWindow &window);  
};