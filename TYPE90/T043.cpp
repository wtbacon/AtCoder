#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <bits/stdc++.h>
#include <atcoder/all>

#define rep(i, n) for (int (i) = 0; (i) < (n); ++(i))

using namespace std;
using namespace atcoder;

typedef long long ll;
const long long INF = LLONG_MAX; // 2^64 > 1.8 * 10^19
const int MOD = pow(10, 9) + 7;
const double pi = 3.14159265358979;

// change minimum
template<class T>
void chmin(T &a, T b) {
    if (a > b) {
        a = b;
    }
}

template<class T>
bool chminBool(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    } else return false;
}

// change maximum
template<class T>
void chmax(T &a, T b) {
    if (a < b) a = b;
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

struct state {
  int x, y, dir;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W, sx, sy, gx, gy;
    cin >> H >> W >> sy >> sx >> gy >> gx;
    sx--, sy--, gx--, gy--;

    vector<string> S(H);
    rep (i, H) cin >> S[i];

    // dist: 各マスに対して4種類の「最短経路」を記録する
    // dist[i][j][0]: (i, j) で上を向く状態になるまでを含めたコスト
    // dist[i][j][1]: (i, j) で右を向く状態になるまでを含めたコスト
    // dist[i][j][2]: (i, j) で下を向く状態になるまでを含めたコスト
    // dist[i][j][3]: (i, j) で左を向く状態になるまでを含めたコスト
    vector<vector<vector<int>>> dist(H, vector<vector<int>>(W, vector<int>(4)));
    int inf = pow(10,6);
    rep (i, H) {
        rep(j, W) {
            dist[i][j][0] = inf;
            dist[i][j][1] = inf;
            dist[i][j][2] = inf;
            dist[i][j][3] = inf;
        }
    }

    deque<state> deq;

    rep(i, 4) {
        dist[sy][sx][i] = 0;
        deq.push_back({sx, sy, i});
    }

    const vector<int> dx = {1, 0, -1, 0};
    const vector<int> dy = {0, -1, 0, 1};
    while (!deq.empty()) {
        state s = deq.front();
        deq.pop_front();
        rep(i, 4) {
            int nx = s.x + dx[i];
            int ny = s.y + dy[i];
            // ステップ1: 現在向いている方向に1マス進む(コスト0)
            // ステップ2: 向いている方向を変える(コスト1)
            int cost = dist[s.y][s.x][s.dir] + (s.dir != i ? 1 : 0); // 前状態の向きを考慮した次のマスのコスト
            if (0 <= nx && nx < W && 0 <= ny && ny < H && S[ny][nx] == '.' && dist[ny][nx][i] > cost) { // 行き止まりでなく、より小さいコストで更新できるか
                dist[ny][nx][i] = cost;
                if (s.dir != i) deq.push_back({nx, ny, i});
                else deq.push_front({nx, ny, i}); // 方向転換がいらないマスを優先的に探索する
                // deq.push_back({nx, ny, i}); // 上記の処理は特に必要ない
            }
        }
    }

    int ans = INT_MAX;
    rep(i, 4) ans = min(ans, dist[gy][gx][i]);

    cout << ans << endl;
    return 0;
}