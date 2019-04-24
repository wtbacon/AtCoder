#include <iostream>

using namespace std;

int main() {
    int N;

    cin >> N;

    long safety = 1;
    for (long i = 0; i < 9; i++) safety *= 10;
    long power = 1;

    for (long n = 1; n <= N; n++) {
        power = power * n % (safety + 7);
    }

    cout << power << endl;
}
