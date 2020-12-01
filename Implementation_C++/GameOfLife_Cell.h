#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
using namespace std;

class Cell{
    private:
        bool stateCur;
        bool stateNext;
        bool gameStarted;
        pair<int, int> coordinate;
        vector<Cell*> nearByCells;
    public:
        Cell(){
            stateCur = false;
            stateNext = false;
            gameStarted = false;
        }
        Cell(int row, int col){
            stateCur = false;
            stateNext = false;
            gameStarted = false;
            coordinate.first = row;
            coordinate.second = col;
        }
        int getAliveNeighbors();
        bool cellState();
        void setNeighbors(Cell*);
        void setState(bool);
        void updateState();
        void getNextState();
        void gameStatusChange();
};

int Cell::getAliveNeighbors(){
    int aliveNum = 0;
    for(auto c: nearByCells){
        if(c->cellState()){
            aliveNum++;
        }
    }
    return aliveNum;
}

bool Cell::cellState(){
    return stateCur;
}

void Cell::setNeighbors(Cell* newNeighbor){
    nearByCells.push_back(newNeighbor);
}

void Cell::setState(bool newState){
    stateCur = newState;
    return;
}

void Cell::updateState(){
    stateCur = stateNext;
    return;
}

void Cell::getNextState(){
    int aliveNeighbor = this->getAliveNeighbors();
    stateNext = false;
    if(!stateCur){
        if(aliveNeighbor == 3){
            stateNext = true;
        }
    }
    else{
        if(aliveNeighbor == 2 || aliveNeighbor == 3){
            stateNext = true;
        }
    }
    return;
}

void Cell::gameStatusChange(){
    gameStarted = !gameStarted;
}