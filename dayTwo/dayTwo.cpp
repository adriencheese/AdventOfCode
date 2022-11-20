#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int x = 0, y = 0, aim = 0;
    string input;
    vector<string> list;

    ifstream file("dayTwo.txt");

    if (file.is_open()) {
        while (getline(file, input)) {
            string direction = input.substr(0, input.find(" "));
            if (direction.compare("forward") == 0) {
                x += stoi(input.substr(input.find(" ")));
                y += aim * stoi(input.substr(input.find(" ")));
                cout << "forward: " << x << endl;
            } else if (direction.compare("down") == 0) {
                aim += stoi(input.substr(input.find(" ")));
                cout << "down: " << aim << endl;
            } else if (direction.compare("up") == 0) {
                aim -= stoi(input.substr(input.find(" ")));
                cout << "up: " << aim << endl;
            }
        }
    }

    cout << x * y;
}