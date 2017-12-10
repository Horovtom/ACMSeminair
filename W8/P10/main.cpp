#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

long double multiple = 0;

long double calculateTotient(long long int n) {
    if (n == 0) return 0;
    bool didIt = false;
    multiple = n;
    while (n % 2 == 0) {
        if (!didIt) {
            didIt = true;
            multiple *= (0.5);
        }
        n = n / 2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2) {
        didIt = false;
        while (n % i == 0) {
            if (!didIt) {
                didIt = true;
                multiple *= (1 - 1.0 / i);
            }
            n = n / i;
        }
    }

    if (n > 2) {
        multiple *= (1 - 1.0 / n);
    }
    return multiple;
}

int main() {
    long long int n;
    cout.precision(0);
    long long int lines;
    cin >> lines;
    if (n < 0) n = -n;
    for (long long int i = 0; i < lines; ++i) {
        cin >> n;
        cout << fixed << calculateTotient(n) << endl;
    }

}