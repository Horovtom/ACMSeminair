#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Fenwick {
private:
    vector<long long int> arr;

public:
    Fenwick(int size) {
        for (int i = 0; i < size; ++i) {
            arr.push_back(0);
        }
    }

    void update(int i, int v) {
        while (i > 0) {
            arr[i] += v;
            i -= i & (-i);
        }
    }

    long int get(int i) {
        long int sum = 0;
        while (i < arr.size()) {
            sum += arr[i];
            i += i & (-i);
        }
        return sum;
    }
};

int main() {

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        if (n % 2 == 1 || n < 4) {
            cout << "Impossible" << endl;
        } else {
            cout << n * 3 / 2 << endl;
            for (int i = 1; i < n; ++i) {
                cout << i << " " << i + 1 << endl;
            }
            cout << n << " 1" << endl;

            long long int half = n / 2 + 1;

            for (int j = 1; j <= n / 2; ++j) {
                cout << j << " " << half << endl;
                half += 1;
            }
        }

    }
}
