#pragma once
#include <SFML/Graphics.hpp>


#define tile_size 25
#define board_width 10
#define board_height 20

class piece;
class block;

class board {
    public:
        board();
        int checkCollisions(piece pce, int dy, int dx);
        void setBlock(block Block);
        int setPiece(piece pce);

        //these two functions are seperate in case you want to implement a Tetris Effect style Perfectris system.
        bool checkLineIsFull(int line);
        void removeLine(int line);
    private:
        //learn vectors zach jfc.
        block *field;
        block *extraField = nullptr;
        int extraFieldSize = 0;
        //maybe modifying the board variables might be fun?
        const int width = board_width;
        const int height = board_height;

    //graphical nonsense
    public:
        void draw(sf::RenderWindow &window);
    private:
        sf::Color border_color;
        sf::RectangleShape leftBoard;
        sf::RectangleShape rightBoard;
        sf::RectangleShape bottomBoard;
};