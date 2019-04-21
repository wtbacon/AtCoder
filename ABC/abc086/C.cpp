#include <iostream>

using namespace std;

int main() {

    int N;
    int t[100010], x[100010], y[100010];

    cin >> N;
    t[0] = x[0] = y[0] = 0;
    for (int i = 0; i < N; i++) cin >> t[i + 1] >> x[i + 1] >> y[i + 1];

    bool can = true;
    for (int i = 0; i < N; i++) {
        // 移動することができる回数.
        int dt = t[i + 1] - t[i];
        // 必要最低限の移動回数
        int dist = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);

        if (dt < dist) can = false;
        if (dist % 2 != dt % 2) can = false;
    }

    if (can) cout << "Yes" << endl;
    else cout << "No" << endl;
}