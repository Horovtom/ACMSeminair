#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define NUM_PLACES 100

int link[NUM_PLACES][NUM_PLACES], n, depth[NUM_PLACES], low[NUM_PLACES],
used[NUM_PLACES], cut;
int DFS(int node, int d, int parent) {
    int i, back = INT_MAX, son = 0, tmp, flag = 0;
    depth[node] = d;
    for(i = 1; i <= n; i++) {
        if(link[node][i] == 1) {
            if(used[i] == 0) {
                used[i] = 1;
                tmp = DFS(i, d+1, node);
                if(tmp >= d) {
                    flag = 1;
                }
                if (back >= tmp) {
                    back = tmp;
                }
                back = back < tmp ? back : tmp;
                son++;
            } else {
                if(i != parent)
                    back = back < depth[i] ? back : depth[i];
            }
        }
    }
    low[node] = back;
    if(node == 1) {
        if(son > 1)
            cut++;
    } else {
        cut += flag;
    }
    return low[node];
}
int main() {
    int x, y;
    char c;
    while(scanf("%d", &n) == 1 && n) {
        memset(link, 0, sizeof(link));
        memset(depth, 0, sizeof(depth));
        memset(low, 0, sizeof(low));
        memset(used, 0, sizeof(used));
        while(scanf("%d", &x) == 1 && x) {
            while(scanf("%d%c", &y, &c) == 2) {
                link[x][y] = 1;
                link[y][x] = 1;
                if(c == '\n')	break;
            }
        }
        used[1] = 1;
        cut = 0;
        DFS(1, 1, 0);
        printf("%d\n", cut);
    }
    return 0;
}
