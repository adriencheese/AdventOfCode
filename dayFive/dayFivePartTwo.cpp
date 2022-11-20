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
    vector<int> output;
    
    if (!s.empty()) {
        s.replace(s.find(delim), 4, ",");

        stringstream ss(s);
        string token;
        char del = ',';

        while (!ss.eof()) {
            getline(ss, token, del);
            output.push_back(stoi(token));
        }
        return output;
    }
    return output;
}

int main() {
    ifstream file("dayFive.txt");
    vector<vector<int>> board (990, vector<int> (990));
    // vector<vector<int>> board (10, vector<int> (10));

    int sum;
    map<int, int> map;
    string input;

    while (!file.eof()) {
        getline(file, input);

        vector<int> coordinates = split(input, " -> ");

        int xa = coordinates[0], xb = coordinates[2], ya = coordinates[1], yb = coordinates[3];

        cout << xa << " " << xb << " " << ya << " " << yb << endl; 
        
        if (xa == xb || ya == yb) {
            for (int i = 0; i <= abs(xb - xa); i++) {
                for (int j = 0; j <= abs(yb - ya); j++) {
                    board[min(ya, yb) + j][min(xa, xb) + i]++;
                }
            }   
        } else if (ya < yb) {
            int difference = abs(yb - ya);
            if (xa < xb) {
                for (int i = 0; i <= difference; i++) {
                    board[ya + i][xa + i]++;
                }
            } else { // runs 4th
                for (int i = 0; i <= difference; i++) {
                    board[ya + i][xa - i]++;
                }
            }
        } else if (ya > yb) {
            int difference = abs(ya - yb);
            if (xa < xb) { // runs first
                for (int i = 0; i <= difference; i++) {
                    board[ya - i][xa + i]++;
                }
            } else {
                for (int i = 0; i <= difference; i++) {
                    board[ya - i][xa - i]++;
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

    cout << "check: " << checkSum << endl;
        
    }

    file.close();
}
