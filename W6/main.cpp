#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<limits>
#include<cmath>

using namespace std;

vector<long double> racks;
map<int, map<long double, long double>> saved;
int size;

long double solve(int i, long double left);

int main() {
    int t;
    long double nRacks, sizeLeft;
    cin >> t;

    while(t--) {
        racks.clear();
        saved.clear();

        cin >> nRacks;
        cin >>size;

        sizeLeft = size;

        while(nRacks--) {
            int dishes;
            cin >> dishes;
            int sum = 0;
            int number;
            for (int i = 0; i < dishes; ++i) {
                cin >> number;
                sum += number;
            }
            racks.push_back(sum);
        }
        cout << solve(0,0) << endl;
    }

}

long double solve(int i, long double mySize) {
    if (mySize > size) return -INTMAX_MAX;
    if (i >= racks.size()) return mySize;
    if (saved[i][mySize] == 0) {
        saved[i][mySize] = max(solve(i + 1, mySize + racks[i]), solve(i+ 1, mySize));
    }

    return saved[i][mySize];
}
