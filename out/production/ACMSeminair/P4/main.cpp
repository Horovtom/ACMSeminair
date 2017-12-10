#include <iostream>
#include <cmath>
using namespace std;

int numRows, numCols;

struct position {
    int x, y;
};

int distTo(position pos1, position pos2) {
    return abs(pos1.x - pos2.x) + abs(pos1.y - pos2.y);
}

bool catOnDiagonal(position mouse, position cat1, position cat2) {
    return (((cat1.x == mouse.x - 1 && cat1.x == cat2.x - 2) && (cat1.y == mouse.y - 1 && cat1.y == cat2.y - 2)) ||
            ((cat2.x == mouse.x - 1 && cat2.x == cat1.x - 2) && (cat2.y == mouse.y - 1 && cat2.y == cat1.y - 2)) ||
            ((cat2.x == mouse.x + 1 && cat2.x == cat1.x + 2) && (cat2.y == mouse.y - 1 && cat2.y == cat1.y - 2)) ||
            ((cat1.x == mouse.x + 1 && cat1.x == cat2.x + 2) && (cat1.y == mouse.y - 1 && cat1.y == cat2.y - 2)));
}

bool escapeThrough(int x, int y, position mouse, position cat1, position cat2) {
        position pos = {x,y};
        int distMouse = distTo(mouse, pos);
        if (distMouse < distTo(cat1, pos) && distMouse < distTo(cat2, pos)) {
                //cout << "It can escape through: " << x << " " << y << endl;   
                return true;
        }
        return false;
}

bool canEscape(position mouse, position cat1, position cat2) {
    //Boundaries of map
    if (mouse.x == 1 || mouse.x == numRows || mouse.y == 1 || mouse.y == numCols) return true;
    //They are on same cells, so its Game Over
    if ((mouse.x == cat1.x && mouse.y == cat1.y) && (mouse.x == cat2.x && mouse.y == cat2.y)) return false;
    //Both cats are behind mouse, so its a win
    if ((mouse.x >= cat1.x && mouse.x >= cat2.x) || 
        (mouse.y >= cat1.y && mouse.y >= cat2.y) ||
        (mouse.x <= cat1.x && mouse.x <= cat2.x) || 
        (mouse.y <= cat1.y && mouse.y <= cat2.y))  return true;
        
    //If they are on diagonal, mouse lost:
    if (catOnDiagonal(mouse, cat1, cat2)) return false;
    
    int distCat1, distCat2, distMouse;
    position pos = {};
    //If cats dist to every escape is lower or equal than mouses dist to every escape, it lost.
    for (int y = 1; y <= numRows; y++) {
        if (escapeThrough(1, y, mouse, cat1, cat2) || escapeThrough(numCols, y, mouse, cat1, cat2)) return true;
    }
    
    for (int x = 1; x <= numCols; x++) {
        if (escapeThrough(x, 1, mouse, cat1, cat2) || escapeThrough(x, numRows, mouse, cat1, cat2)) return true;
    }
    
    return false;
}



int main() {
    
    int testCases;
    cin >> numRows;
    cin >> numCols;
    cin >> testCases;
    position mouse, cat1, cat2;
    for (int i = 0; i < testCases; i++) {
        cin >> mouse.x;
        cin >> mouse.y;
        cin >> cat1.x;
        cin >> cat1.y;
        cin >> cat2.x;
        cin >> cat2.y;
        
        if (canEscape(mouse, cat1, cat2)) cout << "YES" << endl;
        else cout << "NO" << endl;
        //cout << "Position of cat2: " << cat2.x << " " << cat2.y << endl;
    }
    return 0;
    
    /*
    cout << catOnDiagonal({1,1}, {0, 0}, {2, 2}) << endl; //Should be yes.
    cout << catOnDiagonal({1,1}, {2,2}, {0, 0}) << endl; //Should be yes.
    cout << catOnDiagonal({1,1}, {2, 0}, {0, 2}) << endl; //Should be yes.
    cout << catOnDiagonal({1,1}, {0,2}, {2, 0}) << endl; // Should be yes.
    cout << catOnDiagonal({1,1}, {1, 0}, {1, 2}) << endl; //Sould be no.
    cout << catOnDiagonal({1,1}, {1,2}, {1,0}) <<endl; //shoul be no.
    cout << catOnDiagonal({1,1}, {0,1}, {2, 1}) << endl; //Should be no.
    cout << catOnDiagonal({0, 0}, {1, 1}, {2,2}) << endl; //Should be no.
    */
    
    //cout << distTo({2,2}, {5,3}) << endl;
}
