#include "board.hpp"
#include "piece.hpp"
#include "block.hpp"
#include "pieceData.hpp"

class sf::Time;
class sf::Keyboard;

class Game{
    public:
        bool isGameOver();
        void input(sf::Keyboard keyboard,piece pce);
        void update(sf::Time dt);
    private:
        int dx, dy;
        bool gameOver;
        board board;
        piece* curPiece;
        sf::Time counter = sf::Time::Zero;
        int frameCounter = 0;
        sf::Keyboard keyboard;
};