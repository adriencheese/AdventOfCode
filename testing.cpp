#include <iostream>
#include <string>

using namespace std;

int main() {
    string a = "test";

    string *ptr = &a;

    cout << *ptr << endl << &a << endl;
}