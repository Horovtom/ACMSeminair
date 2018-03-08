#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;
std::map<int, std::vector<int>> adjacency;

int maxDepthNode = 0;
int maxDepth = 0;

void getMaxDepthNode(int cameFrom, int current, int depth) {
    vector<int> currentChildren = adjacency[current];
    if (currentChildren.size() == 1 && currentChildren[0] == cameFrom) {
        if (maxDepth < depth) {
            maxDepth = depth;
            maxDepthNode = current;
        }
        return;
    }
    for (int i : currentChildren) {
        if (i != cameFrom)
            getMaxDepthNode(current,i, depth + 1);
    }
}

int main() {
    int nodes;

    cin >> nodes;
    int a, b;
    int current = 0;
    for (int i = 0; i < nodes - 1; ++i) {
        cin >> a >> b;
        if (i == 0) {
            current = a;
        }
        adjacency[a].emplace_back(b);
        adjacency[b].emplace_back(a);
    }

    getMaxDepthNode(-1, current, 0);

    current = maxDepthNode;
    getMaxDepthNode(-1, current, 0);
    cout << maxDepth;

}
