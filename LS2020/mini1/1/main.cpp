//
// Created by lactosis on 20.2.20.
//

#include <iostream>

int main() {
    /*
6 4
\//\\/
\///\/
//\\/\
\/\///
3 3
///
\//
\\\
0 0
     */

    // NOTES: We can go from the top. If there is /\ in there, it can be a part of the cycle. However it cannot be a cycle otherwise


    int w, h;
    std::cin >> w >> h;
    while(w > 0 && h > 0) {
        for (int row = 0; row < h; ++row){
            for (int col = 0; col < w; ++col) {
                // The first line contained /\, we can save the index of it.
                // TODO:
            }
        }
    }

}