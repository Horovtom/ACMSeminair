#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

long double sum = 0;

long double calculateSum(long long int n) {
    sum = 0;
    long long int square_root = (long long int) (sqrt(n) + 1);
    for (long long int i = 1; i < square_root; i++) {
        if (n % i == 0) {
            //cout << "DIvisors: " << i << " " <<  n / i << endl;
            if (i < n && i != n/i) sum += i;
            if (n/i < n) sum += n/i;
        }
    }
    return sum;
}

int main() {
    long long int n;
    cout.precision(0);
    long long int lines;
    cin >> lines;
    if (n<0) n=-n;
    for (long long int i = 0; i < lines; ++i) {
        cin >> n;
        cout << fixed << calculateSum(n) << endl;
    }

//    for (int j = 0; j < 100000; ++j) {
//        cout<<fixed<<calculateSum(500000) << endl;
//    }
}