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

    int N;
    cin >> N;
    int numFor = 0;
    int numAgainst = 0;

    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    for (auto &s : S) s == "For" ? numFor++ : numAgainst++;

    if (numFor > numAgainst) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}