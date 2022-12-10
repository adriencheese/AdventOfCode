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

void d8p1() { // dp with 2d vector of 4 values (top, bottom, left, right)
                // from top left, fill in values of top and left
                // from bottom bottom right, fill in values of bottom and right
                // by comparing neighboring coordinates with respective direction
    ifstream file("input.in");
    vector<vector<int> > forest;
    int sol = 0;

    string line;

    int row = 0;
    while (getline(file, line)) {
        forest.push_back(vector<int>());
        for (char i : line) {
            forest[row].push_back(i - '0');
        }
        row++;
    }

    int xMax = forest[0].size();
    int yMax = forest.size();

    vector<vector<tuple<string, int, int> > > dp(yMax, vector<tuple<string, int, int> > (xMax, tuple("", 0, 0)));
// get<1> west - east
// get<2> north - south

    // from top left
    for (int x = 0; x < xMax; x++) { 
        for (int y = 0; y < yMax; y++) {

            if (y == 0 || x == 0) { // is there a better way to do this?
                if (y == 0) { // north border
                    get<0>(dp[y][x]).append("N");
                    get<2>(dp[y][x]) = forest[y][x];
                }
                if (x == 0) { // west border
                    get<0>(dp[y][x]).append("W");
                    get<1>(dp[y][x]) = forest[y][x];
                }
                continue;
            }

            if (get<1>(dp[y][x - 1]) < forest[y][x]) {
                get<0>(dp[y][x]).append("W");
            }
            get<1>(dp[y][x]) = max(forest[y][x], get<1>(dp[y][x - 1]));

            if (get<2>(dp[y - 1][x]) < forest[y][x]) {
                get<0>(dp[y][x]).append("N");
            }
            get<2>(dp[y][x]) = max(forest[y][x], get<2>(dp[y - 1][x]));
        }
    }

    for (int x = xMax - 1; x >= 0; x--) {
        for (int y = yMax - 1; y >= 0; y--) {
            if (y == yMax - 1 || x == xMax - 1) { // is there a better way to do this?
                if (y == yMax - 1) { // south border
                    get<0>(dp[y][x]).append("S");
                    get<2>(dp[y][x]) = forest[y][x];
                }
                if (x == xMax - 1) { // east border
                    get<0>(dp[y][x]).append("E");
                    get<1>(dp[y][x]) = forest[y][x];
                }
                continue;
            }

            if (get<2>(dp[y + 1][x]) < forest[y][x]) {
                get<0>(dp[y][x]).append("S");
            }
            get<2>(dp[y][x]) = max(forest[y][x], get<2>(dp[y + 1][x]));

            if (get<1>(dp[y][x + 1]) < forest[y][x]) {
                get<0>(dp[y][x]).append("E");
            }
            get<1>(dp[y][x]) = max(forest[y][x], get<1>(dp[y][x + 1]));
        }
    }
    for (int x = 0; x < xMax; x++) {
        for (int y = 0; y < yMax; y++) {
            if (!get<0>(dp[y][x]).empty()) {
                sol++;
            }
        }
    }

    cout << sol;
}

int d8p2findScore(const vector<vector<int> > &forest, int x, int y) {
    int xMax = forest[0].size();
    int yMax = forest.size();

    int N = 0, S = 0, E = 0, W = 0;

    for (int i = 1; i <= y; i++) { // check top
        // cout << "top: " << forest[y - i][x] << " - " << forest[y][x] << endl;
        if (forest[y - i][x] < forest[y][x]) {
            N++;
        } else if (forest[y - i][x] >= forest[y][x]) {
            N++;
            break;
        } else {
            break;
        }
        // cout << N << endl;
    }

    for (int i = 1; i <= (yMax - 1 - y); i++) { // check south
        // cout << "south: " << forest[y + i][x] << " - " << forest[y][x] << endl;
        if (forest[y + i][x] < forest[y][x]) {
            S++;
        } else if (forest[y + i][x] >= forest[y][x]) {
            S++;
            break;
        } else {
            break;
        }
        // cout << S << endl;
    }

    for (int i = 1; i <= (xMax - 1 - x); i++) { // check east
        // cout << "east: " << forest[y][x + i] << " - " << forest[y][x] << endl;
        if (forest[y][x + i] < forest[y][x]) {
            E++;
        } else if (forest[y][x + i] >= forest[y][x]) {
            E++;
            break;
        } else {
            break;
        }
        // cout << E << endl;
    }
    
    for (int i = 1; i <= x; i++) { // check west
        // cout << "west: " << forest[y][x - i] << " - " << forest[y][x] << endl;
        if (forest[y][x - i] < forest[y][x]) {
            W++;
        } else if (forest[y][x - i] >= forest[y][x]) {
            W++;
            break;
        } else {
            break;
        }
        // cout << W << endl;
    }

    // cout << N << ", " << S << ", " << W << ", " << E << endl;

    return (N * S * W * E);
}

