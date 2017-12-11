#include <iostream>
#include <cmath>
#include <map>

using namespace std;

int main() {
    int tstCases;
	cin >> tstCases;
	cout.precision(0);
	for (int i = 0; i < tstCases; ++i) {
		int F, S;
		cin >> F;
		cin >> S;
		int l = S - 1;
		int r = F - 1;
		if (l > r - l) {
			l = r - l;
		}
		long long result = 1;
		for(int i = 0; i < l; ++i) {
		    result = result * (r - i)/(i+1);
		}
		cout << fixed << result << endl;
	}

    return 0;
}
