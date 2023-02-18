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

string slice(string const &v, int m, int n) {
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + n + 1;

    string s(first, last);
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    int cnt = 0;
    vector<string> S(N), T(M);
    unordered_set<string> t(M);
    vector<string> s(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    for (int i = 0; i < M; i++) cin >> T[i];

    for (auto &tt : T) t.insert(tt);
    for (int i = 0; i < N; i++) {
        auto ss = slice(S[i], 3, 5);
        if (t.count(ss)) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}