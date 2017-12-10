#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long double n;
    cout.precision(0);
    while(scanf("%Lf", &n) != EOF) {
        cout << fixed << 6*(pow((n+1)/2, 2)) - 9 << endl;
    }
}