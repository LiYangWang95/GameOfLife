#include "GameOfLife_Cell.h"
#include "GameOfLife_GameOfLife.h"
using namespace std;

int main(){
    GameOfLife t;
    vector<pair<int, int>> tmp;
    tmp.push_back(make_pair(2, 2));
    tmp.push_back(make_pair(2, 3));
    tmp.push_back(make_pair(2, 4));

    t.initialSetting(tmp);
    t.startGame();
    t.showGameBoard();
    int curGeneration = 0, numOfGeneration = 5;
    while(curGeneration < numOfGeneration){
        t.nextGeneration();
        t.tickTimer();
        t.updateAll();
        t.showGameBoard();
        curGeneration++;
    }
    return 0;
}