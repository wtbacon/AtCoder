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
#include <initializer_list>
//#include <bits/stdc++.h>

#define rep(i, n) for (int (i) = 0; (i) < (n); ++(i))

using namespace std;

typedef long long ll;
const long long INF = LLONG_MAX;
const int MOD = pow(10, 9) + 7;

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

bool P(int i) {
    return i;
}

int binary_search() {
    int left = 0, right = 0;

    while (right - left > 1) {  // P(left)=false, P(right)=true より
        int mid = (right - left) / 2;
        if (P(mid)) right = mid;
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

const double pi = 3.14159265358979;

double getAngleFromB(Point p) {
    double ang = atan2(p.y, p.x) * 180.0 / pi;
    return ang < 0.0 ? 360.0 - abs(ang) : ang;
}

double getAngleByTwoPoints(double A, double C) {
    // 原点と見立てた B からの偏角が A, C であることに注意
    double diff = abs(A - C);
    return diff >= 180.0 ? 360.0 - diff : diff;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<Point> P(N);
    rep(i, N) {
        cin >> P[i].x >> P[i].y;
    }

    double ans = 0.0;
    rep(i, N) {
        Point B = P[i];

        vector<double> vec;
        rep (j, N) {
            Point p = P[j] - B;
            if (i != j) vec.push_back(getAngleFromB(p));
        }
        sort(vec.begin(), vec.end());

        double ABC = 0.0;
        rep (j, vec.size()) {
            double A = vec[j];
            double target = A + 180.0 < 360.0 ? A + 180.0 : A + 180.0 - 360.0;

            int pos = lower_bound(vec.begin(), vec.end(), target) - vec.begin();
            int candPos1 = pos % vec.size();
            int candPos2 = (pos - 1 + vec.size()) % vec.size();
            double cand1 = getAngleByTwoPoints(A, vec[candPos1]);
            double cand2 = getAngleByTwoPoints(A, vec[candPos2]);
            ABC = max(ABC, max(cand1, cand2));
        }

        ans = max(ans, ABC);
    }

    printf("%.12lf\n", ans);
    return 0;
}