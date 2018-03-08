#include <iostream>
#include <cmath>

using namespace std;

int myMod(double A, double B) {
    return ((int) A) % ((int) B);
}

bool isFeasible(double N, double K) {
    if (N<K) return false;
    int current = N;
    double mult = (K-1) /K;
    int counter = K;
    while(counter-- > 0) {
        if (myMod(current, K) != 1) return false;
        current = ((current-1)*mult);
    }
    if (myMod(current, K) != 0) return false;
    return true;
}

int main() {
    while(1) {
        int n;
        cin >> n;
        if (n < 0) return 0;
        bool found = false;
        for (int i = sqrt(n) + 1; i >= 2; --i) {
            if (isFeasible(n, i)) {
                cout << n << " coconuts, " << i << " people and 1 monkey" << endl;
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << n << " coconuts, no solution" << endl;
        }
    }

    return 0;
}

