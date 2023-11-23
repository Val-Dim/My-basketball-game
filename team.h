#include <iostream>
#include <cstdlib>

using namespace std;

class Team{
    private:
    string playerName,playerPosition;
    Players**pl_array;
    const int size=5;
    string teamName;
    int plPoints;

    public:
    Team(string teamName);
    ~Team();
    int playerPoints(int plPoints);
    string getTeamName();
    void createPlayer();
    void displayTeam();
};
