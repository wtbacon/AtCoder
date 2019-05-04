#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int A, B, T;
    cin >> A >> B >> T;

    int sum = 0;
    for (int i = A; i < T + 0.5;) {
        sum += B;
        i += A;
    }

    cout << sum << endl;

    return 0;
}