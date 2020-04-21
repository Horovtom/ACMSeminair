//
// Created by lactosis on 2.4.20.
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>

int main () {
    int N = 0;
    std::cin >> N;
    std::vector<std::vector<int>> adj;
    adj.resize(N);
    int frm = 0, to = 0;
   for (int i = 0; i < N - 1; ++i) {
        std::cin >> frm >> to;

        adj[frm - 1].push_back(to-1);
        adj[to  -1].push_back(frm-1);
    }

    std::queue<int> queue;
    std::vector<int> depths;
    depths.resize(N);
    std::fill(depths.begin(), depths.end(), -1);
    depths[0] = 0;
    queue.push(0);
    int maxDepth = 0;
    int maxNode = 0;
    while(!queue.empty()) {
        int curr = queue.front();
        queue.pop();

        for (int a: adj[curr]) {
            if (depths[a] !=  -1) continue;
            depths[a] = depths[curr] + 1;
            if (depths[a] > maxDepth) {
                maxDepth = depths[a];
                maxNode = a;
            }
            queue.push(a);
        }
    }

    std::fill(depths.begin(), depths.end(), -1);
    queue.push(maxNode);
    depths[maxNode] = 0;
    maxDepth = 0;
    while(!queue.empty()) {
        int curr = queue.front();
        queue.pop();
        for (int a: adj[curr]) {
            if (depths[a] != -1) continue;
            depths[a] = depths[curr] + 1;
            if (depths[a] > maxDepth) {
                maxDepth = depths[a];
            }
            queue.push(a);
        }
    }

    std::cout << maxDepth << std::endl;
}