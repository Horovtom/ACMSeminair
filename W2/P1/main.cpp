#include <iostream>
#include <limits.h>
#include <queue>
#include <set>
#include <functional>
#include <assert.h>
#include <algorithm>

#define CAR 1
#define FREE 0

using namespace std;

struct node {
    unsigned type: 2;
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
        return time==rhs.time? x == rhs.x ? y < rhs.y : x < rhs.x : time < rhs.time;
    }
};



class unique_queue {
private:
    queue<positionInTime> m_queue;
    set<positionInTime> m_set;
    //vector<positionInTime> m_set;
public:
    bool push(positionInTime p) {
        m_set.find(p);

        if (m_set.insert(p).second) {
            m_queue.push(p);
            return true;
        }
        return false;

//        if (m_set.insert(p).second) {
//            m_queue.push(p);
//            return true;
//        }
//        return false;

//        for (auto pos : m_set) {
//            if (pos == p) return false;
//        }
//
//
//
//        m_set.push_back(p);
//        m_queue.push(p);
    }

    void pop() {
        assert(!m_queue.empty());
        positionInTime val = m_queue.front();
        m_set.erase(val);

        m_queue.pop();
//        assert(!m_queue.empty());
//        positionInTime val = m_queue.front();
//
//
//        assert(it != m_set.end());
//
//
//
//        m_set.erase(it);
//        m_queue.pop();

//        positionInTime pos = m_queue.front();
//        m_set.erase(remove(m_set.begin(), m_set.end(), pos), m_set.end());
//        m_queue.pop();
    }

    positionInTime front() {
        return m_queue.front();
    }

    int size() {
        return m_queue.size();
    }
};

long mod(long a, long b) {
    return (a%b + b) % b;
}

int maxIterations, numLanes, laneLength;
position target;
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
    if (pos.time > maxIterations || pos.time >= best) return false;
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


int main() {





    int numCases;
    //Load input
    cin >> numCases;
    for (int i = 0; i < numCases; ++i) {
        cin >> maxIterations;
        cin >> numLanes;
        cin >> laneLength;
        node map[numLanes + 2][laneLength];
        position initial;
        for (int j = numLanes + 1; j >= 0; --j) {
            char ch;
            for (int k = 0; k < laneLength; ++k) {
                cin >> ch;
                switch (ch) {
                    case 'O':
                        map[j][k].type = FREE;
                        break;
                    case 'X':
                        map[j][k].type = CAR;
                        break;
                    case 'F':
                        map[j][k].type = FREE;
                        initial = {k, j};
                        break;
                    case 'G':
                        map[j][k].type = FREE;
                        target = {k, j};
                        break;
                    default:
                        cerr << "Unknown identifier!, skipping..." << endl;
                }
            }
        }
//
//
//        node * map1 = (node *) map;
//        for (int time = 0; time < 10; ++time) {
//            cout << (*(map1 + (1 * laneLength) + (mod(0 - time, laneLength)))).type;
//            cout << (*(map1 + (1 * laneLength) + (mod(1 - time, laneLength)))).type;
//            cout << (*(map1 + (1 * laneLength) + (mod(2 - time, laneLength)))).type;
//            cout << (*(map1 + (1 * laneLength) + (mod(3 - time, laneLength)))).type;
//            cout << endl;
//
//        }
//        return 0;


        int result = getPath((node *) map, initial);
        if (result == INT_MAX) {
            cout << "The problem has no solution." << endl;
        } else {
            cout << "The minimum number of turns is " << result << endl;
        }
    }

}