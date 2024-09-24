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
    outFile.close();
    std::cout << "Spelet har sparats!" << std::endl;
};