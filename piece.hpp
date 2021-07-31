#pragma once
#include <SFML/Graphics.hpp>
#include "block.hpp"

class board;

enum direction {
    left,
    right,
    vertFlip,
    horFlip
};


//if can be bothered, convert this to a linked list or learn how to 
//use c++ vectors. obvious exploit potential in multiple points
//in program
struct blockData{
    block Block;
    int rX = 0;
    int rY = 0;
};

struct pieceData{
    blockData* blocks;
    int noBlocks;
    bool hasCenter = true;
};

class piece {
    public:
        piece(const piece& oldPiece);
        piece(pieceData pd);
        ~piece();
        int getX();
        int getY();
        void setX(int newX);
        void setY(int newY);
        int getNoBlocks();
        blockData* getBlocks();
    protected:
        int x;
        int y;
        //yes son.... would i lie? ( ͡° ͜ʖ ͡°)
        int noBlocks;
        blockData *blocks;
        bool hasCenter;
        //TODO: Make blocks spawn in with a random rotation
    public:
        void draw(sf::RenderWindow &window);
        void rotate(direction direction, board &board);
};
