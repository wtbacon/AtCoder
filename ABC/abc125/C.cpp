#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int gcd(int x, int y) {
    if (x < y) swap(x, y);
    if (y == 0) return x;
    return gcd(x % y, y);
}

/**
 * A[i] を書き換える場合, 残りの N − 1 個の最大公約数に書き換えれば,
 * 「整数 A[i] を書き換える」操作は「整数 A[i] を消す」操作と等価になる.
 */
int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> L(N);
    vector<int> R(N);

    int A[N];
    for (int i = 0; i < N; i++) cin >> A[i];

    /**
     * L[i] : A[i] が選ばれたときに, A[0] ~ A[i-1] までの最大公約数を格納する配列.
     * L[0] には「0」が入る.（ A[1] ~ A[N-1] までの最大公約数 R[i] に書き換えるため ）
     */
    for (int i = 0; i < N - 1; i++) L[i + 1] = gcd(L[i], A[i]);

    /**
     * R[i] : A[i] が選ばれたときに, A[i+1] ~ A[N-1] までの最大公約数を格納する配列.
     * R[N-1] は「0」が入る.（ A[0] ~ A[N-2] までの最大公約数 L[i] に書き換えるため ）
     */
    for (int i = N - 1; i >= 1; --i) R[i - 1] = gcd(R[i], A[i]);

    int ans = 1;

    for (int i = 0; i < N; i++) ans = max(ans, gcd(L[i], R[i]));

    cout << ans << endl;

    return 0;
}

