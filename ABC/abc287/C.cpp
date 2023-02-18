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

vector<int> dfsGraphWithStack(const Graph &G, int s) { // bfsGraphWithQueue(): Stack => Queue
    /**
     * Node v を始点とした探索を行う。
     * 全 Node を探索する場合、全 Node を始点としてこの関数を callする必要がある。
     * G: Graph
     * s: 始点となる Node
     */
    int N = (int) G.size();

    vector<bool> seen(N, false);
    stack<int> todo;
    vector<int> degrees(N, 0);

    seen[s] = true;
    todo.push(s);

    while (!todo.empty()) {
        int numDegree = 0;
        int v = todo.top();
        todo.pop();

        for (int x : G[v]) {
            numDegree++; // 辿ってきたノードもカウントする
            if (seen[x]) continue;
            seen[x] = true;
            todo.push(x);
        }
        degrees[v] = numDegree;
    }
    return degrees;
}

/**
 *  連結ではないケース
    5 4
    1 2
    3 4
    4 5
    3 5
    => "No"
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    Graph G(N);
    rep (i, M) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--, v2--;
        G[v1].push_back(v2);
        G[v2].push_back(v1);
    }

    if (M != N - 1) {
        cout << "No" << endl;
        return 0;
    }

    vector<int> degrees = dfsGraphWithStack(G, 0);

    rep (i, N) {
        int numDegree = degrees[i];
        // グラフの連結性と次数の制約の確認
        if (numDegree == 0 || numDegree > 2) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}