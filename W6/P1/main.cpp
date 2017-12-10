#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>

using namespace std;

map<long double, long double> saved;

long double solve(long double n);

int main() {

    long double n;
    cout.precision(0);
    while(cin>>n) cout << fixed << solve(n) << endl;
}

long double solve(long double n) {
    if (n == 1) return 1;
    if (n <= 0) return 0;
    if (saved[n] != 0) return saved[n];
    long double res = max(n, (solve(floor(n/2))+ solve(floor(n/3)) + solve(floor(n/4))));
    saved[n] = res;
    return res;
}
