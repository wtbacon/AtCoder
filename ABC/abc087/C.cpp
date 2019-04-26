#include <iostream>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    int A1[N];
    int A2[N];

    for (int i = 0; i < N; i++) cin >> A1[i];
    for (int i = 0; i < N; i++) cin >> A2[i];

    int mc = 0;
    for (int i = 0; i < N; i++) {
        int candies = 0;
        for (int j = 0; j <= i; j++) candies += A1[j];
        for (int j = i; j < N; j++) candies += A2[j];
        mc = max(mc, candies);
    }
    cout << mc << endl;
}

