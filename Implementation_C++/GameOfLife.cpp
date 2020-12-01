#include "GameOfLife_Cell.h"
#include "GameOfLife_GameOfLife.h"
using namespace std;

int main(){
    Cell c;
    GameOfLife t;
    int x = 0;
    while(x <= 10){
        t.tickTimer();
        x++;
        cout<<x<<endl;
    }
    return 0;
}