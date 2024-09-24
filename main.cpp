#include <iostream>
#include "board.h"
#include "game.h"


//TODO : Spara och ladda spelet i Game class, flytta ytterligare logik till Game class



int main() {

    int boardSize;
    int mineSize;

    std::cout << std::endl;
    std::cout <<  "Välkommen till Adams grymma miniröj i terminalen" << std::endl;
    std::cout << std::endl;
    std::cout << "Hur stort bräde väll du spela på? Välja antal rader" << std::endl;
    std::cin >> boardSize;
    std::cout << "Hur många minor vill du ha till ditt bräde?" << std::endl;
    std::cin >> mineSize;

    Board* board = new Board(boardSize, boardSize, mineSize); //skapar spelarplanen med minor på heapen
    board->placeMines();
    std::cout << "Spelet startat, lycka till!" << std::endl;
    

    bool play = true;
    bool gameWon = false;

    while (play) {
        board->displayBoard();

        char choice; //om man vill flagga eller ej
        char rowInput;
        int colInput;  // koordinater av från spelarval

        /*std::cout << "Tryck 'F' för flagga eller 'A' för avslöja" << std::endl;
        std::cin >> choice;
        std::cout << std::endl;*/

        std::cout << "välj (f)lagga eller (a)vslöja följt av koordinat (exempel fa5 eller ab7)" << std::endl;
        std::cin >> choice >> rowInput >> colInput;
        std::cout << std::endl;


        //cin.fail kollar om inmatningen är en ogiltlig typ och returner true isf, isAlpha kollar så första tecknet är en char
        if (std::cin.fail() || (choice != 'F' && choice != 'f' && choice != 'A' && choice != 'a')
            || !isalpha(rowInput) || colInput <= 0) {
            std::cout << "Fel inmatning, försök igen." << std::endl;
            
            //åtterställer felstutusen på cin och ignorera den felaktiga inmatningen
            std::cin.clear();
            //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            //omvandlar input till index
            int row = rowInput - 'a';
            int col = colInput - 1;

            //kontrollerar om koordinaten är inom spelplanens gränser
            if (row >= board->getRows() || col >= board->getCols()) {
                std::cout << "Koordinaten är utanför spelplanen, försök igen." << std::endl;
            } else {
                if (choice == 'F' || choice =='f') { 
                    board->flag(row, col);
                } else if (choice == 'A' || choice == 'a') {
                    play = board->reveal(row, col);
                }
            }
        };

        if(board->checkWin()) {
            std::cout << std::endl << std::endl << "   Grattis du vann!! :)" << std::endl;
            gameWon = true;
            play = false;
        }
        
        if(!play || gameWon) { //skriver ut brädet igen om du play returnear false (du förlorar) eller om du vinner 
            board->displayBoard();
        }

    };

    delete board; //frigör minnet från heapen när spelet e klart
    

    return 0;
}