#include "game.h"
#include <fstream>
#include <iostream>

void Game::saveGame(Board* board) {
    std::ofstream outFile("saved_game.txt");  //skapar en fil för skrivning om den inte finns, om den finns så skrivs den över

    if(!outFile) {  //kontrollerar så det gick att öppna den sparade filen
        std::cout << "Fel vid öppning av sparade filen" << std::endl;
    }

    //sparar spelplanens dimensioner och minor sen loopar igenom spelplanen och skriver ut kompletta spelplanen till filen
    outFile << board->getRows() << " " << board->getCols() << " " << board->getMines() <<  std::endl;
    for(int i = 0; i < board->getRows(); i++) { 
        for(int j = 0; j < board->getCols(); j++) {
            outFile << board->getPlayBoard(i, j) << " ";
        }
        outFile << std::endl;
    }
    for(int i = 0; i < board->getRows(); i++) { 
        for(int j = 0; j < board->getCols(); j++) {
            outFile << board->getBoard(i, j) << " ";  //samma som innan fast sparar brädet med minorna
        }
        outFile << std::endl;
    }
    outFile.close();
    std::cout << "Spelet har sparats!" << std::endl;
};

Board* Game::loadGame() {
    std::ifstream inFile("saved_game.txt");

    if(!inFile) {
        std::cout << "Inget sparat spel finns" << std::endl;
        return nullptr;  //returnerar nullptr om det inte finns något sparat spel
    }

    int rows, cols, mines; //läser in första raden i filen som innehåller antalet rows, cols och minor
    inFile >> rows >> cols >> mines; 

    Board* board = new Board(rows, cols, mines); //skapar en ny spelplan men de värdena som lästs in 

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            char box; // variabel som lagrar en skild ruta med tex 0, flagga eller mina från filen på raden under
            inFile >> box; 
            board->setPlayBoard(i, j, box); //sätter boarden
        }
    }
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            char box; 
            inFile >> box; 
            board->setBoard(i, j, box);  //samma som förra fast brädan med minor 
        }
    }
    inFile.close();
    std::cout << "Spelet har laddats" << std::endl;

    return board;
};