#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int main() {
    string input;
    vector<string> inputList;
    vector<vector<vector<pair<int, int>>>> boards;

    ifstream file("dayFour.txt");

    if (file.is_open()) {
        char c;
        string num = "";

        getline(file, input);

        istringstream iss(input);

        // add called numbers to inputList as strings
        while (iss >> c) {
            if (c == ',') {
                inputList.push_back(num);
                num = "";
            } else {
                num.push_back(c);
            }
        }
        inputList.push_back(num);
        
        // add rows to 3d vector
        int boardNumber = 0;
        while (getline(file, input)) {
            // boards.push_back(vector<vector<pair<int, int>>>());
            vector<vector<pair<int, int>>> board;

            for (int i = 0; i < 5; i++) {
                getline(file, input);
                // boards[boardNumber].push_back(vector<pair<int, int>>());
                
                // split the line into digits and add to values vector
                vector<pair<int, int>> values;
                num = "";
                for (int j = 0 ; j < input.size(); j++) {
                    if (input[j] == ' ') {
                        if (num == "" || num.empty()) {
                            continue;
                        }
                        values.push_back(pair(stoi(num), 0));
                        num = "";
                    } else {
                        num.push_back(input[j]);
                    }
                }
                values.push_back(pair(stoi(num), 0));
            
                board.push_back(values);
            }
            boards.push_back(board);

            boardNumber++;
        }
    }

    map<int, int> tracker;
    int solvedBoardCount;
    int lastBoard;
    int lastDigit;

    for (int i = 0; i < inputList.size(); i++) {
        for (int j = 0 ; j < boards.size(); j++) {
            for (int k = 0; k < boards[j].size(); k++) {
                for (int l = 0; l < boards[l][k].size(); l++) {
                    // cout << boards[j][k][l].first << endl;
                        // if number called out, pair.second set to 1
                    if (boards[j][k][l].first == stoi(inputList[i])) {
                        boards[j][k][l].second = 1;
                    }
                        // bingo column!
                    if (boards[j][0][l].second == 1 && boards[j][1][l].second == 1 && boards[j][2][l].second == 1 && boards[j][3][l].second == 1 && boards[j][4][l].second == 1) {
                        int boardSum = 0;
                        for (int m = 0; m < boards[j].size(); m++) {
                            for (int n = 0; n < boards[j][m].size(); n++) {
                                if (boards[j][m][n].second == 0) {
                                    boardSum += boards[j][m][n].first;
                                }                            
                            }
                        }
                        tracker[j]++;
                        if (tracker[j] > 0) {
                            solvedBoardCount++;
                            cout << "solved: " << solvedBoardCount << endl;
                        }
                        if (solvedBoardCount == boards.size() - 1) {
                            lastDigit = boards[j][k][l].first;
                            lastBoard = j;
                            cout << "j: " << j << endl;
                        }
                    }
                        // bingo row!
                    if (boards[j][k][0].second == 1 && boards[j][k][1].second == 1 && boards[j][k][2].second == 1 && boards[j][k][3].second == 1 && boards[j][k][4].second == 1) {
                        int boardSum = 0;
                        for (int m = 0; m < boards[j].size(); m++) {
                            for (int n = 0; n < boards[j][m].size(); n++) {
                                if (boards[j][m][n].second == 0) {
                                    boardSum += boards[j][m][n].first;
                                }
                            }
                        }
                        tracker[j]++;
                        if (tracker[j] > 0) {
                            solvedBoardCount++;
                            cout << "solved: " << solvedBoardCount << endl;
                        }
                        if (solvedBoardCount == boards.size() - 1) {
                            lastDigit = boards[j][k][l].first;
                            lastBoard = j;
                            cout << "j: " << j << endl;
                        }
                    }
                }
            }
        }
    }

    int boardSum = 0;
    for (int m = 0; m < boards[lastBoard].size(); m++) {
        for (int n = 0; n < boards[lastBoard][m].size(); n++) {
            if (boards[lastBoard][m][n].second == 0) {
                boardSum += boards[lastBoard][m][n].first;
            }
        }
    }
    cout << boardSum * lastDigit << endl;


}