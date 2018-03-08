#include <iostream>

using namespace std;

int main() {
    long long int n, m;
    while (cin >> n >> m) {
        if (m == 0) cout << 1 << endl;
        else {
            long long int returning = 1;
            for (long long int i = n; i >= n - m + 1; --i) {
                returning *= i;
                while (returning % 10 == 0) {
                    returning /= 10;
                }

                returning = returning % 1000000000;
            }
            cout << returning % 10 << endl;
        }
    }
}
