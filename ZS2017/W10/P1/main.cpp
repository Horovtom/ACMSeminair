#include <iostream>

using namespace std;

int doIt(int D, int I);

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; ++i) {
        int D, I;
        cin >> D;
        cin >> I;
        cout << doIt(D,I) << endl;
    }
    cin >> cases;
    if (cases != -1) cerr << "ERROR!" << endl;
    return 0;
}

int doIt(int D, int I) {
    int maxNode = (1<<D) - 1;
    int curr = 1;
    while(true) {
        if (2*curr > maxNode) break;
        if (I % 2 == 1) curr = 2 * curr;
        else curr = 2 * curr + 1;
        I = (I+1) / 2;
        //How many balls went through this
    }
    return curr;
}
