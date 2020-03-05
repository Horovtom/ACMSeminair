//
// Created by lactosis on 20.2.20.
//


#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    int testcases;
    std::cin >> testcases;
    for (int currTests = 0; currTests < testcases; ++currTests) {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> heights;
        for (int i = 0; i < n; ++i) {
            int val;
            std::cin >> val;
            heights.push_back(val);
        }

        std::sort(heights.begin(), heights.end());

        int minDiff = 1000000000;

        for (int i = 0; i <= n-k; ++i) {
            int lowest = heights.at(i);
            int highest = heights.at(i+k - 1);
            if (minDiff > highest - lowest)
                minDiff = highest - lowest;
        }

        std::cout << minDiff << std::endl;

    }
}