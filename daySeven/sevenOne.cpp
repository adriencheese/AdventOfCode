#include <iostream> 
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

int d7p2() {
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

int d7p1() {
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

int main() {
    d7p2();
}

