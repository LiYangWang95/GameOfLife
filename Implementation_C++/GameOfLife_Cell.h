#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Cell{
    private:
        bool stateCur;
        bool statePrev;
        bool gameStarted;
        vector<Cell> nearByCells;
    public:
        Cell(){
            stateCur = false;
            statePrev = false;
            gameStarted = false;
        }
        int getAliveNeighbors();
        void setNeighbors();
        void reset();
        void tick();
        void toggleState();
};

int Cell::getAliveNeighbors(){

}

void Cell::setNeighbors(){

}

void Cell::reset(){

}

void Cell::tick(){

}

void Cell::toggleState(){

}