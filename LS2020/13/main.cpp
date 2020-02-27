//
// Created by lactosis on 20.2.20.
//


#include <iostream>
#include <vector>

int main() {

    while (true) {
        int N;
        std::cin >> N;
        if (N == -1) break;

        std::vector<int> packets;
        packets.reserve(N);
        int curr;
        int sum = 0;
        int j = 0;
        for (int i = 0 ; i < N; ++i) {
            std::cin >> curr;
            packets.push_back(curr);
            sum += curr;
        }

        if (sum % N != 0) {
            std::cout << "-1" << std::endl;
            continue;
        }

        int avg = sum / N;
        sum = 0;
        for (int i: packets) {
            if (i < avg)
                sum += abs(avg - i);
        }

        std::cout << sum << std::endl;

    }
}