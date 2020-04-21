//
// Created by lactosis on 2.4.20.
//

#include <iostream>
#include <queue>
#include <map>
#include <cstring>
#include <set>

int tar1, tar2, tar3, tar4;


std::map<int, std::vector<int>> neighbors;

int getNumber(int p1, int p2, int p3, int p4) {
    p1 = (p1 + 10) % 10;
    p2 = (p2 + 10) % 10;
    p3 = (p3 + 10) % 10;
    p4 = (p4 + 10) % 10;

    return p1 * 1000 + p2 * 100 + p3 * 10 + p4;
}

void preFill() {
    for (int i = 0; i <= 9999; ++i) {
        int num = i;
        int p4 = num % 10;
        num = (num - p4) / 10;
        int p3 = num % 10;
        num = (num - p3) / 10;
        int p2 = num % 10;
        num = (num - p2) / 10;
        int p1 = num % 10;
        std::vector<int> neighs;
        neighs.reserve(8);
        for (int j = -1; j < 2; j += 2) {
            neighs.push_back(getNumber(p1 + j, p2, p3, p4));
            neighs.push_back(getNumber(p1, p2 + j, p3, p4));
            neighs.push_back(getNumber(p1, p2, p3 + j, p4));
            neighs.push_back(getNumber(p1, p2, p3, p4 + j));
        }
        neighbors[i] = neighs;
    }
}

int main() {

    preFill();

    int N;
    std::cin >> N;
    while (N--) {
        int in1, in2, in3, in4;
        std::cin >> in1 >> in2 >> in3 >> in4;
        std::cin >> tar1 >> tar2 >> tar3 >> tar4;
        int target = getNumber(tar1, tar2, tar3, tar4);

        int n;
        std::cin >> n;
        std::set<int> forbidden;
        int a, b, c, d;
        while (n--) {
            std::cin >> a >> b >> c >> d;
            int num = getNumber(a, b, c, d);
            forbidden.insert(num);
        }

        std::map<int, int> visited;
        std::queue<int> queue;
        int inNumber = getNumber(in1, in2, in3, in4);
        queue.push(inNumber);
        visited[inNumber] = 0;
        int found = -1;

        if (inNumber == target) {
            found = 0;
            goto outer;
        }

        while (!queue.empty()) {
            int top = queue.front();
            queue.pop();
            for (int neigh : neighbors[top]) {
                if (visited.find(neigh) != visited.end())
                    continue;
                if (forbidden.find(neigh) != forbidden.end())
                    continue;
                visited[neigh] = visited[top] + 1;
                if (neigh == target) {
                    found = visited[neigh];
                    goto outer;
                }

                queue.push(neigh);
            }
        }
        outer:

        std::cout << found << std::endl;
    }


}