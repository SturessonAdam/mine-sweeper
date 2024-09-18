#include <iostream>
#include "board.h"



int main() {
    Board board(5, 5, 6); //skapar en 5x5 spelplan
    board.placeMines();
    board.displayBoard();
    


    return 0;
}