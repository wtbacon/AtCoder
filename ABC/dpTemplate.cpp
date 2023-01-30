#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
//#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const long long INF = 1LL << 60; // 2^60

// change minimum
template<class T>
void chmin(T &a, T b) {
    if (a > b) a = b;
}

// change maximum
template<class T>
void chmax(T &a, T b) {
    if (a < b) a = b;
}


int knapsackProblem01() {

    int N;
    ll W;
    cin >> N >> W;

    vector<ll> weight(N), value(N);
    for (int i = 0; i < N; i++) cin >> weight[i] >> value[i];

    // 外側の配列のインデックスは品物 i 番目までを対象にしていることを意味する。
    // 内側の配列のインデックスは重さの総和が w を超えてはならないことを意味する。
    // 何もない状態では、品物も重さも 0 になるため、要素数は N+1, W+1 となる。
    vector<vector<ll> > dp(N + 1, vector<ll>(W + 1, 0));

    for (int i = 0; i < N; i++) { // dp[i+1] に配る遷移形式であることに注意
        for (int w = 0; w <= W + 1; w++) {
            // 検討する品物 i+1 の重さ weight[i+1] が制約以下でないと選べない => array index out of bounds
            if (w - weight[i] >= 0) {
                dp[i + 1][w] = max(dp[i][w - weight[i]] + value[i], dp[i + 1][w]);
            }

            // 検討する品物 i+1 を選ばない場合
            dp[i + 1][w] = max(dp[i + 1][w], dp[i][w]);
        }
    }
    cout << dp[N][W] << endl;
}

int unrestrictedKnapsackProblem() {
    int N, W;
    cin >> N >> W;

    vector<int> v(N);
    vector<int> w(N);
    for (int i = 0; i < N; i++) cin >> v[i] >> w[i];

    vector<vector<int> > dp(N + 1, vector<int>(W + 1, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= W; j++) {
            if (j - w[i] >= 0) dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);
            else dp[i + 1][j] = dp[i][j];
        }
    }

    cout << dp[N][W] << endl;
    return 0;
}

int restrictedPartialSumProblem() { // 個数制限付きはYes/No問題が多い
    int N, X;
    cin >> N >> X;

    vector<int> A(N); // 数
    vector<int> B(N); // A_i の個数　
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    vector<vector<int> > dp(N + 1, vector<int>(X + 1, -1));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= X; j++) {
            if (dp[i][j] >= 0) dp[i + 1][j] = B[i];
            else if (j < A[i] || dp[i + 1][j - A[i]] < 0) dp[i + 1][j] = -1;
            else dp[i + 1][j] = dp[i + 1][j - A[i]] - 1;
        }
    }
    if (dp[N][X] >= 0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}

int unrestrictedPartialSumProblem() {   // 個数制限なしは最小/最大個数問題が多い

    int N, amount;
    cin >> N >> amount;

    vector<int> coins(N);
    for (int i = 0; i < N; i++) cin >> coins[i];

    vector<vector<int> > dp(N + 1, vector<int>(amount + 1, amount + 1));
    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= amount; j++) {
            if (j - coins[i] >= 0) dp[i + 1][j] = min(dp[i][j], dp[i + 1][j - coins[i]] + 1);
            else dp[i + 1][j] = dp[i][j];
        }
    }

    if (dp[N][amount] > amount) cout << "-1" << endl;
    else cout << dp[N][amount] << endl;

    return 1;
}

int LCSProblem() {
    string S, T;
    cin >> S >> T;

    int N = S.size();
    int M = T.size();

    vector<vector<int> > dp(N + 1, vector<int>(M + 1, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (S[i] == T[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
            else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }

    cout << dp[N][M] << endl;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    /**
     * https://atcoder.jp/contests/abc032/tasks/abc032_d
        3 10
        9 15
        6 10
        4 6
        => 16
     */
    // knapsackProblem01();

    /**
     * https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_C&lang=jp
        4 8
        4 2
        5 2
        2 1
        8 3
        => 21
     */
    // unrestrictedKnapsackProblem();

    /**
     * https://atcoder.jp/contests/abc286/tasks/abc286_d
     2 19
     2 3
     5 6
     => Yes

     2 18
     2 3
     5 6
     => No
     */
    // restrictedPartialSumProblem();

    /**
     * https://leetcode.com/problems/coin-change/
        3 11
        1
        2
        5
     */
    // unrestrictedPartialSumProblem();

    /**
     * https://algo-method.com/tasks/314
        abracadabra
        aabraardba
        => 8
     */
    // LCSProblem();

    return 0;
}