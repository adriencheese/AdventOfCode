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

using namespace std;

void d1p2() {
	int n;
	int count;
	vector<int> list;

	ifstream file("dayOne.txt");

	if (file.is_open()) {
		while (file >> n) {
			list.push_back(n);
		}
		for (int i = 0; i < list.size()-3; i++) {
			if (list[i] + list[i+1] + list[i+2] < list[i+1] + list[i+2] + list[i+3]) {
				count++;
			}
		}
	}
	cout << count;
}
void d2p2() {
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

void d3p1() {
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

    for (int i = 0 ; i < 12; i++) {
        for (int j = 0; j < list.size(); j++) {
            map[list[j][i] - '0']++;
        }

        if (map[0] > map[1]) {
            gammaRate += pow(10, 11 - i) * 0;
            epsilonRate += pow(10, 11 - i) * 1;
        } else {
            gammaRate += pow(10, 11 - i) * 1;
            epsilonRate += pow(10, 11 - i) * 0;
        }

        map[0] = 0;
        map[1] = 0;
    }
    cout << convert(gammaRate) * convert(epsilonRate);
}

string d3p2(vector<string> list, bool oxy, int i) {
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

    return d3p2(list, oxy, i);
}

void d3() {
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

    string oxy = d3p2(list, true, 0);

    string co = d3p2(list, false, 0);

    cout << oxy << " " << convert(stod(oxy)) << endl << co << " " << convert(stod(co)) << endl;
    cout << convert(stod(oxy)) * convert(stod(co));
}

void d4p1() {
    string input;
    vector<string> inputList;
    vector<vector<vector<pair<int, int> > > > boards;

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
            // boards.push_back(vector<vector<pair<int, int> >>());
            vector<vector<pair<int, int> > > board;

            for (int i = 0; i < 5; i++) {
                getline(file, input);
                // boards[boardNumber].push_back(vector<pair<int, int> >());
                
                // split the line into digits and add to values vector
                vector<pair<int, int> > values;
                num = "";
                for (int j = 0 ; j < input.size(); j++) {
                    if (input[j] == ' ') {
                        if (num == "" || num.empty()) {
                            continue;
                        }
                        values.push_back(make_pair(stoi(num), 0));
                        num = "";
                    } else {
                        num.push_back(input[j]);
                    }
                }
                values.push_back(make_pair(stoi(num), 0));
            
                board.push_back(values);
            }
            boards.push_back(board);

            boardNumber++;
        }
    }
    
    int a = 1;
    int b = 1;
    int c = 1;
    int d = 1;

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

                    // cout << "test: " << boards[j][0][l].first << " " <<  boards[j][0][l].second << boards[j][1][l].first << " " << boards[j][1][l].second << " " << boards[j][2][l].first << " " << boards[j][2][l].second << " " << boards[j][3][l].first << " " << boards[j][3][l].second << " " << boards[j][4][l].first << " " << boards[j][4][l].second << " " << endl;
                    if (boards[j][0][l].second == 1 && boards[j][1][l].second == 1 && boards[j][2][l].second == 1 && boards[j][3][l].second == 1 && boards[j][4][l].second == 1) {
                        a = 0;
                        int columnSum = boards[j][0][l].first + boards[j][1][l].first + boards[j][2][l].first + boards[j][3][l].first + boards[j][4][l].first; 
                        int boardSum = 0;
                        for (int m = 0; m < boards[j].size(); m++) {
                            for (int n = 0; n < boards[j][k].size(); n++) {
                                boardSum += boards[j][k][l].first;
                            }
                        }
                        cout << "first: " << boards[j][k][l].first << " ";
                        cout << "j k l (" << j << " " << k << " " << l << "): " << boards[j][k][l].first * (boardSum - columnSum) << endl;
                        cout << boards[j][k][l].first * (boardSum - columnSum) << endl;
                        break;
                    }
                        // bingo row!
                    
                    // cout << "test: " << boards[j][k][l].second << endl;
                    if (boards[j][k][0].second == 1 && boards[j][k][1].second == 1 && boards[j][k][2].second == 1 && boards[j][k][3].second == 1 && boards[j][k][4].second == 1) {
                        a = 0;
                        int boardSum = 0;

                        for (int m = 0; m < boards[j].size(); m++) {
                            for (int n = 0; n < boards[j][m].size(); n++) {
                                if (boards[j][m][n].second == 0) {
                                    boardSum += boards[j][m][n].first;
                                    cout << "boardSum: " << boardSum << endl;
                                }
                            }
                        }

                        cout << boards[j][k][l].first * (boardSum) << endl;
                        break;
                    }
                }
                if (a != 1) {
                    break;
                }
            }
            if (a != 1) {
                break;
            }
        }
        if (a != 1) {
            break;
        }
    }
}

