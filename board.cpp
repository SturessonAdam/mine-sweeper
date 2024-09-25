#include "board.h"
#include <vector>
#include <iostream>
#include <cstdlib>   
#include <ctime>   

Board::Board(int rows, int cols, int mines) : rows(rows), cols(cols), mines(mines) {
    board = std::vector<std::vector<char>>(rows, std::vector<char>(cols, '#')); //varje rad innehåller en vektor av cols och varje ruta fylls med en char
    srand(time(0));
    playBoard = std::vector<std::vector<char>>(rows, std::vector<char>(cols, '#')); // en ny spelplan med osynliga minorna
};

void Board::displayBoard() {
    std::cout << "     "; // lägger till avstånd till siffrorna
    for (int i = 1; i <= cols; ++i) {  // skriver ut sifforna 1 till antaler cols
        std::cout << i << "  ";
    }
    std::cout << std::endl << "  +--";
    for (int i = 0; i < cols; ++i) {  // skrive ut + i varje hörn och tre st - för varje col så det blir linjer
        std::cout << "---";
    }
    std::cout << "+" << std::endl;

    for (int i = 0; i < rows; i++) {  //går igenom antalet rows på planen
        // (char)('a' + i) konverterar en int till motsvarande bokstav, där i är radnumret 0 för a, 1 för b osv
        std::cout << (char)('a' + i) << " |  "; 
        for (int j = 0; j < cols; j++) {
            std::cout << playBoard[i][j] << "  "; 
        }  //går igenom varje kolumn på den nuvarande raden och skriver ut '-' från spelplanen playBoard[i][j], där i raden och j kolumnen.
        std::cout << "|" << std::endl;
    }

    std::cout << "  +--";
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
        if (board[randMineRow][randMineCol] != 'X') {
            board[randMineRow][randMineCol] = 'X';
            placedMines++;
        }
    }

};

bool Board::reveal(int row, int col) {
    if(board[row][col] == 'X') {  //kollar om det finns en mina i board och uppdaterar playboarden med minan
        playBoard[row][col] = 'X';
        std::cout << std::endl << std::endl << "  BOOM! du träffade en mina, GAME OVER!" << std::endl;
        return false;
    } else {
        int aroundMines = countMines(row, col);
        if (aroundMines > 0) {
            playBoard[row][col] = '0' + aroundMines; //konventerar inten till char 
        } else {
            checkEmpty(row, col);
        }
        return true;
    }

};

int Board::countMines(int row, int col) {
    int mineCount = 0;

    //går igenom alla rutor runt den valda rutan
    for(int i = -1; i <= 1; i++) {  // loop för att kolla row -1, 0, 1 (raden över, samma rad och raden nedanför)
        for(int j = -1; j <= 1; j++) { // loop för att kolla col -1, 0, 1 (kolumnen vänster, samma koulmn och kolumnen höger)
            int newRow = row + i;
            int newCol = col + j;

            //kontroll så vi inte går utanför spelplanen
            if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                if(board[newRow][newCol] == 'X') {
                    mineCount++;  //om vi hittar en mina så öknar vi mineCount
                }
            }
        } 
    }
    return mineCount;

};

void Board::checkEmpty(int row, int col) {
    //kontrollera om vi är innanöför spelplanen
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        return;
    }
    //kontrollerar  om rutan redan är avslöjad
    if (playBoard[row][col] != '#') {
        return;
    }

    int aroundMines = countMines(row, col);

    if(aroundMines > 0) {
        playBoard[row][col] = '0' + aroundMines; //kontrollerar minan
    } else {
        playBoard[row][col] = 'O';
        //återanvände samma kod/logik som är i countMines
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) { 
            int newRow = row + i;
            int newCol = col + j;
                if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                    if(playBoard[newRow][newCol] == '#') {
                        checkEmpty(newRow, newCol); //anropar metoden igen rekursivt tills mina hittas
                    }
                }
            }
        }
    }
};

int Board::getRows() const {
    return rows;
};

int Board::getCols() const {
    return cols;
}

void Board::flag(int row, int col){  // om rutan inte är avslöjad sätt F och vice versa
    if(playBoard[row][col] == '#' ){
        playBoard[row][col] = 'F';
    } else if (playBoard[row][col] == 'F') {
        playBoard[row][col] = '#';
    }
};

bool Board::checkWin() {
    int flaggedMines = 0;
    int exploredBoxes = 0;

    for(int i = 0; i < rows; i++){ //går igenom spelbrädet
        for(int j= 0; j < cols; j++ ){
            if(playBoard[i][j] == 'F' && board[i][j] == 'X') { //kollar efter flaggor
                flaggedMines++;
            }
            if(playBoard[i][j] != '#' && playBoard[i][j] != 'F') { //kollar utforskade rutor
                exploredBoxes++;
            }
        }
    }
    return (flaggedMines == mines) && (exploredBoxes == (rows * cols - mines)); //när flaggade minor uppnår antalet minor och utforskade rutor uppfyller brädet - minorna
};

char Board::getPlayBoard(int row, int col) const {
    return playBoard[row][col];
};

void Board::setPlayBoard(int row, int col, char value) {
    playBoard[row][col] = value;
};

int Board::getMines() const {
    return mines;
};

char Board::getBoard(int row, int col) const {
    return board[row][col];
};
void Board::setBoard(int row, int col, char value) {
    board[row][col] = value;
};