#include "board.hpp"
#include "piece.hpp"
#include "block.hpp"
#include <iostream>

board::board()
{
    border_color = sf::Color::White;
    leftBoard = sf::RectangleShape(sf::Vector2f(tile_size, board_height * tile_size));
    rightBoard = sf::RectangleShape(sf::Vector2f(tile_size, board_height * tile_size));
    bottomBoard = sf::RectangleShape(sf::Vector2f(tile_size * (board_width + 1), tile_size));
    leftBoard.setFillColor(border_color);
    rightBoard.setFillColor(border_color);
    bottomBoard.setFillColor(border_color);

    rightBoard.setPosition(sf::Vector2f(board_width * tile_size, 0.0f));
    bottomBoard.setPosition(sf::Vector2f(0.0f, board_height * tile_size));

    field = new block[board_width * board_height];
    for (int y = 0; y < board_height; y++)
    {
        for (int x = 0; x < board_width; x++)
        {
            field[y * board_width + x] = block(sf::Color::Transparent);
            field[y * board_width + x].setX(x);
            field[y * board_width + x].setY(y);
        }
    }
}

int board::checkCollisions(piece pce, int dy, int dx)
{
    piece cpy(pce);
    cpy.setX(pce.getX() + dx);
    cpy.setY(pce.getY() + dy);
    const int noBlocks = cpy.getNoBlocks();
    blockData *blocks = cpy.getBlocks();
    for (int i = 0; i < noBlocks; i++)
    {
        block Block(blocks[i].Block);
        int y = Block.getY();
        int x = Block.getX();
        if (field[y * board_width + x].getCollidable())
        {
            return true;
        }
        if (y == board_height || x == 0 || x == board_width)
        {
            return true;
        }
    }
    return false;
}

void board::draw(sf::RenderWindow &window)
{
    window.draw(leftBoard);
    window.draw(rightBoard);
    window.draw(bottomBoard);
    for (int i = 0; i < board_height * board_width; i++)
    {
        field[i].draw(window);
    }
}

void board::setBlock(block blk)
{
    field[blk.getY() * width + blk.getX()] = block(blk);
    //std::cout << field[blk.getY() * width + blk.getX()].getCollidable();
}

//Returns the number of lines cleared by placing the piece down
int board::setPiece(piece pce)
{
    int min = board_height;
    int max = 0;
    int linesCleared = 0;
    blockData *blocks = pce.getBlocks();
    for (int i = 0; i < pce.getNoBlocks(); i++)
    {
        int y = blocks[i].Block.getY();
        min = (y < min) ? y : min;
        max = (y > max) ? y : max;
        //std::cout << blocks[i].Block.getX();
        setBlock(blocks[i].Block);
    }
    if(min < 0){
        if(extraField == nullptr){
            extraField = new block[(min*-1 *board_width)];
        }
    }
    for(int line = min; line <= max; line++){
        //std::cout << min << " " << line << " " << max << " ";
        //std::cout << field[line*width + 0].getCollidable()  << "\n";
        if(checkLineIsFull(line)){
            removeLine(line);
            linesCleared++;
        }
    }
    return linesCleared;
}

bool board::checkLineIsFull(int line){
    //field index 0 is where the wall is, oops
    for(int i = 1; i < board_width; i++){
        //std::cout << field[line*board_width + i].getCollidable();
        if(!field[line*board_width + i].getCollidable()){
            return false;
        }
    }
    return true;
}

void board::removeLine(int line){
    //TODO make a proper animation for the line clear
    for(int i = 0; i < board_width; i++){
        field[line*board_width + i] = block(sf::Color::Transparent);
    }
    //y>1 maybe
    for(int y = line; y > 1; y--){
        for(int x = 0; x < board_width; x++){
            field[y*board_width+x] = field[(y-1)*board_width+x];
            field[y*board_width+x].setY(y);
        }
    }
}