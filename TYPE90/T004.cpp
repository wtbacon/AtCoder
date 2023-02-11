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

    int H, W;
    cin >> H >> W;

    vector<vector<int> > A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    vector<int> R(H);
    vector<int> C(W);
    rep(i, H) {
        rep(j, W) {
            R[i] += A[i][j];
            C[j] += A[i][j];
        }
    }

    rep(i, H) {
        rep(j, W) cout << R[i] + C[j] - A[i][j] << " ";
        cout << endl;
    }
    return 0;
}