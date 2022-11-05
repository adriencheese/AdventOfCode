#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string input;
    vector<string> inputList;
    vector<vector<vector<int>>> boards;

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
        
        // add rows to 3d vector
        int boardNumber = 0;
        while (getline(file, input)) {
            boards.push_back(vector<vector<int>>());
            for (int i = 0; i < 5; i++) {
                getline(file, input);
                boards[boardNumber].push_back(vector<int>());
                
                // split the line into digits and add to values vector
                vector<int> values;
                num = "";
                for (int i = 0 ; i < input.size(); i++) {
                    if (i == input.size() - 1) {
                        values.push_back(stoi(num));
                        num = "";
                        continue;
                    }
                    if (input[i] != ' ') {
                        num.push_back(input[i]);
                    } else {
                        if (input[i + 1] == ' ') {
                            continue;
                        }
                        values.push_back(stoi(num));
                        cout << "values[" << i << "]: " << values[i] << endl;
 
                        num = "";
                    }
                }

                for (int i = 0; i < 5; i++) {
                    cout << "values[" << i << "]: " << values[i] << endl;
                    boards[boardNumber][i].push_back(values[i]);
                }
            }
            boardNumber++;
            cout << "boardNumber: " << boardNumber << endl;
        }

        for (int i = 0 ;i < boards.size(); i++) {
            cout << endl;
            for (int j = 0; j < boards[0].size(); j++) {
                cout << endl;
                for (int k = 0; k < boards[0][0].size(); k++) {
                    cout << boards[i][j][k] << " ";
                }
            }
        }
    }
}