#include <player.h>

Players::Players(string& name,string& position,int points){
    this->name=name;
    this->position=position;
    this->points=points;
}

void Players::setPoints(int points){
    this->points=points;
}

int Players::getPoints(){
    return points;
}

void Players::setNamePos(string& name,string& position){
    this->name=name;
    this->position=position;
    cout<<"Enter player's name"<<endl;
    cin>>name;
    cout<<"Their position"<<endl;
    cin>>position;
}

void Players::printAll(){
    cout<<name<<","<<position<<endl;
    cout<<"Points scored:"<<getPoints()<<"\n"<<endl;
}
