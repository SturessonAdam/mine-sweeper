#include <vector>

class Board {

    private:
    int rows; //rader för planen
    int cols; //kolumner för planen
    std::vector<std::vector<char>> board; //spelplanen (2d-vector)
    int mines;


    public:
    Board(int rows, int cols, int mines);
    void displayBoard();
    void placeMines(); //funktion som ska placera ut minorna


};



