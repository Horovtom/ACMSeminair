//
// Created by lactosis on 5.3.20.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <climits>

int n;
long long dp[100001];
int ar[100001];

long long solve(int i) {
    if (i >= n) {
        return 0;
    }
    if (dp[i] != -1) {
        return dp[i];
    }
    dp[i] = std::max(ar[i] + solve(i + 2),
                     std::max(ar[i] + ar[i + 1] + solve(i + 4), ar[i] + ar[i + 1] + ar[i + 2] + solve(i + 6)));
    return dp[i];
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::cin >> n;
        std::memset(ar, 0, sizeof(ar));
        for (int i = 0; i < n; i++) {
            std::cin >> ar[i];
        }
        std::memset(dp, -1, sizeof(dp));
        solve(0);
        std::cout << dp[0] << "\n";

    }
    return 0;
}