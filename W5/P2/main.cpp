#include<iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int n,k;
double * table;

double f(int i, int i1);

int main() {


    while(cin >> k) {

        cin >> n;


        table = (double *) calloc((size_t) (n * (k + 1)), sizeof(double));

        double sum = 0;
        for (int i = 0; i <= k; ++i) {
            sum += f(n - 1, i);
        }
        //cout << sum << endl;
        double result = sum / (double) pow(k + 1, n);
        result *= 100;
        result = (round(result * 100000) / 100000.0);
        cout << std::fixed;
        cout << std::setprecision(5);
        cout << result << endl;


        free(table);
    }
}

double f(int length, int lastCharacter) {
    if (length == 0) return 1;
    int currIndex = lastCharacter * n + length;
    if (table[currIndex] == 0) {
        double sum = f(length - 1, lastCharacter);
        if (lastCharacter > 0) sum += f(length - 1, lastCharacter - 1);
        if (lastCharacter < k) sum += f(length - 1, lastCharacter + 1);
        table[currIndex] = sum;
       // cout << "table[" << length << "][" << lastCharacter << "] = " << table[currIndex] << endl;
    }
    return table[currIndex];
}