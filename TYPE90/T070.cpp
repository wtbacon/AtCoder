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
const int MOD = (int) pow(10, 9) + 7;
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

ll octalToDecimal(const string &num) {
    ll decimal = 0;
    rep(i, num.size()) {
        decimal = decimal * 8 + int(num[i] - '0');
    }
    return decimal;
}

string DecimalToNonary(ll num) {
    if (num == 0) return "0";

    string nonary;
    while (num > 0) {
        nonary = char(num % 9 + '0') + nonary;
        num /= 9;
    }
    return nonary;
}

double fastPow(double x, ll n) {
    if (n == 0) {
        return 1.0;
    }

    double half = fastPow(x, n / 2);
    if (n % 2 == 0) {
        return half * half;
    } else {
        return x * half * half;
    }
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


using Graph = vector<vector<int> >;
//using Graph = vector<vector<Edge> >;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    nth_element(X.begin(), X.begin() + N / 2, X.end());
    nth_element(Y.begin(), Y.begin() + N / 2, Y.end());

    ll x = 0, y = 0;
    rep(i, N) {
        x += abs(X[i] - X[N / 2]);
        y += abs(Y[i] - Y[N / 2]);
    }

    cout << x + y << endl;
    return 0;
}