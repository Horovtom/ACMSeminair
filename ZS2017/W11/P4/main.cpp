#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    int number;
    while(scanf("%d", &number) == 1) {
        int numfactors;
        cin >> numfactors;
        vector<int> factors;

        for (int k = 0; k < numfactors; ++k) {
            int val;
            cin >>val;
            factors.emplace_back(val);
        }

        char ways[1000001];
        ways[0] = 0;
        for (int i = 1; i <= number; ++i) {
            ways[i] = 0;
            for (int j = 0; j < numfactors; ++j) {
                if (i-factors[j] >= 0) {
                    if (ways[i - factors[j]] == 0) {
                        ways[i] = 1;
                        break;
                    }
                }
            }
        }
        if (ways[number]){
            cout << "Stan wins" << endl;
        } else {
            cout << "Ollie wins" << endl;
        }

    }
    return 0;
}
