#include<iostream>
#include <vector>

using namespace std;
vector<int> table;

int f(int input);

int main() {
    table.push_back(1);
    table.push_back(1);

    int input;
    while(true) {
        cin >> input;
        if (input == 0) return 0;
        if (table.size() < input + 1) {
            table.resize((unsigned long) input + 1);
        }
        cout << f(input) << endl;
    }
}

int f(int input) {
    if (table[input] == 0) {
        table[input] = f(input - 1) + f(input - 2);
    }
    return table[input];
}