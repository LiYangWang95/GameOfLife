#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
#ifndef ALIVE
#define ALIVE true
#endif
#ifndef DEAD
#define DEAD false
#endif
using namespace std;

class Cell{
    private:
        bool stateCur;
        bool stateNext;
        bool gameStarted;
        pair<int, int> coordinate;
        vector<Cell*> nearByCells;
        int getAliveNeighbors();
    public:
        Cell(){
            stateCur = DEAD;
            stateNext = DEAD;
            gameStarted = DEAD;
        }
        Cell(int row, int col){
            stateCur = DEAD;
            stateNext = DEAD;
            gameStarted = DEAD;
            coordinate.first = row;
            coordinate.second = col;
        }
        
        bool cellState();
        void setNeighbors(Cell*);
        void setState(bool);
        void updateState();
        void calNextState();
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
    return this->stateCur;
}

void Cell::setNeighbors(Cell* newNeighbor){
    nearByCells.push_back(newNeighbor);
}

void Cell::setState(bool newState){
    this->stateCur = newState;
}

void Cell::updateState(){
    this->stateCur = this->stateNext;
}

void Cell::calNextState(){
    int aliveNeighbor = getAliveNeighbors();
    this->stateNext = DEAD;
    if(this->stateCur == DEAD){
        if(aliveNeighbor == 3){
            this->stateNext = ALIVE;
        }
    }
    else{
        if(aliveNeighbor == 2 || aliveNeighbor == 3){
            this->stateNext = ALIVE;
        }
    }
}

void Cell::gameStatusChange(){
    gameStarted = !gameStarted;
}