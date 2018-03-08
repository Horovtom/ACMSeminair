#include<iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>


using namespace std;

std::map<int, vector<int>> saved;
vector<int> primes;


vector<int> getPrimes(int n) {
    if (n <= 1) return {0};
    if (saved.find(n) != saved.end()) {
        return saved[n];
    }

    vector<int> res(primes.size());

    for (int i = 0; i < primes.size(); ++i) {
        while(n % primes[i] == 0) {
            n /= primes[i];
            res[i]++;
        }
    }

    saved[n] = res;
    return res;
}

void generateStartPrimes() {
    for (int i = 2; i < 100; ++i) {
        bool b = false;
        for (int j = i/2; j > 1; --j) {
            if (i % j == 0) {
                b = true;
                break;
            }
        }
        if (!b) primes.emplace_back(i);
    }
}

int main() {
    generateStartPrimes();
    int num;
    while(true) {
        cin >> num;
        if(num == 0) break;

        vector<int> result(primes.size());
        for (int i = num; i > 1; --i) {
            vector<int> getted = getPrimes(i);
            for (int j = 0; j < getted.size(); ++j) {
                result[j] += getted[j];
            }
        }

        int max;
        for (int k = result.size() - 1; k >= 0; --k) {
            if (result[k] != 0) {
                max = k;
                break;
            }
        }
        cout << right << setw(3) << num << "! =";
        for (int l = 0; l <= max; ++l) {
            if (l % 15 == 0 && l != 0) cout << endl << "      ";
            cout << right << setw(3) << result[l];
        }
        cout << endl;
    }

}

