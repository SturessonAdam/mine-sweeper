#include <iostream>
#include "board.h"



int main() {
    Board board(6, 6, 5); //skapar en 6x6 spelplan med 5 minor
    board.placeMines();
    

    bool play = true;

    while (play) {
        board.displayBoard();

        char rowInput;
        int colInput;  // koordinater av från spelarval

        std::cout << "Vilken ruta vill du välja? ange rad med bokstav och kolumn med siffra" << std::endl;
        std::cin >> rowInput >> colInput;

        //omvandlar input till index
        int row = rowInput - 'a';
        int col = colInput - 1;

        play = board.reveal(row, col);

        if(!play) {
            board.displayBoard();
        }

    };
    


    return 0;
}