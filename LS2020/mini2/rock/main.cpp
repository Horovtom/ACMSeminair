//
// Created by lactosis on 5.3.20.
//
#include <iostream>
#include <bits/stdc++.h>

#define SWEET '1'
// 0123456789
// 100110001010001
std::string a;
int N;

std::vector<int> calculated;

int calculate(int endPos) {
    if (calculated[endPos] != -1) return calculated[endPos];
    int ifBreakHere = 0;
    // If i break here, how many I get?
    int sweetsBalance = 0;
    for (int i = endPos; i > 0; --i) {
        if (a.at(i-1) == SWEET) sweetsBalance++;
        else sweetsBalance--;

        if (sweetsBalance > 0) {
            // I could start at i-1
            ifBreakHere = std::max(ifBreakHere, endPos-i+1 + calculate(i-1));
        }
    }

    calculated[endPos] = std::max(ifBreakHere, calculate(endPos-1));
    return calculated[endPos];
}


int main() {

    int t;
    std::cin >> t;
    while(t--) {
        std::cin >> N;
        std::cin >> a;

        calculated.resize(N+1, -1);
        std::fill(calculated.begin(), calculated.end(), -1);
        calculated.at(0) = 0;

        std::vector<int> br;
        std::vector<int> nbr;

        br.resize(a.size()-1);
        nbr.resize(a.size()-1);

        int res = calculate(a.size());
        std::cout << res << std::endl;
    }

}


