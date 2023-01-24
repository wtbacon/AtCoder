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


int knapsackProblem() {

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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    /**
        3 10
        9 15
        6 10
        4 6
        => 16
     */
    knapsackProblem();

    return 0;
}