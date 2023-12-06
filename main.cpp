#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

class Players {
private:
    string name;
    int points;

public:
    Players(string name, int points);
    string getName();
    int getPoints();
};

Players::Players(string name, int points) {
    this->name = name;
    this->points = points;
}

string Players::getName() {
    return name;
}

int Players::getPoints() {
    return points;
}

class Team {
private:
    string teamName;
    const int size = 5;
    int totalPoints = 0;
    Players** player;
    int wins;

public:
    Team(string teamName);
    string getTeamName();
    void createPlayer(string file);
    int teamPoints();
    int getWins();
    void displayTeam();
};

Team::Team(string teamName) {
    this->teamName = teamName;
    this->wins=0;
}

string Team::getTeamName() {
    return teamName;
}

void Team::createPlayer(string file) {
    ifstream myfile(file);
    if (myfile.is_open()) {
        string line;
        vector<string> names;
        while (getline(myfile, line)) {
            names.push_back(line);
        }
        myfile.close();
        if (!names.empty()) {
            player = new Players*[size];
            for (int i = 0; i < names.size(); ++i) {
                player[i] = new Players(names[i], rand() % 31);
            }
        }
    }
}

int Team::teamPoints() {
    totalPoints = 0;
    for (int i = 0; i < size; i++) {
        totalPoints += player[i]->getPoints();
    }
    return totalPoints;
}

int Team::getWins(){
    wins++;
    return wins;
}

void Team::displayTeam() {
    cout << "Team " << getTeamName() << "->Total points:" << teamPoints() << endl;
    for (int i = 0; i < size; i++) {
        cout << player[i]->getName() << "->";
        cout << "Points scored:" << player[i]->getPoints() << endl;
    }
}

class Conference {
private:
    vector<Team> teams;

public:
    Conference() {};
    void getTeam(const Team& team);
    void confGames();
};

void Conference::getTeam(const Team& team) {
    teams.push_back(team);
}

void Conference::confGames() {
    for(int i=0;i<teams.size();i++){
        for(int j=i+1;j<teams.size();j++){
            cout<<teams[i].getTeamName()<<" vs "<<teams[j].getTeamName()<<endl;
            int pointsTeamI = teams[i].teamPoints();
            int pointsTeamJ = teams[j].teamPoints();
            if (pointsTeamI < pointsTeamJ) {
                cout << teams[j].getTeamName() << " wins!" << endl;
                teams[j].getWins();
            } else if (pointsTeamI > pointsTeamJ) {
                cout << teams[i].getTeamName() << " wins!" << endl;
                teams[i].getWins();
            }else{
                cout<<"Tie"<<endl;
            }
        }
            
    }
}


int main() {
    srand((unsigned)time(NULL));

    Team atlanta("Atlanta");
    Team dallas("Dallas");
    Team denver("Denver");
    dallas.createPlayer("dallas.txt");
    atlanta.createPlayer("atlanta.txt");
    denver.createPlayer("denver.txt");
    // dallas.displayTeam();
    // denver.displayTeam();
    // atlanta.displayTeam();

    Conference conf;
    conf.getTeam(atlanta);
    conf.getTeam(dallas);
    conf.getTeam(denver);
    conf.confGames();

    return 0;
}
