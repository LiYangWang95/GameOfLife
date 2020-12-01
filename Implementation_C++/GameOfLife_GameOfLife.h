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
        void nextGeneration();
        void resetAll();
        void startGame();
        void tickTimer();
};

void GameOfLife::nextGeneration(){

}

void GameOfLife::resetAll(){

}

void GameOfLife::startGame(){

}

void GameOfLife::tickTimer(){
    this_thread::sleep_for(chrono::milliseconds(tickInterval));
    return;
}