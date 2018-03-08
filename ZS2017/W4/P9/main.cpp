#include <iostream>
#include <list>
#include <set>
#include <vector>

using namespace std;
std::vector< std::vector< int > > nodes;
std::vector< int > incomingConnections;

std::vector< int > results;
int sticks;


void findResultNew() ;

int main() {
    while(true){
        nodes.clear();
        incomingConnections.clear();
        results.clear();
        cin >> sticks;
        int rows;
        cin >> rows;

        if (sticks == 0 && rows == 0) return 0;
        int a, b;
        nodes.resize((unsigned long) sticks + 1);
        incomingConnections.resize((unsigned long) (sticks + 1));
        while(rows > 0) {
            cin >> a;
            cin >> b;

            nodes[a].push_back(b);
            incomingConnections[b]++;
            rows--;
        }
        findResultNew();
    }
}

void findResultNew() {
    int opened = sticks;
    int lastOpened = -1;
    while(opened > 0) {
        if (lastOpened == opened) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        lastOpened = opened;

        for (int i = 1; i < sticks + 1; ++i) {
            if (incomingConnections[i] == 0) {
                results.push_back(i);
                incomingConnections[i] = -1;

                for (int j = 0; j < nodes[i].size(); ++j) {
                    incomingConnections[nodes[i][j]]--;
                }
                opened--;
            }
        }
    }
    for (int i = 0; i < sticks; ++i) {
        cout << results[i] << endl;
    }

}
