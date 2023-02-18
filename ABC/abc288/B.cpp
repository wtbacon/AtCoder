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

    int N, K;
    cin >> N >> K;

    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    for (int i = 1; i < K; i++) {
        string v = S[i];

        int j = i;
        for (; j > 0; j--) {

            int L = v.size() < S[j - 1].size() ? v.size() : S[j - 1].size();
            bool flag = v.size() < S[j - 1].size();
            // S[j-1] と S[i] の比較
            bool bigger;  // S[j-1] の方が辞書順で大きいか
            int c = 0;
            for (; c < L; c++) {
                if ((int) v[c] < (int) S[j - 1][c]) {
                    bigger = true;
                    break;
                }
                if ((int) v[c] > (int) S[j - 1][c]) {
                    bigger = false;
                    break;
                }
                if (c == L - 1) {
                    if (flag) bigger = true;
                    else bigger = false;
                }
            }
            if (bigger) S[j] = S[j - 1];
            else break;
        }
        S[j] = v;
    }

    for (int i = 0; i < K; i++) {
        cout << S[i] << endl;
    }


    return 0;
}