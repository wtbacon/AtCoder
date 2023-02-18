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
const double pi = 3.14159265358979;

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

int binary_search() {
    int left = 0, right = 0;

    while (right - left > 1) {  // P(left)=false, P(right)=true より
        int mid = (right - left) / 2;
        if (mid) right = mid;
        else left = mid;
    }
    return right;
}

struct Point {
  double x, y;
};

Point operator-(const Point &p1, const Point &p2) {
    return {p1.x - p2.x, p1.y - p2.y};
}


double getAngleFromB(Point p) {
    double ang = atan2(p.y, p.x) * 180.0 / pi;
    return ang < 0.0 ? 360.0 - abs(ang) : ang;
}

double getAngleByTwoPoints(double A, double C) {
    // 原点と見立てた B からの偏角が A, C であることに注意
    double diff = abs(A - C);
    return diff >= 180.0 ? 360.0 - diff : diff;
}

using Graph = vector<vector<int> >;

int findConnectedComponentByDfs(const Graph &G) { // bfsGraphWithQueue(): Stack => Queue
    /**
     * Graph の連結成分(connected Component) の数を求める
     * G: Graph
     */
    int N = (int) G.size();

    vector<bool> seen(N, false);
    int cnt = 0;

    rep (i, N) {
        if (!seen[i]) {
            seen[i] = true;
            cnt++;
            stack<int> todo;
            todo.push(i);

            while (!todo.empty()) {
                int v = todo.top();
                todo.pop();

                for (int x : G[v]) {
                    if (seen[x]) continue;
                    seen[x] = true;
                    todo.push(x);
                }
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    Graph G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // int cnt = findConnectedComponentByDfs(G);

    int cnt = 0;
    vector<bool> seen(N, false);

    rep (i, N) {
        if (!seen[i]) {
            seen[i] = true;
            cnt++;
            stack<int> todo;
            todo.push(i);

            while (!todo.empty()) {
                int v = todo.top();
                todo.pop();

                for (int x : G[v]) {
                    if (seen[x]) continue;
                    seen[x] = true;
                    todo.push(x);
                }
            }
        }
    }

    // 式変形することで各連結成分の深さを頂点の数を求めずに済む
    // https://atcoder.jp/contests/abc288/editorial/5662
    int ans = M - N + cnt;

    if (ans < 0) {
        cout << 0 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}