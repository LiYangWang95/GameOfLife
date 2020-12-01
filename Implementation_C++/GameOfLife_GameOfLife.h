#include <thread>
#include <chrono>
using namespace std;

class GameOfLife{
    private:
        vector<vector<Cell>> cells;
        int col;
        int row;
        long tickInterval;
    public:
        GameOfLife(){
            col = 5;
            row = 5;
            tickInterval = 1000;
        }
        GameOfLife(int c, int r, int time){
            col = c;
            row = r;
            tickInterval = time;
        }
        void buildGameTable();
        void initialSetting(vector<pair<int, int>>&);
        void nextGeneration();
        void updateAll();
        void startGame();
        void tickTimer();
};

void GameOfLife::buildGameTable(){
    for(int i = 0; i < row; i++){
        vector<Cell> tmpRow;
        for(int j = 0; j < col; j++){
            Cell tmpCell(i, j);
            tmpRow.push_back(tmpCell);
        }
        cells.push_back(tmpRow);
    }
}

void GameOfLife::initialSetting(vector<pair<int, int>>& coordinates){
    
}

void GameOfLife::nextGeneration(){
    for(auto vectorRow: cells){
        for(auto cell: vectorRow){
           cell.getNextState();
        }
    }
}

void GameOfLife::updateAll(){
    for(auto vectorRow: cells){
        for(auto cell: vectorRow){
            cell.updateState();
        }
    }
}

void GameOfLife::startGame(){
    for(auto vectorRow: cells){
        for(auto cell: vectorRow){
            cell.gameStatusChange();
        }
    }
}

void GameOfLife::tickTimer(){
    this_thread::sleep_for(chrono::milliseconds(tickInterval));
    return;
}