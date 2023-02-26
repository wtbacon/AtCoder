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

template<class T>
bool chminBool(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    } else {
        return false;
    }
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

ll lsm(ll a, ll b) {
    // by GCD * LSM = a * b
    return a / gcd(a, b) * b;
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

// Union-Find
struct UnionFind {
  /**
   * par: 各ノードの根ノードの番号(自分が根の場合は -1)
   * siz: 各ノードの属する根付き木のノード数
   */
 private:
  vector<int> par, siz;

 public:
  // UnionFind(int n) : par(n, -1), siz(n, 1) {}
  void init(int n) {
      par.resize(n, -1), siz.resize(n, 1);
  }

  // root を求める
  int root(int x) {
      if (par[x] == -1) return x;
      else return par[x] = root(par[x]); // 経路圧縮
  }

  // x と y が同じグループか(root が同じか)
  bool issame(int x, int y) {
      return root(x) == root(y);
  }

  // x のグループと y のグループを併合する
  bool unite(int x, int y) {
      x = root(x);
      y = root(y);

      if (x == y) return false;

      // Union by size
      if (siz[x] < siz[y]) swap(x, y);

      par[y] = x;
      siz[x] += siz[y];
      return true;
  }

  // x のグループのサイズ
  int size(int x) {
      return siz[root(x)];
  }
};

struct Edge {
  int to; // 隣接Node番号
  ll w;

  Edge(int to, ll w) : to(to), w(w) {
  }
};

using Graph = vector<vector<Edge> >;

int N, M;

vector<ll> dijkstra(Graph &G, int s) {
    vector<ll> dist(N, LLONG_MAX);
    dist[s] = 0;

    // (d[v], v) のペアを要素としたヒープを作る
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    que.push(make_pair(dist[s], s));

    while (!que.empty()) {
        ll d = que.top().first;
        int v = que.top().second;
        que.pop();

        // d > dist[v] => (d, v) はゴミ
        if (d > dist[v]) continue;

        // v を始点とした各エッジの緩和
        for (auto e : G[v]) {
            if (chminBool(dist[e.to], dist[v] + e.w)) que.push(make_pair(dist[e.to], e.to));
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        G[a].push_back(Edge(b, c));
        G[b].push_back(Edge(a, c));
    }

    vector<ll> dist1 = dijkstra(G, 0);
    vector<ll> distN = dijkstra(G, N - 1);

    rep(i, N) {
        ll ans = dist1[i] + distN[i];
        cout << ans << endl;
    }

    return 0;
}