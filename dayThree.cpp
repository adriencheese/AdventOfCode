#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int convert(long long n) {
  int dec = 0, i = 0, rem;

  while (n!=0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    ++i;
  }

  return dec;
}

string partTwo(vector<string> list, bool oxy, int i) {
    if (list.size() == 1) {
        cout << list[0] << " " << oxy << endl;
        return list[0];
    }

    unordered_map<int, int> map;

    for (int j = 0; j < list.size(); j++) {
        map[list[j][i] - '0']++;
    }

    vector<int> eraseList;

    if (oxy == true) {
        if (map[0] > map[1]) {
            for (int k = list.size() - 1; k >= 1; --k) {
                if (list[k][i] - '0' == 1) {
                    list.erase(list.begin() + k);
                }
            }
        } else if (map[0] < map[1] || map[0] == map[1]) {
            for (int k = list.size() - 1; k >= 0; --k) {
                if (list[k][i] - '0' == 0) {
                    list.erase(list.begin() + k);
                } 
            }
        }
    } else {
        if (map[0] > map[1]) {
            for (int k = list.size() - 1; k >= 0; --k) {
                if (list[k][i] - '0' == 0) {
                    list.erase(list.begin() + k);
                } 
            }
        } else if (map[0] < map[1] || map[0] == map[1]) {
            for (int k = list.size() - 1; k >= 0; --k) {
                if (list[k][i] - '0' == 1) {
                    list.erase(list.begin() + k);
                } 
            }
        }
    }

    map[0] = map[1] = 0;
    i++;

    cout << "listsize: " << list.size() << ", i: " << i << ", oxy: " << oxy << endl;

    return partTwo(list, oxy, i);
}

int main() {
    cout << fixed;
    string input;
    double gammaRate = 0, epsilonRate = 0;
    vector<string> list;
    unordered_map<int, int> map;

    ifstream file("dayThree.txt");

    if (file.is_open()) {
        while (getline(file, input)) {
            list.push_back(input);
        }
    }

    string oxy = partTwo(list, true, 0);

    string co = partTwo(list, false, 0);

    cout << oxy << " " << convert(stod(oxy)) << endl << co << " " << convert(stod(co)) << endl;
    cout << convert(stod(oxy)) * convert(stod(co));
    
        // part one
    // for (int i = 0 ; i < 12; i++) {
    //     for (int j = 0; j < list.size(); j++) {
    //         map[list[j][i] - '0']++;
    //     }

    //     if (map[0] > map[1]) {
    //         gammaRate += pow(10, 11 - i) * 0;
    //         epsilonRate += pow(10, 11 - i) * 1;
    //     } else {
    //         gammaRate += pow(10, 11 - i) * 1;
    //         epsilonRate += pow(10, 11 - i) * 0;
    //     }

    //     map[0] = 0;
    //     map[1] = 0;
    // }
    // cout << convert(gammaRate) * convert(epsilonRate);

    
}
