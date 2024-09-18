#include "board.h"
#include <vector>
#include <iostream>

Board::Board(int rows, int cols, int mines) : rows(rows), cols(cols), mines(mines) {
    board = std::vector<std::vector<char>>(rows, std::vector<char>(cols, '-')); //varje rad innehåller en vektor av cols och varje ruta fylls med -
};

void Board::displayBoard() {
    std::cout << "    "; // lägger till avstånd till siffrorna
    for (int i = 1; i <= cols; ++i) {  // skriver ut sifforna 1 till antaler cols
        std::cout << i << "  ";
    }
    std::cout << std::endl << "  +";
    for (int i = 0; i < cols; ++i) {  // skrive ut + i varje hörn och tre st - för varje col så det blir linjer
        std::cout << "---";
    }
    std::cout << "+" << std::endl;

    for (int i = 0; i < rows; i++) {  //går igenom antalet rows på planen
        // (char)('a' + i) konverterar en int till motsvarande bokstav, där i är radnumret 0 för a, 1 för b osv
        std::cout << (char)('a' + i) << " | "; 
        for (int j = 0; j < cols; j++) {
            std::cout << board[i][j] << "  "; 
        }  //går igenom varje kolumn på den nuvarande raden och skriver ut '-' från spelplanen board[i][j], där i raden och j kolumnen.
        std::cout << "|" << std::endl;
    }

    std::cout << "  +";
    for (int i = 0; i < cols; ++i) {
        std::cout << "---";
    }
    std::cout << "+" << std::endl;
};

void Board::placeMines() {


};