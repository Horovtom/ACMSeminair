//
// Created by lactosis on 20.2.20.
//

#include <iostream>
#include <vector>
#include <set>

int main() {
    int friendCount;
    std::cin >> friendCount;

    std::set<int> possibleFF;
    std::set<int> friends;

    for (int friendIndex = 0; friendIndex < friendCount; ++friendIndex){
        int friendNumber;
        std::cin >> friendNumber;
        int friendFriends;
        std::cin >> friendFriends;

        for (int i = 0; i < friendFriends; ++i) {
            int friendFriend ;
            std::cin >> friendFriend;
            possibleFF.insert(friendFriend);
        }

        friends.insert(friendNumber);
    }

    for (int num : friends) {
        possibleFF.erase(num);
    }

    std::cout << possibleFF.size() << std::endl;

}