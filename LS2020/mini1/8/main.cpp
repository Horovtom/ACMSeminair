#include<cstdio>
#include<hash_map>
#include<algorithm>
#include <iostream>
#include <map>
#include <cmath>

std::map<int,int> flakes;
int cases, flakeCount, x, i, u, mx;
int main(){

    std::cin >> cases;

    while( cases-- ){
        std::cin >> flakeCount;

        flakes.clear();
        mx = u = 0;
        for( i=1; i<=flakeCount; ++i ){
            std::cin >> x;
            int& r = flakes[x];
            if( r>u ){
                mx = std::max(mx,i-u-1);
                u = r;
            }
            r = i;
        }
        mx = std::max(mx,flakeCount-u);

        std::cout << mx << std::endl;
    }
}