void d8p2() {
    ifstream file("input.in");
    vector<vector<int> > forest;
    int sol = INT_MIN;

    string line;

    int row = 0;
    while (getline(file, line)) {
        forest.push_back(vector<int>());
        for (char i : line) {
            forest[row].push_back(i - '0');
        }
        row++;
    }

    int xMax = forest[0].size();
    int yMax = forest.size();

    for (int i = 1; i < yMax - 1; i++) {
        for (int j = 1; j < xMax - 1; j++) {
            // cout << j << ", " << i << " - " << forest[i][j] << endl;
            int score = d8p2findScore(forest, j, i);
            // cout << "result: " << j << ", " << i << " - " << score << endl;
            if (score > sol) {
                sol = score;
            }
            // cout << endl;
        }
    }
    cout << sol;
}

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};

void d9p1() { // get 3 under the correct solution
    ifstream file("input.in");
    // vector<vector<char> > board (5, vector<char> (5, ' '));
    unordered_map<pair<int, int>, int, hash_pair> coordinates;

    string line;
    pair<int, int> head (0, 0);
    pair<int, int> tail (0, 0);
    
    char lastDir = ' ';

    while (getline(file, line)) {
        char dir = line[0];
        int count = stoi(line.substr(line.find(" ") + 1));

        if (dir == 'R') {
            for (int i = 0; i < count; i++) {
                head.first++;
                
                if (abs(head.second - tail.second) > 1 || abs(head.first - tail.first) > 1) {
                    tail.first++;

                    if (head.second != tail.second && head.first != tail.first) {
                        if (lastDir == 'U') {
                            tail.second--;
                        } else if (lastDir == 'D') {
                            tail.second++;
                        }
                    }
                }

                coordinates[tail]++;
                // cout << "Rhead(" << head.first << ", " << head.second << "), tail(" << tail.first << ", " << tail.second << ")" << endl;

            }
        } else if (dir == 'U') {
            for (int i = 0; i < count; i++) {
                head.second--;
                
                if (abs(head.second - tail.second) > 1 || abs(head.first - tail.first) > 1) {
                    tail.second--;

                    if (head.second != tail.second && head.first != tail.first) {
                        if (lastDir == 'L') {
                            tail.first--;
                        } else if (lastDir == 'R') {
                            tail.first++;
                        }   
                    }
                }

                coordinates[tail]++;
                // cout << "Uhead(" << head.first << ", " << head.second << "), tail(" << tail.first << ", " << tail.second << ")" << endl;
            }
        } else if (dir == 'L') {
            for (int i = 0; i < count; i++) {
                head.first--;
                
                if (abs(head.second - tail.second) > 1 || abs(head.first - tail.first) > 1) {
                    tail.first--;

                    if (head.second != tail.second && head.first != tail.first) {
                        if (lastDir == 'U') {
                            tail.second--;
                        } else if (lastDir == 'D') {
                            tail.second++;
                        }
                    }
                }

                coordinates[tail]++;
                // cout << "Lhead(" << head.first << ", " << head.second << "), tail(" << tail.first << ", " << tail.second << ")" << endl;

            }
        } else if (dir == 'D') { // D
            for (int i = 0; i < count; i++) {
                head.second++;
                
                if (abs(head.second - tail.second) > 1 || abs(head.first - tail.first) > 1) {
                    tail.second++;

                    if (head.second != tail.second && head.first != tail.first) {
                        if (lastDir == 'L') {
                            tail.first--;
                        } else if (lastDir == 'R') {
                            tail.first++;
                        }   
                    }
                }

                coordinates[tail]++;
                // cout << "Dhead(" << head.first << ", " << head.second << "), tail(" << tail.first << ", " << tail.second << ")" << endl;

            }
        }
        
        lastDir = dir;
        // cout << "head(" << head.first << ", " << head.second << "), tail(" << tail.first << ", " << tail.second << ")" << endl;
    }

    // for (auto i : coordinates) {
    //     cout << "coord: " << i.first.first << ", " << i.first.second << endl;
    // }

    cout << coordinates.size() << endl;
}

int main() {
    d9p1();
}