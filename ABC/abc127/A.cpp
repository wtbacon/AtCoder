#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int A, B;
    cin >> A >> B;

    if (A >= 13 ) cout << B << endl;
    else if (6 <= A and A <= 12) cout << B / 2 << endl;
    else cout << 0 << endl;

    return 0;
}