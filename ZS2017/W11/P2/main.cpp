#include <iostream>
#include <algorithm>

using namespace std;

int64_t get_it(int64_t val){
    while(val % 2) {
        val = val >> 1;
    }
    return static_cast<int64_t>(val >> 1);
}

int main(){
    int64_t samples;
    cin >> samples;

    for (int64_t i = 0; i < samples; ++i) {
        int64_t value = 0;
        int64_t columns;
        cin >> columns;
        for (int64_t j = 0; j < columns; ++j) {
            int64_t curr;
            cin >> curr;
            curr = get_it(curr);
            value = value ^ curr;
        }
        if (value) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
