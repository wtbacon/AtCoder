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

UnionFind uf;
vector<vector<bool>> used;
int H, W;

void query1(int px, int py) {
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    rep (i, 4) {
        int nx = px + dx[i], ny = py + dy[i];
        // 四方を探索しても塗られていなければ併合することはできないことに注意
        if (0 <= nx && nx < H && 0 <= ny && ny < W && used[nx][ny]) {
            int hash1 = px * W + py;
            int hash2 = nx * W + ny;
            uf.unite(hash1, hash2);
        }
    }
    used[px][py] = true;
}

bool query2(int px, int py, int qx, int qy) {
    if (!used[px][py] || !used[qx][qy]) return false;
    int hash1 = px * W + py;
    int hash2 = qx * W + qy;
    return uf.issame(hash1, hash2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> H >> W;
    used = vector<vector<bool>>(H, vector<bool>(W, false));

    int Q;
    cin >> Q;

    uf.init(H * W);

    rep(i, Q) {
        int t;
        cin >> t;

        if (t == 1) {
            int r, c;
            cin >> r >> c;
            r--, c--;
            query1(r, c);
        } else {
            int ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            ra--, ca--, rb--, cb--;
            if (query2(ra, ca, rb, cb)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}