#include <cstdio>
#include <iostream>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <vector>

using namespace std;


long double calculateMod(long long int B, long long int P, int M) {
    //COnvert P to binary:

    string bin = std::bitset<32>((unsigned long long int) P).to_string();
    reverse(bin.begin(), bin.end());
    vector<int> values;
    values.push_back((int &&) (B % M));
    for (int i = 2; i < bin.length() + 1; ++i) {
        values.push_back(values[i-2]*values[i-2] % M);
    }
    long long int sum = 1;
    for (int j = 0; j < bin.length(); ++j) {
        if (bin[j] == '1') {
            sum *= values[j];
            sum = sum % M;
        }
    }

    return sum;
}

int main() {
    //439^233 mod 713 ...
    //COnvert 233 to binary
    //Get coefficients iteratively: 439^4 mod 713 = ((439^2 mod 713)^2 mod 713)

    while(true) {
        long long int B, P, M;
        if (scanf("%lli", &B) == EOF) {
            return 0;
        }
        cin >> P;
        cin >> M;
        cout << calculateMod(B, P, M) << endl;
        if(cin.peek()=='\n')
            cin.get();
            cin.get();
            if (cin.peek() == '\n') return 0;
    }
}