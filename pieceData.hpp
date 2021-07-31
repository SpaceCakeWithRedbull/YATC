#pragma once
#include "piece.hpp"
#include "block.hpp"
#define noPieces 7

const int noBlocks = 4;

block OBlock(sf::Color::Yellow);
blockData Oblocks[noBlocks] = {
                            {.Block = OBlock, .rX = 0, .rY = 0},
                            {.Block = OBlock, .rX = 1, .rY = 0},
                            {.Block = OBlock, .rX = 0, .rY = 1},
                            {.Block = OBlock, .rX = 1, .rY = 1}};
pieceData OPiece = {.blocks=Oblocks,.noBlocks = noBlocks, .hasCenter = false} ;

block IBlock(sf::Color::Cyan);
blockData IBlocks[noBlocks] = {
    {.Block = IBlock, .rX = 0, .rY = 0},
    {.Block = IBlock, .rX = 1, .rY = 0},
    {.Block = IBlock, .rX = 2, .rY = 0},
    {.Block = IBlock, .rX =-1, .rY = 0}
};
pieceData IPiece = {.blocks=IBlocks,.noBlocks = noBlocks};

block TBlock(sf::Color::Magenta);
blockData TBlocks[noBlocks] = {
    {.Block = TBlock, .rX = 0, .rY = 0},
    {.Block = TBlock, .rX = 1, .rY = 0},
    {.Block = TBlock, .rX =-1, .rY = 0},
    {.Block = TBlock, .rX = 0, .rY = -1},
};
pieceData TPiece = {.blocks=TBlocks, .noBlocks =noBlocks};

//We've reached that point, but at least it has a nice in it
block LBlock(sf::Color(255,69,0));
blockData LBlocks[noBlocks] = {
    {.Block = LBlock, .rX = 0, .rY = 0},
    {.Block = LBlock, .rX = 1, .rY = 0},
    {.Block = LBlock, .rX = 1, .rY = 1},
    {.Block = LBlock, .rX =-1, .rY = 0},
};
pieceData LPiece = {.blocks=LBlocks, .noBlocks=noBlocks};

block JBlock(sf::Color::Blue);
blockData JBlocks[noBlocks] = {
    {.Block = JBlock, .rX = 0, .rY = 0},
    {.Block = JBlock, .rX = 1, .rY = 0},
    {.Block = JBlock, .rX =-1, .rY = 0},
    {.Block = JBlock, .rX =-1, .rY = 1},
};
pieceData JPiece = {.blocks=JBlocks, .noBlocks=noBlocks};

block SBlock(sf::Color::Green);
blockData SBlocks[noBlocks] = {
    {.Block = SBlock, .rX = 0, .rY = 0},
    {.Block = SBlock, .rX = 1, .rY = 0},
    {.Block = SBlock, .rX = 0, .rY = 1},
    {.Block = SBlock, .rX =-1, .rY = 1},
};
pieceData SPiece = {.blocks=SBlocks, .noBlocks=noBlocks};

block ZBlock(sf::Color::Red);
blockData ZBlocks[noBlocks] = {
    {.Block = ZBlock, .rX = 0, .rY = 0},
    {.Block = ZBlock, .rX =-1, .rY = 0},
    {.Block = ZBlock, .rX = 0, .rY = 1},
    {.Block = ZBlock, .rX = 1, .rY = 1},
};
pieceData ZPiece = {.blocks=ZBlocks, .noBlocks=noBlocks};

pieceData pieces[noPieces] = {TPiece,OPiece,IPiece,LPiece,JPiece,SPiece,ZPiece};