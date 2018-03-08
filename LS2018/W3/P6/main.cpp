#include <iostream>
#include <queue>

using namespace std;

int grid[185][185];
int numRows, numCols;

void bfs(pair<int, int> s) {
    pair<int, int> u;
    int distance;
    queue<pair<int, int>> Q;
    Q.push(s);
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        for (int i = u.first - 1; i <= u.first + 1; ++i) {
            for (int j = u.second - 1; j <= u.second + 1; ++j) {
                if (i >= 0 && i < numRows && j >= 0 && j < numCols) {
                    distance = abs(i - s.first) + abs(j - s.second);
                    if (grid[i][j] > distance) {
                        grid[i][j] = distance;
                        Q.push(pair<int, int>(i, j));
                    }
                }
            }
        }

    }
}

/*
 * 0001
 * 0011
 * 0110
 */

int main() {
    int MAX = 1<<30;
    int t;
    cin >> t;

    vector<pair<int, int>> ones;
    for (int current = 0; current < t; ++current) {
        ones.clear();
        cin >> numRows >> numCols;

        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                char c;
                cin >> c;
                if (c == '0') {
                    grid[i][j] = MAX;
                } else {
                    grid[i][j] = 0;
                    ones.emplace_back(pair<int, int>(i, j));
                }
            }
        }

        for (const auto &one : ones) {
            bfs(one);
        }

        for (int i = 0; i < numRows; ++i) {
            cout << grid[i][0];
            for (int j = 1; j < numCols; ++j) {
                cout << " " <<grid[i][j];
            }
            cout << endl;
        }
    }
}
