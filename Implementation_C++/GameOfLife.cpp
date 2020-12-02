#include "GameOfLife_Cell.h"
#include "GameOfLife_GameOfLife.h"
using namespace std;

int main(){
    Cell c;
    GameOfLife t;
    vector<pair<int, int>> tmp;

    t.initialSetting(tmp);
    t.showGameStatus();
    return 0;
}