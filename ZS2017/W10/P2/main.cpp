#include <iostream>
#include <algorithm>

using namespace std;



int main() {
    int casenum = 1;
    bool doneSmth = false;
    while(true) {

        //C crossings, S streets, Q queries
        int C, S, Q;
        cin >> C >> S >> Q;
        if (C == 0 && S == 0 & Q == 0) break;
        C += 1;
        int table[101][101];


        for (int j = 0; j < C; ++j) {
            for (int i = 0; i < C; ++i) {
                table[j][i] = 10000 + 1;
            }
        }

        int c1, c2, d;
        for (int i = 0; i < S; ++i) {
            cin >> c1 >> c2 >> d;
            table[c1][c2] = d;
            table[c2][c1] = d;
        }

        for (int k = 0; k < C; ++k) {
            for (int i = 0; i < C; ++i) {
                for (int j = 0; j < C; ++j) {
                    if (k == i || j == i || j == k) continue;
                    int maximum = max(table[i][k], table[k][j]);
                    if (table[i][j] > maximum) {
                        table[i][j] = maximum;
                        table[j][i] = maximum;
                    }
                }
            }
        }
        if (doneSmth) cout << endl;
        cout << "Case #" << casenum++ << endl;
        for (int l = 0; l < Q; ++l) {
            cin >> c1 >> c2;
            if (table[c1][c2] <= 10000) {
                cout << table[c1][c2] << endl;
            } else {
                cout << "no path" << endl;
            }
        }
        doneSmth = true;
    }
}
