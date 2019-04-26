#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * 「ある範囲に存在する西 (東) を向いている人の人数」の累積和を配列に入れておく.
 * 'W'と'E'で配列を作っておくと, minの計算が楽.
 */

int main() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    vector<int> w(N + 1, 0);
    vector<int> e(N + 1, 0);

    for (int i = 0; i < N; i++) {
        if (S[i] == 'W') {
            w[i + 1] = w[i] + 1;
            e[i + 1] = e[i];
        } else {
            w[i + 1] = w[i];
            e[i + 1] = e[i] + 1;
        }
    }

    int minDirection = 300000;
    for (int i = 0; i < N; i++) {
        minDirection = min(minDirection, w[i] + (e[N] - e[i + 1]));
    }
    cout << minDirection << endl;
}
