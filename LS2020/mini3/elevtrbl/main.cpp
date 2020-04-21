//
// Created by lactosis on 2.4.20.
//
#include <queue>
#include <iostream>
#include <map>

int write(int res) {
    if (res < 0)
        std::cout << "use the stairs" <<std::endl;
    else
        std::cout << res << std::endl;


    return 0;
}

int main() {
    int f,s,g,u,d;
    std::cin >> f >> s >> g>>u>>d;
    s -= 1;
    g -=1;

    if (s == g)
        return write(0);

    std::queue<int> queue;
    std::map<int , int> moves;
    moves[s] = 0;
    queue.push(s);


    while(!queue.empty()) {
        int curr = queue.front();
        queue.pop();

        int up = curr + u;
        if (up < f && moves.find(up) == moves.end()) {
            moves[up] = moves[curr] + 1;
            if (up == g) return write(moves[up]);
            queue.push(up);
        }
        int down = curr - d;
        if (down >= 0 && moves.find(down) == moves.end()) {
            moves[down] = moves[curr] + 1;
            if (down == g) return write(moves[down]);
            queue.push(down);
        }
    }

    return write(-1);
}