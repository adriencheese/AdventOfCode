#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ifstream file("daySix.txt");
    vector<int> list; 
    
    string input;
    getline(file, input);

    for (int i = 0; i < input.size(); i++) {
        if (input[i] == ',') {
            continue;
        }

        list.push_back((int)(input[i]) - '0');
    }

    for (int i = 0; i < 256; i++) {
        cout << i << endl;
        int initialSize = list.size();
        for (int j = 0; j < initialSize; j++) {
            --list[j];
            if (list[j] < 0) {
                list[j] = 6;
                list.push_back(8);
            }
        }
    }

    cout << list.size() << endl;
}