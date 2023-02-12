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

#define rep(i, n) for (int (i) = 0; (i) < (n); ++(i))

using namespace std;

typedef long long ll;
const long long INF = LLONG_MAX;
const int MOD = pow(10, 9) + 7;

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

bool P(int i) {
    return i;
}

int binary_search() {
    int left, right;

    while (right - left > 1) {  // P(left)=false, P(right)=true より
        int mid = (right - left) / 2;
        if (P(mid)) right = mid;
        else left = mid;
    }
    return right;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    vector<vector<int> > nexts(N, vector<int>(26, N));

    // 貪欲法で求めるための前計算
    for (int i = N - 1; i >= 0; i--) {
        rep(j, 26) {
            if (S[i] - 'a' == j) nexts[i][j] = i;
            else nexts[i][j] = i == N - 1 ? nexts[i][j] : nexts[i + 1][j];
        }
    }

    string ans;
    int curIdx = 0; // S の index
    rep (k, K) {    // K を1つずつ貪欲法で求める
        rep (j, 26) {
            int nextIdx = nexts[curIdx][j];
            // nextIdx を K の1つとするとき、残りの S が K より大きくなけらばならない
            int remainLen = N - (nextIdx + 1);
            if (remainLen >= K - (k + 1)) {
                ans += (char) (j + 'a');
                curIdx = nextIdx + 1;   // nextIdx の文字を使うので、nextIdx 以降の範囲で貪欲法
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}