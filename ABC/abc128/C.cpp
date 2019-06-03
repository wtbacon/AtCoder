#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> k(M, vector<int>(N + 1));
    vector<int> p(M);

    for (int m = 0; m < M; ++m) {
        cin >> k[m][0];
        for (int i = 0; i < k[m][0]; ++i) cin >> k[m][i + 1];
    }

    for (int i = 0; i < M; ++i) cin >> p[i];

    int total = 0;
    for (int mask = 0; mask < (1 << N); ++mask) {
        bool flag = true;
        for (int m = 0; m < M; ++m) {
            int tmpk = 0;
            for (int i = 0; i < k[m][0]; ++i) {
                if (mask & (1 << N - k[m][i + 1])) {
                    tmpk += 1;
                }
            }
            if (tmpk % 2 != p[m]) flag = false;
        }
        if (flag) total += 1;
    }

    cout << total << endl;

    return 0;
}

