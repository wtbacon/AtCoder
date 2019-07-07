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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, D;

    cin >> N >> D;

    double X[N][D];
    rep(i, N) rep(j, D) cin >> X[i][j];

    int count = 0;
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; j++) {
            double tmp = 0.0;
            for (int d = 0; d < D; d++) tmp += pow(X[i][d] - X[j][d], 2);
            double s = sqrt(tmp);
            if (ceil(s) == floor(s)) count += 1;
        }
    }

    cout << count << endl;
    return 0;
}