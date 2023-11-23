#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Person {
private:
    std::string name;

public:
    Person() {} // Default constructor

    // Constructor that takes a name as an argument
    Person(const std::string& personName) : name(personName) {}

    // Method to set the name by reading from a file
    void setNameFromFile(const std::string& fileName) {
        std::ifstream file(fileName);
        if (file.is_open()) {
            std::vector<std::string> names;
            std::string line;
            while (std::getline(file, line)) {
                names.push_back(line);
            }
            file.close();

            if (!names.empty()) {
                // For simplicity, just use the first name in the file
                for (int i=0;i<5;i++){
                    name=names[i];
                    std::cout << "Name set from file: " << name << std::endl;
                }
                
            } else {
                std::cout << "File is empty" << std::endl;
            }
        } else {
            std::cout << "Unable to open file: " << fileName << std::endl;
        }
    }

    // Method to get the name
    std::string getName() const {
        return name;
    }
};

int main() {
    Person person;
    person.setNameFromFile("atlanta.txt");

    // Get and display the name
    std::cout << "Person's name: " << person.getName() << std::endl;

    return 0;
}
