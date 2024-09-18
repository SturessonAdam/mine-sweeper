#include "board.h"
#include <vector>
#include <iostream>
#include <cstdlib>   // för randomize
#include <ctime>   // för random tiden

Board::Board(int rows, int cols, int mines) : rows(rows), cols(cols), mines(mines) {
    board = std::vector<std::vector<char>>(rows, std::vector<char>(cols, '-')); //varje rad innehåller en vektor av cols och varje ruta fylls med -
    srand(time(0)); // för random tiden
    playBoard = std::vector<std::vector<char>>(rows, std::vector<char>(cols, '-')); // en ny spelplan med osynliga minorna
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
            std::cout << playBoard[i][j] << "  "; 
        }  //går igenom varje kolumn på den nuvarande raden och skriver ut '-' från spelplanen playBoard[i][j], där i raden och j kolumnen.
        std::cout << "|" << std::endl;
    }

    std::cout << "  +";
    for (int i = 0; i < cols; ++i) {
        std::cout << "---";
    }
    std::cout << "+" << std::endl;
};

void Board::placeMines() {
    int placedMines = 0;
    while (placedMines < mines) {
        int randMineRow = rand() % rows; // slumpar raden
        int randMineCol = rand() % cols; // slumpar kolumn

        // kollar så de randomizade cols och rows inte redan har en mina
        if (board[randMineRow][randMineCol] != '0') {
            board[randMineRow][randMineCol] = '0';
            placedMines++;
        }
    }

};