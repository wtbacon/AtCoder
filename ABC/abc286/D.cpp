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
#include <cstring>

//#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

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

    int N, X;
    cin >> N >> X;

    int MAX_N = 50;
    int MAX_X = pow(10, 4);
    vector<int> A(MAX_N);
    vector<int> B(MAX_N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    vector<int> dp(MAX_X + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= X; j++) {
            if (dp[j] >= 0) {
                dp[j] = B[i];
            } else if (j < A[i] || dp[j - A[i]] <= 0) {
                dp[j] = -1;
            } else {
                dp[j] = dp[j - A[i]] - 1;
            }
        }
    }

    if (dp[X] >= 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}