#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;

const int INF1 = 2147483647; // 10^9
const ll INF2 = 9223372036854775807; // 10^18

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int L, R;
    cin >> L >> R;

    if (R - L <= 2019) {
        if (L >= 2019) L = L % 2019;
        if (R >= 2019) R = R % 2019;

        int count;

        if (L > R) count = 2019 - L + R + 1;
        else count = R - L + 1;

        vector<int> X(count);

        for (int i = 0; i < count; ++i) {
            X[i] = (L + i) % 2019;
        }

        int min1 = INF1;
        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                int t = (X[i] * X[j]) % 2019;

                if (t < min1) min1 = t;
            }
        }

        if (L == 0 and R == 0) min1 = 0;

        cout << min1 << endl;
    } else {
        int count = 2019;
        vector<int> Y(2019);

        int min1 = INF1;
        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                int t = (Y[i] * Y[j]) % 2019;

                if (t < min1) min1 = t;
            }
        }

        if (L == 0 and R == 0) min1 = 0;

        cout << min1 << endl;
    }

    return 0;
}