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


        //cin.fail kollar om inmatningen är en ogiltlig typ och returner true isf, isAlpha kollar så första tecknet är en char
        if (std::cin.fail() || !isalpha(rowInput) || colInput <= 0) {
            std::cout << "Fel inmatning, försök igen." << std::endl;
            
            //åtterställer felstutusen på cin och ignorera den felaktiga inmatningen
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            //omvandlar input till index
            int row = rowInput - 'a';
            int col = colInput - 1;

            //kontrollerar om koordinaten är inom spelplanens gränser
            if (row >= board.getRows() || col >= board.getCols()) {
                std::cout << "Koordinaten är utanför spelplanen, försök igen." << std::endl;
            } else {
                play = board.reveal(row, col);
            }
        }


        
        if(!play) {
            board.displayBoard();
        }

    };
    


    return 0;
}