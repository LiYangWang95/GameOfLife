#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
using namespace std;

class Cell{
    private:
        bool stateCur;
        bool statePrev;
        bool gameStarted;
        pair<int, int> coordinate;
        vector<Cell> nearByCells;
    public:
        Cell(){
            stateCur = false;
            statePrev = false;
            gameStarted = false;
        }
        Cell(int x, int y){
            stateCur = false;
            statePrev = false;
            gameStarted = false;
            coordinate.first = x;
            coordinate.second = y;
        }
        int getAliveNeighbors();
        bool cellState();
        void setNeighbors();
        void reset();
        void tick();
        void toggleState();
};

int Cell::getAliveNeighbors(){
    int aliveNum = 0;
    for(Cell c: nearByCells){
        if(c.cellState()){
            aliveNum++;
        }
    }
    return aliveNum;
}

bool Cell::cellState(){
    return stateCur;
}

void Cell::setNeighbors(){

}

void Cell::reset(){

}

void Cell::tick(){

}

void Cell::toggleState(){

}