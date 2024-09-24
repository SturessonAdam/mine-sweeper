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
    void placeMines(); //funktion som ska placera ut minorna
    bool reveal(int row, int col); // funktion som ska avlöja användarens val på planen
    int countMines(int row, int col); // funktion som ska räkna minorna runt valda boxen
    void checkEmpty(int row, int col); //funktion som ska avslöja tomma rutor
    int getRows() const;
    int getCols() const;
    void flag(int row, int col); //funktion som flaggar rutor
    bool checkWin(); // funktion som ska kolla om alla rutor är utforskade
    char getPlayBoard(int row, int col) const; // funktion som ska hämta aktuella spelplanen
    void setPlayBoard(int row, int col, char value); // funktion som ska sätta aktuella spelplanen
    int getMines() const;

};



