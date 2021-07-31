#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "board.hpp"
#include "piece.hpp"
#include "block.hpp"
#include "pieceData.hpp"
#include <iostream>
#define char_size 24
#define screen_width 25
#define screen_height 40

int main()
{
    board Board;
    int random_number = rand() % noPieces;
    piece *pce = new piece(pieces[random_number]);
    sf::Text noPoints;
    sf::Text noLines;
    sf::Font font;
    sf::Keyboard keyboard;
    int dx, dy;
    unsigned int linesCleared = 0;
    bool gameOver = false;

    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "error loading file";
        return 1;
    }

    sf::RenderWindow window(sf::VideoMode(tile_size * screen_width, tile_size * screen_height), "Tetris!");

    sf::Clock clock;
    sf::Time gameTick = sf::Time::Zero;
    sf::Time inputTimer = sf::Time::Zero;
    bool keypress = false;
    while (window.isOpen())
    {
        window.clear();
        sf::Event event;
        if (!gameOver)
        {
            pce->draw(window);
            random_number = rand() % noPieces;
            sf::Time elapsed = clock.restart();
            gameTick += elapsed;
            inputTimer += elapsed;

            dx = 0;
            dy = 0;

            if (inputTimer.asMilliseconds() > 100)
            {
                dx = 0;
                dy = 0;
                if (keyboard.isKeyPressed(sf::Keyboard::A))
                {
                    pce->rotate(left, Board);
                }
                if (keyboard.isKeyPressed(sf::Keyboard::D))
                {
                    pce->rotate(right, Board);
                }
                if (keyboard.isKeyPressed(sf::Keyboard::Left))
                {
                    dx = -1;
                    keypress = true;
                }
                if (keyboard.isKeyPressed(sf::Keyboard::Right))
                {
                    dx = 1;
                }
                if (keyboard.isKeyPressed(sf::Keyboard::Down))
                {
                    dy = 1;
                }
                if (!Board.checkCollisions(*pce, 0, dx))
                {
                    pce->setX(pce->getX() + dx);
                }
                if (!Board.checkCollisions(*pce, dy, 0))
                {
                    pce->setY(pce->getY() + dy);
                }
                inputTimer = sf::Time::Zero;
            }
            if (gameTick.asMilliseconds() > 1000)
            {
                dy = 1;
                if (!Board.checkCollisions(*pce, dy, 0))
                {
                    pce->setY(pce->getY() + dy);
                }
                else
                {
                    linesCleared += Board.setPiece(*pce);
                    std::cout << linesCleared << "\n";
                    delete pce;
                    pce = new piece(pieces[random_number]);
                    if(Board.checkCollisions(*pce,0,0)){
                        gameOver = true;
                    }
                }
                gameTick = sf::Time::Zero;
            }
            Board.draw(window);
            window.draw(noLines);
            window.draw(noPoints);
            window.display();
        }
                while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
    }
}