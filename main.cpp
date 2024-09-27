#include <iostream>
#include "board.h"
#include "game.h"


//TODO : Klar! :)



int main() {

    Game game;

    int boardSize;
    int mineSize;
    char loadChoice;

    Board* board = nullptr;

    std::cout << std::endl;
    std::cout <<  "Välkommen till Adams grymma miniröj i terminalen" << std::endl;
    std::cout << std::endl;

    std::cout << "Vill du ladda ett sparat spel? (j/n)" << std::endl;
    std::cin >> loadChoice;
    if (loadChoice == 'j' || loadChoice == 'J') {
        board = game.loadGame();
    } else {
        std::cout << "Hur stort bräde väll du spela på? Välja antal rader" << std::endl;
        std::cin >> boardSize;
        std::cout << "Hur många minor vill du ha till ditt bräde?" << std::endl;
        std::cin >> mineSize;

        board = new Board(boardSize, boardSize, mineSize); //skapar spelarplanen med minor på heapen
        board->placeMines();
    }

    game.playGame(board);
    
    delete board; //frigör minnet från heapen för att förhindra minnesläcka

    return 0;
}