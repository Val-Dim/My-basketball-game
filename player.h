#include <iostream>
#include <cstdlib>

using namespace std;

class Players{
    private:
    string name;
    string position;
    int points;

    public:
    Players(string& name,string& position,int points);
    void setPoints(int points);
    int getPoints();
    void setNamePos(string& name,string& position);
    void printAll();
};
