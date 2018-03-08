#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<limits>
#include<cmath>

using namespace std;

int lcs(string x, string y, int m, int n) {

    __int16_t L[6101][6101];
    int i, j;

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            } else if (x[i - 1] == y[j - 1]) {
                L[i][j] = (__int16_t) (L[i - 1][j - 1] + 1);

            } else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

    return L[m][n];
}


int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        string str1;
        cin >> str1;
        string copy(str1);
        std::reverse(copy.begin(), copy.end());

        cout << str1.length() - lcs(str1, copy, (int) str1.length(), (int) copy.length()) << endl;
    }
}