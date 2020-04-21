//
// Created by lactosis on 2.4.20.
//


#include <cstdio>

int mat[1000][1000];
int rsum[1000], csum[1000];

int main() {
    int n, i, j, sum, diff, cs = 1;
    while(scanf("%d", &n)==1 && n) {
        for(i = sum = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                scanf("%d", &mat[i][j]);
                sum += mat[i][j];
            }
        }
        for(i = 0; i < n; i++) {
            for(rsum[i] = csum[i] = j = 0; j < n; j++) {
                rsum[i] += mat[i][j];
                csum[i] += mat[j][i];
            }
        }
        for(i = diff = 0; i < n; i++)
            if(rsum[i] > csum[i])
                diff += rsum[i] - csum[i];
        printf("%d. %d %d\n", cs++, sum, diff);
    }
    return 0;
}