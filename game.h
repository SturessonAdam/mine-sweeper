#include "board.h"

class Game {

    private:
    Board board;


    public:
    Game(int rows, int cols, int mines);
    bool userInput(); //metod som ska hantera user inputs
    void startGame(); //metod som ska hantera spelet

};


