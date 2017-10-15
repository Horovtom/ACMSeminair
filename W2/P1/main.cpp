#include <iostream>
#include <queue>
#include <set>
#include <limits.h>
#include <cassert>

#define CAR 1
#define FREE 0

using namespace std;

struct node {
    unsigned type: 1;
};

struct position {
    int x, y;
};

struct positionInTime {
    int x, y, time;

    bool operator==(const positionInTime &rhs) const {
        return (x == rhs.x && y == rhs.y && time == rhs.time);
    }

    bool operator<(const positionInTime &rhs) const {
        return time == rhs.time ? x == rhs.x ? y < rhs.y : x < rhs.x : time < rhs.time;
    }
};


class unique_queue {
private:
    queue<positionInTime> m_queue;
    set<positionInTime> m_set;
public:
    bool push(positionInTime p) {
        m_set.find(p);

        if (m_set.insert(p).second) {
            m_queue.push(p);
            return true;
        }
        return false;
    }

    void pop() {
        assert(!m_queue.empty());
        positionInTime val = m_queue.front();
        m_set.erase(val);

        m_queue.pop();
    }

    positionInTime front() {
        return m_queue.front();
    }

    int size() {
        return (int) m_queue.size();
    }
};

long mod(long a, long b) {
    return (a % b + b) % b;
}

int maxIterations, numLanes, laneLength;
position target, initial;
int best = INT_MAX;
unique_queue bfsQueue;

bool isSolvable(node *map) {
    //Check whether any lane is composed of only X
    for (int i = 0; i < numLanes + 2; ++i) {
        bool full = true;
        for (int j = 0; j < laneLength; ++j) {
            if ((*(map + i * laneLength + j)).type == FREE) {
                full = false;
                break;
            }
        }
        if (full) return false;
    }
    return true;
}

bool isValidToBeOn(int time, position pos, node *map) {
    if (pos.x >= laneLength || pos.x < 0 || pos.y >= numLanes + 2 || pos.y < 0) return false;
    if (pos.y % 2 == 1) {
        //Moving right
        return (*(map + (pos.y * laneLength) + (mod(pos.x - time, laneLength)))).type != CAR;
    } else {
        //Moving left
        return (*(map + (pos.y * laneLength) + (mod(pos.x + time, laneLength)))).type != CAR;
    }
}

bool bfs(node *map) {
    positionInTime pos = bfsQueue.front();
    bfsQueue.pop();
    if (pos.x == target.x && pos.y == target.y) {
        best = min(pos.time, best);
        return true;
    }
    if (pos.time >= maxIterations || pos.time >= best) return false;
    //4 directions:
    position nextPos;
    //N
    nextPos = {pos.x, pos.y + 1};
    if (isValidToBeOn(pos.time + 1, nextPos, map)) {
        bfsQueue.push({nextPos.x, nextPos.y, pos.time + 1});
    }

    //E
    nextPos = {pos.x + 1, pos.y};
    if (isValidToBeOn(pos.time + 1, nextPos, map)) {
        bfsQueue.push({nextPos.x, nextPos.y, pos.time + 1});
    }

    //S
    nextPos = {pos.x, pos.y - 1};
    if (isValidToBeOn(pos.time + 1, nextPos, map)) {
        bfsQueue.push({nextPos.x, nextPos.y, pos.time + 1});
    }

    //W
    nextPos = {pos.x - 1, pos.y};
    if (isValidToBeOn(pos.time + 1, nextPos, map)) {
        bfsQueue.push({nextPos.x, nextPos.y, pos.time + 1});
    }

    //Stand
    if (isValidToBeOn(pos.time + 1, {pos.x, pos.y}, map)) {
        bfsQueue.push({pos.x, pos.y, pos.time + 1});
    }
    return false;
}

int getPath(node *map, position startingPos) {
    if (!isSolvable(map)) return INT_MAX;
    bfsQueue.push({startingPos.x, startingPos.y, 0});
    do {
        if (bfs(map)) {
            return best;
        }
    } while (!bfsQueue.size() == 0);
    return INT_MAX;
}

void loadChar(node *map, int j, int k) {
    char ch;
    cin >> ch;
    switch (ch) {
        case 'O':
        (*(map)).type = FREE;
            break;
        case 'X':
            (*(map)).type = CAR;
            break;
        case 'F':
            (*(map)).type = FREE;
            initial = {k, j};
            break;
        case 'G':
            (*(map)).type = FREE;
            target = {k, j};
            break;
        default:
            loadChar(map, j, k);
            //cerr << "Unknown identifier!, skipping..." << endl;
    }
}

int main() {
    int numCases;
    //Load input
    cin >> numCases;
    while (numCases--) {
        bfsQueue = unique_queue();
        maxIterations = 0;
        numLanes = 0;
        laneLength = 0;
        initial = {-1, -1};
        target = {-1, -1};
        best = INT_MAX;
        cin >> maxIterations;
        cin >> numLanes;
        cin >> laneLength;
        node map[numLanes + 2][laneLength];
        for (int j = numLanes + 1; j >= 0; --j) {
            char ch;
            for (int k = 0; k < laneLength; ++k) {
                loadChar(&map[j][k], j, k);
            }
        }

        if (target.x == -1 || target.y == -1 || initial.x == -1 || initial.y == -1) {
            cout << "The problem has no solution." << endl;
        }

        int result = getPath((node *) map, initial);
        if (result == INT_MAX) {
            cout << "The problem has no solution." << endl;
        } else {
            cout << "The minimum number of turns is " << result << "." << endl;
        }
    }
}