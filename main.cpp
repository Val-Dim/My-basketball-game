#include <iostream>
#include <cstdlib>
#include "team.h"
#include "player.h"

int main(){
    srand((unsigned) time(0));
	int points = rand()%31;

    Team atlanta("Atlanta");
    atlanta.createPlayer("atlanta.txt");
    //atlanta.playerPoints(points);
    atlanta.displayTeam();
    atlanta.~Team();
    return 0;
}
