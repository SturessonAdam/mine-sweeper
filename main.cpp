#include <iostream>
#include "board.h"


//TODO : Felhantering input, flagga, vinna spelet, välja spelplan och minor, implementera spellogiken i Game?, VG-kraven


int main() {
    Board board(9, 9, 10); //skapar spelarplanen med minor
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