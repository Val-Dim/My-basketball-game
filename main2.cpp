#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Players{
    private:
    string name,position;
    int points;
    Players**arr;
    const int size=5;

    public:
    Players(string& name/*,string& position,int points*/);
    void setPoints(int points);
    int getPoints();
    void setNameFile(string& fileName);
    void setNamePlayer(string name);
    void printAll();
};

Players::Players(string& name/*,string& position,int points*/){
    this->name=name;
    // this->position=position;
    // this->points=points;
}

void Players::setPoints(int points){
    this->points=points;
}

int Players::getPoints(){
    return points;
}

void Players::setNamePlayer(string name){
    this->name=name;
    for(int i=0;i<size;i++){
        arr[i]=new Players(name);
    }
}

void Players::setNameFile(string& fileName){
    ifstream myfile(fileName);
    myfile.open(fileName);
    if(myfile.is_open()){
        string line;
        vector<string> names;
        while(getline(myfile,line)){
            names.push_back(line);
        }
        myfile.close();
        if(!names.empty()){
            for(int i=0;i<size;i++){
                arr[i]->setNamePlayer(names[i]);
            }
        }
    }  
}

void Players::printAll(){
    for(int i=0;i<size;i++){
    	cout<<name<</*","<<position<<*/endl;
    //cout<<"Points scored:"<<getPoints()<<"\n"<<endl;
    }
}

class Team{
    private:
    string playerName,playerPosition;
    Players**pl_array;
    string teamName,file;
    int plPoints;
    const int size=5;
    
    public:
    Team(string teamName);
    ~Team();
    int playerPoints(int plPoints);
    string getTeamName();
    void createPlayer(string file);
    void displayTeam();
};

Team::Team(string teamName){
    pl_array=new Players*[size];
    this->teamName=teamName;
}

// int Team::playerPoints(int plPoints){
//     for (int i = 0; i < size; i++){
//         pl_array[i]->setPoints(plPoints);
//     }
//     return plPoints;
// }

string Team::getTeamName(){
    return teamName;
}

void Team::createPlayer(string file){
    this->file=file;
    for(int i=0;i<size;i++){
        pl_array[i]->setNameFile(file);
    }
}

void Team::displayTeam(){
    cout<<getTeamName()<<endl;
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

int main(){
    srand((unsigned) time(0));
	int points = rand()%31;

    Team atlanta("Atlanta");
    atlanta.createPlayer("D:\\C++ programs\\Baketball game\\atlanta.txt");
    //atlanta.playerPoints(points);
    atlanta.displayTeam();
    atlanta.~Team();
    return 0;
}
