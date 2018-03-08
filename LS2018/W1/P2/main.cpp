
#include <iostream>

using namespace std;

int getFives(double n) {
    int r = 0;
    while(true) {
        if (n >0) {
            n /= 5;
            r += n;
        } else return r;
    }

}

int main() {
    int count;
    cin >> count;
    int num;
    for (int i = 0; i < count; ++i) {
        cin >> num;
        cout << getFives(num) << endl;
    }

}
