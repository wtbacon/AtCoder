#include <iostream>

using namespace std;

int N;
int A[210];

int main() {

    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];

    int res = 0;
    while (true) {

        bool flag = false;

        for (int i = 0; i < N; ++i) {
            if (A[i] % 2 != 0) {
                flag = true;
                break;
            } else {
                A[i] /= 2;
            }
        }

        if (flag) break;

        ++res;

    }
    cout << res <<  endl;
}
