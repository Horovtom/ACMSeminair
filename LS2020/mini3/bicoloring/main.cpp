//
// Created by lactosis on 2.4.20.
//
#include <iostream>
#include <vector>
#include <queue>

static const int C1 = 0;
static const int UNKNOWN = 2;

int main() {
    int n;
    while (std::cin >> n, n != 0) {
        std::vector<std::vector<int>> G(n);
        std::vector<int> color(n, UNKNOWN);
        int l, u, v;
        std::cin >> l;
        while (l--) {
            std::cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        bool isBipartite = true;

        std::queue<int> q;
        color[0] = C1;
        q.push(0);
        while (!q.empty() && isBipartite) {
            int curr = q.front();
            q.pop();
            for (int i = 0; i < G[curr].size(); ++i) {
                int to = G[curr][i];
                if (color[to] == color[curr]) {
                    isBipartite = false;
                    break;
                } else if (color[to] == UNKNOWN) {
                    color[to] = 1 - color[curr];
                    q.push(to);
                }
            }
        }
        if (isBipartite)
            std::cout << "BICOLORABLE." << std::endl;
        else
            std::cout << "NOT BICOLORABLE." << std::endl;
    }
    return 0;
}