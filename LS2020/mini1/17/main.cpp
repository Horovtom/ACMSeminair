//
// Created by lactosis on 20.2.20.
//

#include <iostream>

int main() {

    float c;
    std::cin >> c;

    while(c) {
        float len = 0.00;
        int n = 0;
        while (len < c) {
            n++;
            len += 1.00 / (1.00 + n);

        }

        std::cout << n << " card(s)" << std::endl;
        std::cin >> c;
    }

}