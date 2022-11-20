#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

    /*
        1. first iterated through and found max x and y values
        2. initialized board with those vector
    
        question: is it slow to pass a large map through methods?
    */
    
using namespace std;

vector<int> split(string s, string delim) { // input line, split by " -> ", then by comma, add to vector and return
    s.replace(s.find(delim), 4, ",");

    vector<int> output;
    stringstream ss(s);
    string token;
    char del = ',';

    while (!ss.eof()) {
        getline(ss, token, del);
        output.push_back(stoi(token));
    }
    return output;
}

int main() {
    ifstream file("dayFive.txt");
    vector<vector<int>> board (990, vector<int> (990));

    // vector<vector<int>> board (988, vector<int> (985));
    // vector<vector<int>> board (10, vector<int> (10));

    int sum;
    map<int, int> map;
    string input;

    while (!file.eof()) {
        getline(file, input);
        vector<int> coordinates = split(input, " -> ");
        
        if (coordinates[0] == coordinates[2] || coordinates[1] == coordinates[3]) {
            for (int i = 0; i <= abs(coordinates[2] - coordinates[0]); i++) {
                for (int j = 0; j <= abs(coordinates[3] - coordinates[1]); j++) {
                    board[min(coordinates[0], coordinates[2]) + i][min(coordinates[1], coordinates[3]) + j]++;
                    if (board[min(coordinates[0], coordinates[2]) + i][min(coordinates[1], coordinates[3]) + j] >= 2) {
                        string coordID = to_string(min(coordinates[0], coordinates[2]) + i) + to_string(min(coordinates[1], coordinates[3]) + j);
                        cout << coordID << " " << sum << endl;
                        if (map[stoi(coordID)] < 1) {
                            sum++;
                        }                        
                        map[stoi(coordID)]++;
                    }
                }
            }   
        }
    }
    int checkSum = 0;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] > 1) {
                checkSum++;
            }
        }
    }

    cout << endl << checkSum << " " << sum << endl;

    file.close();
}