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


void permutation(int first, vector<int> &runners, vector<vector<int>> &pttns) {
    if (first == runners.size()) {
        vector<int> pttn = runners;
        pttns.push_back(pttn);
        return;
    }

    for (int i = first; i < runners.size(); i++) {
        swap(runners[first], runners[i]);
        permutation(first + 1, runners, pttns);
        swap(runners[first], runners[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<vector<int> > A(N, vector<int>(N));
    rep(i, N) rep(j, N) cin >> A[i][j];

    int M;
    cin >> M;

    vector<set<int> > rumor(N);
    rep(i, M) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        rumor[x].insert(y);
        rumor[y].insert(x);
    }

    vector<int> runners(N);
    rep(i, N) runners[i] = i;

    vector<vector<int> > pttns;
    permutation(0, runners, pttns);

    int ans = INT_MAX;
    for (int i = 0; i < pttns.size(); i++) {
        auto &p = pttns[i];
        bool isBad = false;
        int total = A[p[0]][0];
        for (int j = 1; j < p.size(); j++) {
            if (!rumor[p[j]].count(p[j - 1])) total += A[p[j]][j];
            else {
                isBad = true;
                break;
            }
        }
        if (isBad) continue;
        else ans = min(ans, total);
    }

    if (ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;

    return 0;

}
