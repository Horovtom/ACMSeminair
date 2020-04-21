//
// Created by lactosis on 2.4.20.
//

#include <cstdio>
#include <cstring>
#include <iostream>

const int MAX = 50 + 1;
int con[MAX][MAX];
bool vis[MAX];

void check(int now) {
    vis[now] = true;
    for (int i = 0; i < MAX; i++) {
        if (con[now][i] && !vis[i]) {
            check(i);
        }
    }
}

void print(int now) {
    for (int i = 0; i < MAX; i++) {
        if (con[now][i]) {
            con[now][i]--;
            con[i][now]--;
            print(i);
            std::cout << i << " " << now << std::endl;
        }
    }
}

int main() {
    int T;
    std::cin >> T;
    for (int C = 1; C <= T; ++C) {
        int N;
        std::cin >> N;
        int rec[MAX] = {};
        memset(con, 0, sizeof(con));
        memset(vis, 0, sizeof(vis));
        while (N--) {
            int a, b;
            std::cin >> a >> b;
            rec[a]++;
            rec[b]++;
            con[a][b]++;
            con[b][a]++;
        }
        bool solvable = true;
        for (int i : rec) {
            if (i % 2 == 1) {
                solvable = false;
            }
        }

	std::cout << "Case #" << C << std::endl;
	
	if (solvable) {
        for (int i = 0; i < MAX; i++) {
            if (rec[i]) {
                check(i);
                for (int j = 0; j < MAX; j++) {
                    if (rec[j] && !vis[j]) {
                        solvable = false;
                    }
                }
                if (solvable) {
                    print(i);
                }
                break;
            }
        }
	}

	if (!solvable) 
            std::cout << "some beads may be lost" << std::endl;

        if (C< T)
            std::cout << std::endl;
    }
    return 0;
}
