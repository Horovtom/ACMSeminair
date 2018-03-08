#include <iostream>

using namespace std;

int main() {

    long long int costToA = INT32_MAX;
    long long int costToB = 0;
    long long int costToC = INT32_MAX;
    long long int newCostToA;
    long long int newCostToB;
    long long int newCostToC;

    int currentCase = 1;
    int N;
    cin >> N;
    while(N > 0) {
        int a, b, c;
        for (int i = 0; i < N; ++i) {
            cin >> a >> b >> c;
            if (i == 0) {
                costToA = 1000000;
                costToB = b;
                costToC = b +c;
                continue;
            }



            newCostToA = min(costToA, costToB) + a;
            newCostToB = min(costToA, min(costToB, costToC)) + b;
            newCostToC = min(costToB, costToC) + c;
            newCostToB = min(newCostToB, newCostToA + b);
            newCostToC = min(newCostToC, newCostToB + c);

            costToA = newCostToA;
            costToB = newCostToB;
            costToC = newCostToC;
        }

        cout << currentCase++ << ". " << costToB << endl;

        cin >> N;
    }
}
