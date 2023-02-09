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

ll N, L, K;

bool greedy(ll M, vector<ll> &A) {
    ll cnt = 0, pre = 0;    // cnt は piece の数ではなく仕切りを入れた数

    rep(N) {
        if (A[i] - pre >= M && L - A[i] >= M) {
            cnt++;
            pre = A[i];
        }
    }
    if (cnt >= K) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> L;
    cin >> K;

    vector<ll> A(N);
    rep(N) cin >> A[i];

    ll left = 0, right = L;

    while (right - left > 1) {  // P(left)=true, P(right)=false より
        ll mid = (right + left) / 2;
        if (!greedy(mid, A)) right = mid;
        else left = mid;
    }

    cout << left << endl; // P(left)=true
    return 0;
}