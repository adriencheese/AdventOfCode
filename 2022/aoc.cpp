#include <iostream> 
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <queue>
#include <deque>

using namespace std;

// 2022

void d1p1() {
    fstream file("input.in");
    vector<int> reindeer;

    string line;
    int currentSum = 0;
    while(getline(file, line)) {
        if (line == "") {
            reindeer.push_back(currentSum);
            currentSum = 0;
            continue;
        }
        currentSum += stoi(line);
    }

    reindeer.push_back(currentSum);

    int high = INT_MIN;
    for (auto i : reindeer) {
        if (i > high) {
            high = i;
        }
    }

    cout << high;
}

void d1p2() {
    fstream file("input.in");
    vector<int> reindeer;

    string line;
    int currentSum = 0;
    while(getline(file, line)) {
        if (line == "") {
            reindeer.push_back(currentSum);
            currentSum = 0;
            continue;
        }
        currentSum += stoi(line);
    }

    reindeer.push_back(currentSum);

    nth_element(reindeer.begin(), reindeer.end(), reindeer.end());
    nth_element(reindeer.begin(), reindeer.end() - 1, reindeer.end());
    nth_element(reindeer.begin(), reindeer.end()- 2, reindeer.end());
    cout << reindeer[reindeer.size() - 1] << " " << reindeer[reindeer.size() - 2] << " " << reindeer[reindeer.size() - 3] << endl;
    int topThree = reindeer[reindeer.size() - 1] + reindeer[reindeer.size() - 2] + reindeer[reindeer.size() - 3];

    cout << topThree;
}

void d2p1() {
    fstream file("input.in");
    int winSum = 0, ourSum = 0;

    string line;
    while(getline(file, line)) {
        char first = line[0];
        char second = line[2];

        cout << first << ", " << second << endl;

        if (second == 'Y') { // we threw paper
            ourSum += 2;
            if (first == 'A') {
                winSum += 6;
            } else if (first == 'B') {
                winSum += 3;
            }
        } else if (second == 'X') { // we threw rock
            ourSum += 1;
            if (first == 'C') {
                winSum += 6;
            } else if (first == 'A') {
                winSum += 3;
            }
        } else if (second == 'Z') { // we threw scissors
            ourSum += 3;
            if (first == 'B') {
                winSum += 6;
            } else if (first == 'C') {
                winSum += 3;
            }
        }
    }

    cout << winSum + ourSum << endl;
}

void d2p2() {
    fstream file("input.in");
    int winSum = 0, ourSum = 0;

    string line;
    while(getline(file, line)) {
        char first = line[0];
        char second = line[2];

        if (second == 'X') { // lose
            if (first == 'A') {
                ourSum += 3;
            } else if (first == 'B') {
                ourSum += 1;
            } else {
                ourSum += 2;
            }
        } else if (second == 'Y') { // tie
            winSum += 3;
            if (first == 'A') {
                ourSum += 1;
            } else if (first == 'B') {
                ourSum += 2;
            } else {
                ourSum += 3;
            }
        } else if (second == 'Z') { // win
            winSum += 6;
            if (first == 'A') {
                ourSum += 2;
            } else if (first == 'B') {
                ourSum += 3;
            } else {
                ourSum += 1;
            }
        }
    }

    cout << winSum + ourSum << endl;
}

void d3p1() {
    fstream file("input.in");
    unordered_map<char, int> tracker;
    vector<char> shared;

    string line;
    while (getline(file, line)) {
        cout << "       " << line << endl;
        string a = line.substr(0, line.size() / 2);
        string b = line.substr(line.size() / 2);

        for (auto c : a) {
            tracker[c]++;
            if (tracker[c] > 1) {
                tracker[c]--;
            }
        }
        for (auto c : b) {
            tracker[c]++;
            cout << c << ", pre: " << tracker[c] << endl;
            if (tracker[c] > 1) {
                shared.push_back(c);
                cout << c << endl;
                tracker.clear();
                break;
            }
            tracker[c]--;
            cout << c << ", post: " << tracker[c] << endl;
        }
        tracker.clear();
    }

    int sum = 0;
    for (auto i : shared) {
        if (i >= 97 && i <= 122) {
            sum += i - 96;
        } else {
            sum += i - 38;
        }
    }

    cout << sum;
}

