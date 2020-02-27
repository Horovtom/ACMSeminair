//
// Created by lactosis on 20.2.20.
//


#include <iostream>

int main() {
    int cases;
    std::cin >> cases;

    for (int currCase = 0; currCase < cases ; ++currCase){
        char ch;
        scanf(" %c", &ch);
        bool loadingA = true;
        int multiplier = 1;
        int a = 0, b = 0;
        while(ch != '\n') {
            if (ch == ' ') {
                loadingA = false;
                multiplier = 1;
            } else {
                if (loadingA) {
                    a += multiplier * (ch - '0');
                } else {
                    b += multiplier * (ch - '0');
                }
                multiplier *= 10;
            }
            scanf("%c", &ch);
        }


        int res = a + b;
        multiplier = 10;
        int cipher;
        bool isTrailing = true;
        while(res > 0) {
            cipher = res % multiplier;
            res = (res - cipher) / 10;
            if (isTrailing && cipher == 0) continue;
            std::cout << cipher;
            isTrailing = false;
        }

        std::cout <<  std::endl;

    }

}