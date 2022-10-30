#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
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
