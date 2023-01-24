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

#define rep(n) for (int i = 0; i < (n); ++i)

using namespace std;

typedef long long ll;
const long long INF = 1LL << 60; // 2^60

// change minimum
template<class T>
void chmin(T &a, T b) {
    if (a > b) {
        a = b;
    }
}

// change maximum
template<class T>
void chmax(T &a, T b) {
    if (a < b) a = b;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, W;
    cin >> N >> W;

    vector<int> v(N);
    vector<int> w(N);

    rep(N) cin >> v[i] >> w[i];

    vector<vector<ll> > dp(N + 1, vector<ll>(W + 1, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= W; ++j) {
            // N 個の品物を 0 始まりの添字で表現する: i(0 <= i <= N-1)番目の品物
            // したがって、i番目の品物の価値と重さ: v[i], w[i]
            // 「最初のi個(i-1番目まで)の品物から重さの総和がj以下となるように選んだ状態」: dp[i][j]
            // 「最初のi+1個(i番目まで)の品物から重さの総和がj以下となるように選んだ状態」: dp[i+1][j]
            // 「最初のi+1個(i番目まで)の品物から重さの総和がj-w[i]以下となるように選んだ状態」: dp[i+1][j-w[i]]
            // 以下、i番目の品物を含めるか含めないかを検討している。i番目の品物の検討の場合、dpの添字はi+1になる。
            if (j - w[i] >= 0) {
                chmax(dp[i+1][j], dp[i][j - w[i]] + v[i]);
            }
            chmax(dp[i + 1][j], dp[i][j]);
        }
    }

    cout << dp[N][W] << endl;
    return 0;
}