void d4p2() {
    string input;
    vector<string> inputList;
    vector<vector<vector<pair<int, int> > > > boards;

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
            // boards.push_back(vector<vector<pair<int, int> >>());
            vector<vector<pair<int, int> > > board;

            for (int i = 0; i < 5; i++) {
                getline(file, input);
                // boards[boardNumber].push_back(vector<pair<int, int> >());
                
                // split the line into digits and add to values vector
                vector<pair<int, int> > values;
                num = "";
                for (int j = 0 ; j < input.size(); j++) {
                    if (input[j] == ' ') {
                        if (num == "" || num.empty()) {
                            continue;
                        }
                        values.push_back(make_pair(stoi(num), 0));
                        num = "";
                    } else {
                        num.push_back(input[j]);
                    }
                }
                values.push_back(make_pair(stoi(num), 0));
            
                board.push_back(values);
            }
            boards.push_back(board);

            boardNumber++;
        }
    }

    int a = 0;
    map<int, int> tracker;
    int solvedBoardCount;
    int lastBoard;
    int lastDigit;


    for (int i = 0; i < inputList.size(); i++) {
        for (int j = 0 ; j < boards.size(); j++) {
                // if board is solved, skip the board 
            if (tracker[j] == 1) {
                continue;
            }
            for (int k = 0; k < boards[j].size(); k++) {
                for (int l = 0; l < boards[j][k].size(); l++) {
                    // cout << boards[j][k][l].first << endl;
                        // if number called out, pair.second set to 1
                    if (boards[j][k][l].first == stoi(inputList[i])) {
                        boards[j][k][l].second = 1;
                    }

                        // bingo column!
                    if (boards[j][0][l].second == 1 && boards[j][1][l].second == 1 && boards[j][2][l].second == 1 && boards[j][3][l].second == 1 && boards[j][4][l].second == 1) {
                        if (tracker[j] != 1) {
                            cout << "lastDigit before: " << lastDigit << endl;
                            lastDigit = boards[j][k][l].first;
                            cout << "lastDigit after: " << lastDigit << endl;
                            solvedBoardCount++;
                            cout << j << " solved: " << solvedBoardCount << endl;
                            tracker[j]++;
                        }

                        // if (solvedBoardCount == boards.size() - 1) {
                        //     a = 1;
                        //     lastDigit = boards[j][k][l].first;
                        //     lastBoard = j;
                        //     cout << "j: " << j << endl;
                        //     break;
                        // }
                    }

                        // bingo row!
                    if (boards[j][k][0].second == 1 && boards[j][k][1].second == 1 && boards[j][k][2].second == 1 && boards[j][k][3].second == 1 && boards[j][k][4].second == 1) {
                        if (tracker[j] != 1) {
                            cout << "lastDigit before: " << lastDigit << endl;
                            lastDigit = boards[j][k][l].first;
                            cout << "lastDigit after: " << lastDigit << endl;
                            solvedBoardCount++;
                            cout << j << " solved: " << solvedBoardCount << endl;
                            tracker[j]++;
                        }

                        // if (solvedBoardCount == boards.size() - 1) {
                        //     a = 1;
                        //     lastDigit = boards[j][k][l].first;
                        //     lastBoard = j;
                        //     cout << "j: " << j << endl;
                        //     break;
                        // }
                    }
                }
            }
        }
    }

    int boardSum = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (boards[31][i][j].second != 1) {
                boardSum += boards[31][i][j].first;
            }
        }
    }
    cout << boardSum * lastDigit << endl;
}

// day 5
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

