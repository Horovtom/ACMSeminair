//
// Created by lactosis on 2.4.20.
//


#include <iostream>
#include <vector>
#include <map>
#include <queue>

void dfs(long long int a, const std::vector<std::vector<long long int>> &friends, std::vector<bool> &visited) {
    visited[a] = true;
    for (long long int i = 0; i < friends[a].size(); i++) {
        if (!visited[friends[a][i]]) {
            dfs(friends[a][i], friends, visited);
        }
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        long long int n, res = 0;
        long long int e;
        std::cin >> n >> e;

        std::vector<std::vector<long long int >> friends(n, std:: vector<long long int>());
        std::vector<bool> visited(n, false);
        for (long long int i = 0; i < e; i++) {
            long long int  a, b;
            std::cin >> a >> b;
            friends[a].push_back(b);
            friends[b].push_back(a);
        }
        for (long long int  i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, friends, visited);
                res++;
            }
        }
        std::cout << res << std::endl;
    }
    return 0;
}