//
// Created by lactosis on 5.3.20.
//
#include <iostream>
#include <vector>
#include <set>
#include <bits/stdc++.h>
#include <algorithm>

std::vector<std::vector<int>> common; // common.at(aIndex).at(bIndex);
std::string a, b; // rename to a, b
std::set<std::string> strings;
int lenA, lenB;
int dp[82][82];
int sequenceLen;
char readyStr[100]; // WTF>

int solve(int i, int j) {
    if (i == lenA || j == lenB)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (a[i] == b[j])
        return dp[i][j] = 1 + solve(i + 1, j + 1);
    else
        return dp[i][j] = std::max(solve(i + 1, j), solve(i, j + 1));
}

void print(int posA, int posB, int currLen) {
    if (currLen == sequenceLen) {
        readyStr[sequenceLen] = '\0';
        std::cout << readyStr << std::endl;
        return;
    }

    for (char c = 'a'; c <= 'z'; c++) {
        bool done = false;
        for (int x = posA; x < lenA; x++) {
            if (c == a[x]) {
                for (int y = posB; y < lenB; y++) {
                    if (c == b[y] && solve(x, y) == sequenceLen - currLen)
                    {
                        readyStr[currLen] = c;
                        print(x + 1, y + 1, currLen + 1);
                        done = true;
                        break;
                    }
                }
            }
            if (done)
                break;
        }
    }
}

int main() {

    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        std::cin >> a >> b;


        lenA = a.size();
        lenB = b.size();

        memset(dp, -1, sizeof(dp));

        sequenceLen = solve(0, 0);
        print(0, 0, 0);
    }


}
