#include "board.h"

class Game {

    private:
    
    public:
    void saveGame(Board* board);
    Board* loadGame();
    void playGame(Board* board);
    bool handleTurn(Board* board);
    bool checkInput(char choice, char rowInput, int colInput, Board* board);

};

