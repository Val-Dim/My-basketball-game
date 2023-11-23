#include <team.h>
#include <player.h>

Team::Team(string teamName){
    pl_array=new Players*[size];
    this->teamName=teamName;
}

int Team::playerPoints(int plPoints){
    for (int i = 0; i < size; i++){
        pl_array[i]->setPoints(plPoints);
    }
    return plPoints;
}

string Team::getTeamName(){
    return teamName;
}

void Team::createPlayer(){
    for(int i=0;i<size;i++){
        pl_array[i]->setNamePos(playerName,playerPosition);
    }
}

void Team::displayTeam(){
    cout<<getTeamName<<endl;
    for (int i=0;i<size;i++){
        pl_array[i]->printAll();
    }
}

Team::~Team(){
    for (int i=0;i<size;i++){
        delete pl_array[i];
    }
    delete[] pl_array;
}
