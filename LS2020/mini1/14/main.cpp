//
// Created by lactosis on 20.2.20.
//

#include <iostream>
#include <vector>

#define ONE 0
#define ONEZERO 1

int main() {
    int testcases;
    std::cin >> testcases;
    for (int test = 0;  test < testcases; ++test) {
        std::string input;
        std::vector<int> depths;
        int currDepth = -1;
        std::cin >> input;

        for (char ch : input) {

            if (ch == '1') {
                depths.push_back(ONE);
                currDepth++;
            } else {
                if (currDepth < 0) {
                    // Flush line
                    currDepth= 1000;
                    break;
                }

                if (depths.at(currDepth) == ONEZERO) {
                    depths.pop_back();
                    currDepth--;
                }
                else depths.at(currDepth) = ONEZERO;

            }
        }
        if (currDepth >= 0) std::cout << "Case " << test + 1 << ": no" << std::endl;
        else std::cout << "Case " << test + 1 << ": yes" << std::endl;

    }

}