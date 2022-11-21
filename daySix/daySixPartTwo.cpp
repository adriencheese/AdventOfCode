#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> // rotate, param (itr of first, itr of index to go to first index, last itr)
#include <numeric> // accumulate, sum of array using iterators
#include <iomanip> // setfill, setw 



using namespace std;

int main() {
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