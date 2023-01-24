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
    /**
     * この問題を解くために重要な考察として、最初に A 円払う操作を何回かしてから B 円払う操作を何回か行うというように操作の順序を決め打っていいというものがあります。
     * また、 A 円払う操作の回数は N 回未満であるということも重要です。（ N 回行うと元に戻るため）
     *
     * AtCoder では、「K回以内行う」や「好きなだけ行う」と指定されている場合、操作ごとに不変な物が存在する場合があります。
     * また、操作の順番が決められている問題の時、結局どの順番で操作を行ったとしても結果が変わらない場合があります。
     * このような場合は、自分にとって都合の良い順番で操作を行うと良いです。
     */
    int N;
    long long A, B;
    string S;
    cin >> N >> A >> B >> S;
    S += S; // Rotation ごとに文字列を作らずに済む

    ll ans = LLONG_MAX;
    for (int i = 0; i < N; i++) {
        ll tmp = A * i;
        for (int j = 0; j < N / 2; j++) { // 真ん中から左右の文字が一致していなければ交換する
            int l = i + j;
            int r = i + N -1 - j;
            if (S[l] != S[r]) tmp += B;
        }
        ans = min(ans, tmp);
    }

    cout << ans << endl;
}
