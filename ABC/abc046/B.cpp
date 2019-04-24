#include <iostream>

using namespace std;

int main() {

    int N, K;
    cin >> N >> K;

    long res = K;

    for (int i = 1; i < N;i++) {
        res = res * (K-1);
    }

    cout << res << endl;
}