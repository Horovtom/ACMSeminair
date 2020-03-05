//
// Created by lactosis on 20.2.20.
//

#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int n, k , s;
    std::cin >> n >> k >> s;
    std::vector<int> boxes;

    for (int i = 0; i < n ; ++i) {
        int sc;
        std::cin >> sc;

        boxes.push_back(sc);
    }

    std::sort(boxes.begin(), boxes.end());


    int screwsTotal = k * s;

    for (int i = boxes.size() - 1; i >=0; --i ){
        screwsTotal -= boxes.at(i);
        if (screwsTotal <= 0) {
            std::cout << boxes.size() - i << std::endl;
            return 0;
        }
    }

}