void d3p2() {
    fstream file("input.in");
    unordered_map<char, int> tracker;
    vector<char> shared;

    string a;
    while (getline(file, a)) {
        string b, c;
        getline(file, b); 
        getline(file, c);

        cout << endl << a << endl << b << endl << c << endl;

        for (auto i : a) {
            if (tracker[i] > 0) {
                continue;
            }
            tracker[i]++;
        }

        cout << "a" << endl;
        for (auto i : tracker) {
            cout << i.first << ": " << i.second << " ";;
        }
        cout << endl;

        for (auto i : b) {
            if (tracker[i] != 1) {
                continue;
            }
            tracker[i]++;
        }

        cout << "b" << endl;
        for (auto i : tracker) {
            cout << i.first << ": " << i.second << " ";;
        }
        cout << endl;
        
        for (auto i : c) {
            if (tracker[i] != 2) {
                continue;
            }
            tracker[i]++;
            cout << "last - " << i << ": " << tracker[i] << endl;
            if (tracker[i] > 2) {
                shared.push_back(i);
                tracker.clear();
                break;
            }
        }
    }

    int sum = 0;
    for (auto i : shared) {
        if (i >= 97 && i <= 122) {
            sum += i - 96;
        } else {
            sum += i - 38;
        }
    }

    cout << sum;
}

void d4p1() {
    fstream file("input.in");
    
    string line;

    int counter = 0;

    while (getline(file, line)) {
        line.replace(line.find("-"), 1, " ");
        line.replace(line.find("-"), 1, " ");
        line.replace(line.find(","), 1, " ");

        stringstream ss(line);

        int input;
        vector<int> ranges;

        while (ss >> input) {
            ranges.push_back(input);
        }

        if (((ranges[0] <= ranges[2]) && (ranges[1] >= ranges[3])) || ((ranges[0] >= ranges[2]) && (ranges[1] <= ranges[3]))) {
            counter++;
        } 
    }

    cout << counter;
}

void d4p2() {
    fstream file("input.in");
    
    string line;

    int counter = 0;

    while (getline(file, line)) {
        line.replace(line.find("-"), 1, " ");
        line.replace(line.find("-"), 1, " ");
        line.replace(line.find(","), 1, " ");

        stringstream ss(line);

        int input;
        vector<int> ranges;

        while (ss >> input) {
            ranges.push_back(input);
        }

        for (auto a : ranges) {
            cout << a << " ";
        }

        cout << endl;

        if (((ranges[0] <= ranges[2]) && (ranges[1] >= ranges[3])) || ((ranges[0] >= ranges[2]) && (ranges[1] <= ranges[3]))) {
            counter++;
            cout << counter << endl;
        } else if (((ranges[0] >= ranges[2]) && (ranges[0] <= ranges[3])) || ((ranges[2] <= ranges[1]) && (ranges[2] >= ranges[0]))) {
            counter++;
            cout << counter << endl;
        }
        cout << endl;
    }

    cout << counter;
}

void d5p1() {
    fstream file("input.in");
    vector<deque<char> > crates(9);

    string line;

    while (getline(file, line)) {
        if (line == "") {
            break;
        }

        for (int i = 0; i < 9; i++) {
            int pos = i * 4 + 1;
            
            if (line[pos] == ' ') {
                continue;
            }
            crates[i].push_back(line[pos]);
        }
    }

    line = "continue";

    while (getline(file, line)) {
        line.erase(line.find("move"), 5);
        line.erase(line.find("from"), 5);
        line.erase(line.find("to"), 3);

        stringstream ss(line);

        int amt, from, to;
        while (ss >> amt >> from >> to) {
            from--; to--;
            for (int i = 0; i < amt; i++) {
                crates[to].push_front(crates[from].front());
                crates[from].pop_front();
            }
        }
    }

    cout << "result: " << endl;

    for (auto i : crates) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void d5p2() {
    fstream file("input.in");
    vector<deque<char> > crates(9);

    string line;

    while (getline(file, line)) {
        if (line == "") {
            break;
        }

        for (int i = 0; i < 9; i++) {
            int pos = i * 4 + 1;
            
            if (line[pos] == ' ') {
                continue;
            }
            crates[i].push_back(line[pos]);
        }
    }

    line = "continue";

    while (getline(file, line)) {
        line.erase(line.find("move"), 5);
        line.erase(line.find("from"), 5);
        line.erase(line.find("to"), 3);

        stringstream ss(line);

        int amt, from, to;
        while (ss >> amt >> from >> to) {
            from--; to--;

            for (int i = amt - 1; i >= 0; i--) {
                crates[to].push_front(crates[from][i]);
                crates[from].erase(crates[from].begin() + i);
            }
        }
    }

    cout << "result: " << endl;

    for (auto i : crates) {
        cout << i.front();
    }
}

void d6p1() {
    fstream file("input.in");
    unordered_map<char, int> tracker;

    string line; getline(file, line);

    for (int i = 0; i < line.size(); i++) {
        tracker[line[i]]++;
        
        if (tracker.size() == 14) {
            cout << i + 1 << endl;
            break;
        }

        if (i > 12) {
            tracker[line[i - 13]]--;
            if (tracker[line[i - 13]] == 0) {
                tracker.erase(line[i - 13]);
            }
        }
    }
}

int main() {
    d7p1();
}