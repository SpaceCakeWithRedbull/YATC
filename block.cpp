#include "block.hpp"
#include "board.hpp"
#include <iostream>

block::block(){}

block::block(sf::Color COLOR){
    color = COLOR;
    collidable = (color == sf::Color::Transparent)? false : true;
    rect = sf::RectangleShape(sf::Vector2f(tile_size,tile_size));
    rect.setFillColor(color);
    x = 0;
    y = 0;
    rect.setPosition(sf::Vector2f(x*tile_size,y*tile_size));
}

block::block(block &block){
    x = block.getX();
    y = block.getY();
    color = block.color;
    rect = block.rect;
    collidable = block.collidable;
}

void block::draw(sf::RenderWindow &window){
    window.draw(rect);
}

int block::getX(){
    return x;
}

int block::getY(){
    return y;
}
void block::setX(int newX){
    x = newX;
    rect.setPosition(sf::Vector2f(x*tile_size,y*tile_size));
}

void block::setY(int newY){
    y = newY;
    rect.setPosition(sf::Vector2f(x*tile_size,y*tile_size));
}

bool block::getCollidable(){
    return collidable;
}