#include<iostream>

using namespace std;

int main() {
    int testCases, monsters;

    cin >> testCases;
    for (int i = 1; i <= testCases; ++i) {
        cin >> monsters;
        long long int coinCounts[monsters] = {};
        long long int best[monsters] = {};
        for (int j = 0; j < monsters; ++j) {
            cin >> coinCounts[j];
        }

        if(monsters == 1) {
            cout << "Case " << i << ": " << coinCounts[0] << endl;
            continue;
        }

        best[monsters - 1] = coinCounts[monsters - 1];
        best[monsters - 2] = max(coinCounts[monsters - 2], coinCounts[monsters - 1]);

        //Do it without recursion!
        for (int k = monsters - 3; k >= 0; --k) {
            long long int maximum = best[k + 1];
            maximum = max(maximum, coinCounts[k] + best[k + 2]);
            best[k] = maximum;
        }

        cout << "Case " << i << ": " << best[0] << endl;
    }
}