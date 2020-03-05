//
// Created by lactosis on 5.3.20.
//

#include <iostream>
#include <vector>

int main() {
    std::string input;
    while (true) {
        std::cin >> input;
        if (input == "0") return 0;

        std::vector<int> last(input.size()), last2(input.size());

        last.at(0) = 1;
        last2.at(0) = 0;

        for (int i = 1; i < input.size(); ++i) {
            if (input.at(i) > '0')
                last.at(i) = last.at(i-1) + last2.at(i-1);
            if (input.at(i-1) > '0' && (input.at(i-1) - '0')*10+input.at(i-1) - '0' <= 26) {
                // Last2 could ve been numbers
                if (i >= 2)
                    last2.at(i) = last2.at(i-2) + last.at(i-2);
                else
                    last2.at(i) = 1;
            }
        }

        std::cout << last.at(input.size()-1) + last2.at(input.size() -1) << std::endl;
    }

}