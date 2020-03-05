//
// Created by lactosis on 20.2.20.
//

#include <iostream>
#include <vector>
#include <algorithm>


struct Segment
{
    int L, R;
};

bool comp(const Segment &s1, const Segment &s2)
{
    if (s1.L != s2.L) return s1.L < s2.L;

    return s1.R > s2.R;
}


int main() {
    int cases;
    std::cin >> cases;

    for (int testCase = 0; testCase < cases; ++testCase) {
        int M;
        std::cin >> M;

        std::vector<Segment> lines;
        int l, r;
        while(true) {
            std::cin >> l >> r;
            if (l == r && r == 0) break;
            // Throw away useless edges
            if (r < 0 || l > M) continue;
            lines.push_back({l,r});
        }

        std::sort(lines.begin(), lines.end(), comp);

        std::vector<Segment> usedSegments;
        int leftBound = 0;
        int rightBound = 0;
        int indexToUse=0;
        int lineCount = lines.size();

        while(rightBound < M) {
            int newLeftBound = leftBound;
            int bestIndex = -1;
            while(indexToUse < lineCount) {

                auto current = lines.at(indexToUse);
                if (current.L > leftBound) {
                    // Too far... No can do
                    break;
                }
                if (current.R > newLeftBound)
                {
                    newLeftBound = current.R;
                    bestIndex = indexToUse;
                }

                indexToUse++;
            }

            if (bestIndex == -1) break;
            usedSegments.push_back(lines.at(bestIndex));
            rightBound = leftBound = newLeftBound;
        }

        if (rightBound >= M) {
            std::cout << usedSegments.size() << std::endl;
            for (auto s : usedSegments) {
                std::cout << s.L << " " << s.R << std::endl;
            }

        } else {
            // Failed
            std::cout << "0" << std::endl;
        }
        std::cout << std::endl;
    }
}