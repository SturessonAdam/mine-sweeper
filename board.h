#include <vector>

class Board {

    private:
    int rows; //rader för planen
    int cols; //kolumner för planen
    std::vector<std::vector<char>> board; //spelplanen (2d-vector)


    public:
    Board(int rows, int cols);
    void displayBoard();


};



