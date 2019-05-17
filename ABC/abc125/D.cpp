#include <iostream>
#include <vector>
#include <numeric>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

const int INF = 1001001001;

/**
 * A[i] = 0 となる i が存在しない場合、操作によって A[i] < 0 となる i の数の偶奇は変化しない.
 * つまり, A[i] < 0 となる i の数が
 * 偶数の時は, A の総和を取れば良く,
 * 奇数の時は, 負のままにしておく数を１つ選ぶ必要があり, それは絶対値が最小のものを選ぶのが最適となる.
 */
int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> L(N);
    vector<int> R(N);

    vector<int> A(N);
    rep(i, N) cin >> A[i];

    long long ans = 0;
    int neg = 0;

    /**
     * A の絶対値の総和を計算するとともに, 負の個数を数える.
     */
    rep(i, N) {
        ans += abs(A[i]);
        if (A[i] < 0) neg++;
    }

    /**
     * 奇数の時は, 絶対値が最小のものを負のままにしておく数にして, 総和から引く.
     */
    if (neg % 2 == 1) {
        int minA = INF;
        for (int i = 0; i < N; ++i) minA = min(minA, abs(A[i]));
        ans -= minA * 2;
    }

    cout << ans << endl;

    return 0;
}