void d5p1() {
    ifstream file("dayFive.txt");
    vector<vector<int> > board (990, vector<int> (990));

    // vector<vector<int> > board (988, vector<int> (985));
    // vector<vector<int> > board (10, vector<int> (10));

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

void d5p2() {
    ifstream file("dayFive.txt");
    vector<vector<int> > board (990, vector<int> (990));
    // vector<vector<int> > board (10, vector<int> (10));

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
void d6p1() {
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

    for (int i = 0; i < 80; i++) {
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
void d6p2() {
    ifstream file("daySix.txt");
    uint64_t fish[9] = { 0, };

    string input;
    getline(file, input);

    for (int i = 0; i < input.size(); i++) {
        if (input[i] == ',') {
            continue;
        }
        ++fish[(int)input[i] - '0'];
    }

    for (int i = 0; i < 256; i++) {
        rotate(fish + 0, fish + 1, fish + 9);
        fish[6] += fish[8];
    }

    uint64_t sum = accumulate(fish + 0, fish + 9, uint64_t(0));
    cout << sum << endl;
    uint64_t divisor = uint64_t(1) * 1000 * 1000 * 1000;
    uint64_t high = sum / divisor, low = sum % divisor;
    cout << high << setfill('0') << setw(9) << low << endl;
}

// day 7 
    // geometric median, triangle numbers
void d7p1() {
    cout << "one" << endl;
    ifstream file("seven.txt");
    int positions[1000];
    for (int i = 0; i < 1000; i++) {
        file >> positions[i];
        file.ignore(1);
    }

    sort (positions, positions + 1000);

    int sum = 0; int median = positions[500];
    for (auto i : positions) {
        sum += abs(i - median);
    }
    cout << sum << endl;
}

void d7p2() {
    cout << "two" << endl;
    ifstream file("seven.txt");
    int positions[1000];
    int mean = 0;
    for (int i = 0; i < 1000; i++) {
        file >> positions[i];
        file.ignore(1);
        mean += positions[i];
    }
    mean /= 1000;
    int sum = 0;
    // int mean = accumulate(positions, positions + 1000, 0) / 1000;
    for (auto i : positions) {
        int n = abs(i - mean);
        sum += ((n * (n + 1)) / 2);
    }

    cout << mean << " " << sum << endl;
}

void d8p1() {
    ifstream file("input.in");
    
    int sum = 0;
    string str;
    while (getline(file, str)) {
        string output = str.substr(str.find('|'));
        istringstream ss(output);
        while (ss >> str) {
            if (str.size() == 2 || str.size() == 3 || str.size() == 4 || str.size() == 7) {
                cout << str << endl;
                sum++;
            }
        }
    }
    cout << sum << endl;
}

void d8p2() { // solve puzzle
// solved digits : 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
// solved chars : a, b, c, d, e, f

// char lengths : 
    // 2 char : 1
    // 3 char : 7
    // 4 char : 4
    // 5 char : 2, 3, 5
    // 6 char : 0, 6, 9
    // 7 char : 8

// 1 - 4 - 7 - 8 
    // we know: c, f
    // we know: b, d (1 - 4)
    // we know 'a' position 
        // compare 1 digit and 7 digit
        // difference is 'a'

// 5 - 6: 1 char difference 
// 1 - 7: 1 char dif
// 8 - 9 - 0: 1 char dif

// 3, size 6 strings (0, 6, 9)
    // we know 0 digit
    // we know d position 
        // compare 6 size char strings, 
        // check for b and d, if one is missing, it's 'd'
    // we know 6 and 9 digit
    // we know c , f, and e position
        // compare 1 digit and leftover 6 char strings
        // if 6 char string has both 'c' and 'f', it's 9 ('e')
        // the other string is 6 ('c')
    // we know 5 digit
    // we know e position
        // difference between 6 and 5 digits is e char

// 3, 5 char strings (2, 3, 5)
    // compare 1 digit and 5 char strings
            // we know 3 digit
        // if the 5 char string has 1 digit chars, it's 3
            // we know 5 digit
        // if it doesn't have c, it's 5
            // we know 2
        // other string is 2
    // compare 2 and 3
            // we know b position
        // the char they're both missing is b

// find g position
    // last char unknown is inherently g
    


// we know 7, 
    ifstream file("input.in");
    unordered_map<int, string> solved;
    int totalSum;
    string line;
    while (getline(file, line)) { // entire line
        int trueSum = 0;
        // 4 digit output
        string input = line.substr(0, line.find('|'));
        istringstream iss(input);

        vector<string> sixes;
        vector<string> fives;

        string digitStrings;
        while (iss >> digitStrings) {
            if (digitStrings.size() == 2) {
                sort(digitStrings.begin(), digitStrings.end());
                solved[1] = digitStrings;
            } else if (digitStrings.size() == 3) {
                sort(digitStrings.begin(), digitStrings.end());
                solved[7] = digitStrings;
            } else if (digitStrings.size() == 4) {
                sort(digitStrings.begin(), digitStrings.end());
                solved[4] = digitStrings;
            } else if (digitStrings.size() == 7) {
                sort(digitStrings.begin(), digitStrings.end());
                solved[8] = digitStrings;
            } else if (digitStrings.size() == 6) {
                sort(digitStrings.begin(), digitStrings.end());
                sixes.push_back(digitStrings);
            } else if (digitStrings.size() == 5) {
                sort(digitStrings.begin(), digitStrings.end());
                fives.push_back(digitStrings);
            }
        }

            // difference between 1 & 4
        for (auto i : sixes) {
            string one = solved[1];
            string four = solved[4];

                // remove 1 digit chars from 4 digit string
            four.erase(four.find(one[0]), 1);
            four.erase(four.find(one[1]), 1);

                // four = difference between 4 and 1 digit
                // 0 digit
            if (i.find(four[0]) == string::npos || i.find(four[1]) == string::npos) {
                sort(i.begin(), i.end());
                solved[0] = i;
            } else if (i.find(solved[1][1]) != string::npos && i.find(solved[1][0]) != string::npos) {
                    // if 6 char string has both 'c' and 'f', it's 9 ('e')
                sort(i.begin(), i.end());
                solved[9] = i;
            } else {
                sort(i.begin(), i.end());
                solved[6] = i;
            }
        }

        for (auto i : fives) {
            string sixDigit = solved[6];

                // find 5 digit from 6 digit
            int sum = 0;
            for (auto c : i) {
                if (sixDigit.find(c) != string::npos) {
                    sum++;
                }
            }
            if (sum == 5) {
                sort(i.begin(), i.end());
                solved[5] = i;
                continue;
            }
                // compare 1 digit and 5 char strings
            // we know 3 digit
        // if the 5 char string has 1 digit chars, it's 3
            // we know 5 digit
        // if it doesn't have c, it's 5
            // we know 2
        // other string is 2
    // compare 2 and 3
            // we know b position
        // the char they're both missing is b
            string oneDigit = solved[1];
            sum = 0;
            for (auto c : i) {
                if (oneDigit.find(c) != string::npos) {
                    sum++;
                }
            }
            if (sum == 2) {
                sort(i.begin(), i.end());
                solved[3] = i;
                continue;
            }

            // the last 5 char string is 2
            sort(i.begin(), i.end());
            solved[2] = i;
        }

        string output = line.substr(line.find('|') + 2);
        cout << "output: " << output << endl;
        istringstream oss(output);
        // parse through output string
        string outputString;
        int power = 3;
        while (oss >> outputString) {
            sort(outputString.begin(), outputString.end());
            for (int i = 0; i <= 9; i++) {
                if (solved[i] == outputString) {
                    cout << "check: " << pow(10, power) << endl;
                    trueSum += i * pow(10, power);
                    cout << "trueSum: " << trueSum << endl;
                    power--;
                    break;
                }
            }
        }
        totalSum += trueSum;
    }

    cout << "totalSum: " << totalSum << endl;
}

void d9p1() {
    cout << "Here" << endl;
    fstream file("input.in");
    vector<string> heightMap;
    vector<char> solCells;
    vector<int> dir = {0, 1, 0, -1, 0};

    string line;
    while(getline(file, line)) {
        cout << line << endl;
        heightMap.push_back(line);
    }

    for (int i = 0; i < heightMap.size(); i++) {
        for (int j = 0; j < heightMap[i].size(); j++) {
            if (heightMap[i][j] == '9') {
                continue;
            }

            int sum = 0;
            for (int k = 0; k < 4; k++) {
                int nx = j + dir[k], ny = i + dir[k + 1];
                if (nx < 0 || nx == heightMap[i].size() || ny < 0 || ny == heightMap.size()) {
                    continue;
                }

                if (heightMap[ny][nx] > heightMap[i][j]) {
                    sum++;
                }
            }
            
            if (sum == 4) {
                solCells.push_back(heightMap[i][j]);
            }
        }
    }

    int solution;
    for (char c : solCells) {
        solution += c - '0';
    }
    
    cout << solution << endl;
}

int main() {
    d9p1();
}