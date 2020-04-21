//
// Created by lactosis on 2.4.20.
//

#include <iostream>
#include <cstring>
#include <stack>
#include <climits>
#include <cmath>

# define MAXSIZE 101
int adjmat[MAXSIZE][MAXSIZE];

int main() {
    int scNum = 1;
    while (true) {

        int N, E;
        std::cin >> N >> E;
        if (N == E && E == 0) break;
        int C1, C2, P;

        memset(adjmat, 0, sizeof(adjmat[0][0]) * MAXSIZE * MAXSIZE);

        while (E--) {
            std::cin >> C1 >> C2 >> P;
            adjmat[C1][C2] = P;
            adjmat[C2][C1] = P;
        }

        int S, D, T;
        std::cin >> S >> D >> T;


        for (int k = 1; k <= N; ++k) {
            for (int i = 1; i <= N; ++i) {
                for (int j = 1; j <= N; ++j) {
                    adjmat[i][j] = std::max(adjmat[i][j], std::min(adjmat[i][k], adjmat[k][j]));
                }
            }
        }
        int largest = adjmat[S][D] - 1;
        int res  = std::ceil(T / static_cast<double>(largest));
        std::cout << "Scenario #" << scNum++ << std::endl;
        std::cout << "Minimum Number of Trips = " << res << std::endl << std::endl;

    }
}