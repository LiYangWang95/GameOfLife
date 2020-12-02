#include <thread>
#include <chrono>
#ifndef ALIVE
#define ALIVE true
#endif
#ifndef DEAD
#define DEAD false
#endif
using namespace std;

class GameOfLife{
    private:
        vector<vector<Cell>> cells;
        int col;
        int row;
        long tickInterval;
        void buildGameBoard();
    public:
        GameOfLife(){
            col = 5;
            row = 5;
            tickInterval = 100;
        }
        GameOfLife(int c, int r, int time){
            col = c;
            row = r;
            tickInterval = time;
        }
        void initialSetting(vector<pair<int, int>>&);
        void nextGeneration();
        void updateAll();
        void startGame();
        void tickTimer();
        void showGameBoard();
};

void GameOfLife::buildGameBoard(){
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
    pair<int, int> directionNeighbor[] = {
                                        make_pair(0, 1), make_pair(1, 1),
                                        make_pair(1, 0), make_pair(1, -1),
                                        make_pair(0, -1), make_pair(-1, -1),
                                        make_pair(-1, 0), make_pair(-1, 1)};
    
    // Set up game board
    buildGameBoard();

    // Set neighbors for all the cells
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            for(int k = 0; k < 8; k++){
                int rowNeighbor = i + directionNeighbor[k].first;
                int colNeighbor = j + directionNeighbor[k].second;
                if(rowNeighbor >= 0 && rowNeighbor < row && colNeighbor >= 0 && colNeighbor < col){
                    cells[i][j].setNeighbors(&cells[rowNeighbor][colNeighbor]);
                }
            }
        }
    }

    // Set initial conditions
    for(auto aliveCell: coordinates){
        cells[aliveCell.first][aliveCell.second].setState(ALIVE);
    }
    return;
}

void GameOfLife::nextGeneration(){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
           cells[i][j].calNextState();
        }
    }
}

void GameOfLife::updateAll(){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cells[i][j].updateState();
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

void GameOfLife::showGameBoard(){
    for(auto vectorRow: cells){
        for(auto cell: vectorRow){
           if(cell.cellState() == DEAD){
            cout<<" . ";
           }
           else{
               cout<<" O ";
           }
        }
        cout<<endl;
    }
    cout<<endl;
}