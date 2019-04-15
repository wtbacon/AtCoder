#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a[100];
    int N;
    int Alice = 0;
    int Bob = 0;

    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    sort(a, a+N, greater<int>());

    for (int i = 0; i < N; i++) {
        if ( i % 2 == 0) Alice += a[i];
        else Bob += a[i];
    }

    cout << Alice - Bob << endl;
}
