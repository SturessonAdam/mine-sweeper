#ifndef BOARD_H
#define BOARD_H
#include <vector>

class Board {

    private:
    int rows; //rader för planen
    int cols; //kolumner för planen
    std::vector<std::vector<char>> board; //spelplanen (2d-vector)
    int mines;
    std::vector<std::vector<char>> playBoard; // spelplanen med osynliga minor


    public:
    Board(int rows, int cols, int mines);
    void displayBoard();
    void placeMines(); 
    bool reveal(int row, int col); 
    int countMines(int row, int col); 
    void checkEmpty(int row, int col); 
    int getRows() const;
    int getCols() const;
    void flag(int row, int col); 
    bool checkWin(); 
    char getPlayBoard(int row, int col) const;
    void setPlayBoard(int row, int col, char value); 
    int getMines() const;
    char getBoard(int row, int col) const;
    void setBoard(int row, int col, char value);

};

#endif

