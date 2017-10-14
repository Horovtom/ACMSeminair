#include <iostream>
using namespace std;

int searchForNode(char arr[], char ch, int maxLen) {
    for (int i = 0; i < maxLen; i++) {
        if (arr[i] == ch) {
            return i;
        }
    }
    return -1;
}

void printPostOrder(char in[], char pre[], int n) {
    //The first element in preOrder is always root, 
    //search it in inorder to find left arnd right subtrees
    int rootInIndex = searchForNode(in, pre[0], n);
    
    //LST
    if (rootInIndex != 0) {
        printPostOrder(in, pre + 1, rootInIndex);
    }
    
    //RST
    if (rootInIndex != n - 1) {
        printPostOrder(in + rootInIndex + 1, pre + rootInIndex + 1, n - rootInIndex - 1);
    }
    
    cout << pre[0];
} 


int main() {
    int howManyInputSets, nodeCount;
    cin >> howManyInputSets;
    
    for (int i = 0; i < howManyInputSets; i++) {
        cin >> nodeCount;
        char preOrder[nodeCount + 1], inOrder[nodeCount + 1];
        cin >> preOrder;
        cin >> inOrder;
        int n = (sizeof(preOrder) / sizeof(char)) - 1;
        printPostOrder(inOrder, preOrder, n);
        cout << endl;
    }
    /*
    cout << "PreOrder: " << preOrder << endl;
    cout << "InOrder: " << inOrder << endl;
    cout << "Size of preorder: " << (sizeof(preOrder) / sizeof(preOrder[0])) << endl;
    cout << "Size of inorder: " << (sizeof(inOrder) / sizeof(inOrder[0])) << endl;
    */
    
    return 0;
}
