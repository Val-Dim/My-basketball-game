#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>

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
    int size = 5;
    mutable int totalPoints = 0;
    Players** player;
    int wins;

public:
    Team();
    Team(string teamName);
    string getTeamName();
    void createPlayer(string file);
    int teamPoints()const;
    void addWin(); 
    int getWins();
    void displayTeam();
};

Team::Team(){
}

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
                player[i] = new Players(names[i], rand() % 51);
            }
        }
    }
}

int Team::teamPoints() const{
    totalPoints = 0;
    for (int i = 0; i < size; i++) {
        totalPoints += player[i]->getPoints();
    }
    return totalPoints;
}

void Team::addWin(){
    wins++;
}

int Team::getWins(){
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
    void getTeam(Team& team);
    void sortTeams(vector<Team>& teams);
    void confGames();
    vector<Team> rankedTeams();
    void ranklist();
};

void Conference::getTeam(Team& team) {
    teams.push_back(team);
}

void Conference::sortTeams(vector<Team>& teams){
    sort(teams.begin(), teams.end(), [](const Team& a, const Team& b) {
        return a.teamPoints() > b.teamPoints();
    });
}

void Conference::confGames() {
    for(int i=0;i<teams.size();i++){
        for(int j=i+1;j<teams.size();j++){
            cout<<teams[i].getTeamName()<<" vs "<<teams[j].getTeamName()<<endl;
            int pointsTeamI = teams[i].teamPoints();
            int pointsTeamJ = teams[j].teamPoints();
            if (pointsTeamI < pointsTeamJ) {
                cout << teams[j].getTeamName() << " wins!" << endl;
                teams[j].addWin();
            } else if (pointsTeamI > pointsTeamJ) {
                cout << teams[i].getTeamName() << " wins!" << endl;
                teams[i].addWin();
            }else{
                cout<<"Tie"<<endl;
            }
        }       
    }
    //sortTeams(teams);
}

vector<Team> Conference::rankedTeams(){
    vector<Team>t=teams;
    sortTeams(t);
    return t;
}

void Conference::ranklist(){
    for(int i=0;i<teams.size();i++){
        cout<<teams[i].getTeamName()<<"-Wins: "<<teams[i].getWins()<<endl;
    }
}

class Tournament:public Conference{
    private:
    vector<Team>topTeams;

    public:
    Tournament():Conference(){}
    void setUp();
    void playMatches();
};

void Tournament::setUp(){
    vector<Team>foo=rankedTeams();

    for(int i=0;i<min(4,foo.size());i++){
        topTeams.push_back(foo[i]);
    }
}

void Tournament::playMatches(){
    int front=0;
    int back=topTeams.size()-1;
}

int main() {
    srand((unsigned)time(NULL));

    Team atlanta("Atlanta");
    Team dallas("Dallas");
    Team denver("Denver");
    Team lakers("Lakers");
    Team celtics("Celtics");
    dallas.createPlayer("dallas.txt");
    atlanta.createPlayer("atlanta.txt");
    denver.createPlayer("denver.txt");
    lakers.createPlayer("lakers.txt");
    celtics.createPlayer("celtics.txt");
    // dallas.displayTeam();
    // denver.displayTeam();
    // atlanta.displayTeam();

    Conference conf;
    conf.getTeam(atlanta);
    conf.getTeam(dallas);
    conf.getTeam(denver);
    conf.getTeam(lakers);
    conf.getTeam(celtics);
    conf.confGames();
    conf.ranklist();

    return 0;
}
