#include "piece.hpp"
#include "board.hpp"
#include <iostream>

piece::piece(const piece &oldPiece)
{
    x = oldPiece.x;
    y = oldPiece.y;
    noBlocks = oldPiece.noBlocks;
    blocks = new blockData[noBlocks];
    for (int i = 0; i < noBlocks; i++)
    {
        blocks[i].Block = block(oldPiece.blocks[i].Block);
        blocks[i].rX = oldPiece.blocks[i].rX;
        blocks[i].rY = oldPiece.blocks[i].rY;
    }
}

piece::piece(pieceData pd)
{
    y = 0;
    x = board_width / 2;
    noBlocks = pd.noBlocks;
    blocks = new blockData[noBlocks];
    hasCenter = pd.hasCenter;
    for (int i = 0; i < pd.noBlocks; i++)
    {
        blocks[i].Block = block(pd.blocks[i].Block);
        blocks[i].rX = pd.blocks[i].rX;
        blocks[i].rY = pd.blocks[i].rY;
    }
}

piece::~piece()
{
    delete[] blocks;
}
int piece::getX()
{
    return x;
}

int piece::getY()
{
    return y;
}

void piece::setX(int newX)
{
    x = newX;
    for (int i = 0; i < noBlocks; i++)
    {
        blocks[i].Block.setX(x + blocks[i].rX);
    }
}

void piece::setY(int newY)
{
    y = newY;
    for (int i = 0; i < noBlocks; i++)
    {
        blocks[i].Block.setY(y + blocks[i].rY);
    }
}

blockData *piece::getBlocks()
{
    return blocks;
}

int piece::getNoBlocks()
{
    return noBlocks;
}

void piece::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < noBlocks; i++)
    {
        blocks[i].Block.draw(window);
    }
};

void piece::rotate(direction direction, board &board)
{
    if (hasCenter)
    {
        piece cpy = piece(*this);
        blockData *cpyBlocks = cpy.getBlocks();
        int cpyNoBlocks = cpy.getNoBlocks();
        int xmod = 1;
        int ymod = 1;

        switch (direction)
        {
        case (left):
            ymod = -1;
            break;
        case (right):
            xmod = -1;
            break;
        };
        for (int i = 0; i < cpyNoBlocks; i++)
        {
            int tmp = cpyBlocks[i].rX;
            cpyBlocks[i].rX = cpyBlocks[i].rY * xmod;
            cpyBlocks[i].rY = tmp * ymod;
        }
        cpy.setX(cpy.getX());
        cpy.setY(cpy.getY());

        if (!board.checkCollisions(cpy, 0, 0))
        {
            for (int i = 0; i < noBlocks; i++)
            {
                blocks[i].rX = cpyBlocks[i].rX;
                blocks[i].rY = cpyBlocks[i].rY;
            }
            setX(cpy.getX());
            setY(cpy.getY());
        }
    }
}
