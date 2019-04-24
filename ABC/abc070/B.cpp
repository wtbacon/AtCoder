#include <iostream>

using namespace std;

int main() {
    int A, B, C, D;

    cin >> A >> B >> C >> D;

    int start = 0;
    int period = 0;

    if (A <= C) start = C;
    else start = A;

    if (start > B | start > D) period = 0;

    if ( B <= D and start < B) period = B - start;
    if ( D <= B and start < D) period = D -start;

    cout << period << endl;
}


/**
 * int lower = max(A,C);
 * int upper = min(B,D);
 * cout << max(0,upper-lower) << endl;
 */
