#include <iostream>

using namespace std;

string a, b;
int index;

void recurse(int l, int r) {
    if (l > r)
        return;
    int i;
    for (i = l; i <= r; i++) {
        if (b[i] == a[index])
            break;
    }

    if (i != r + 1) {
        index++;
        recurse(l, i - 1);
        recurse(i + 1, r);
        cout << b[i];
    }
}


int main() {
    int samples, n;
    cin >> samples;
    for (int i = 0; i < samples; ++i) {
        cin >> n >> a >> b;
        index = 0;
        recurse(0, n - 1);
        cout << endl;
    }
}
