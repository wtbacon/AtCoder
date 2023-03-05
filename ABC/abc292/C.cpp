#include <climits>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <bits/stdc++.h>

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

int numDivisor(int n) {
    /**
     * input： 整数 n
     * output：nの約数の個数
     * 計算量：O(√n)
     */
    int ans = 1;

    vector<int> x(n + 1);
    int num = n; // 素因数分解する変数num

    for (int i = 2; i <= n; i++) {
        while (num % i == 0) { // 素数で割り切れなくなるまで割っていく
            x.at(i)++;  //割った個数を配列に足す
            num /= i;
        }
    }

    for (int i = 2; i <= n; i++) {
        ans *= x.at(i) + 1; //それぞれを+1して掛けていく
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    ll ans = 0;
    for (int X = 1; X < N; X++) {
        ll cntX = 0;
        for (int A = 1; A * A <= X; A++) {
            if (X % A == 0) { // B = X/A
                cntX++;
                if (A * A != X) cntX++;
            }
        }

        int Y = N - X;
        ll cntY = 0;
        for (int C = 1; C * C <= Y; C++) {
            if (Y % C == 0) { // D = Y/C
                cntY++;
                if (C * C != Y) cntY++;
            }
        }
        ans += cntX * cntY;
    }


    cout << ans << endl;
    return 0;
}