#include <iostream>
#include <fstream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

int main() {
    ifstream file("daySeven/seven.txt");
    int positions[10];
    for (int i = 0; i < 10; i++) {
        file >> positions[i];
        file.ignore(1);
    }

    for (int i = 0 ; i < 10; i++) {
        cout << positions[i] << endl;
    }

}
