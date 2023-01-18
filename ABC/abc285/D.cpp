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

struct Edge {
  int to; // 隣接Node番号
  ll w;

  Edge(int to, ll w) : to(to), w(w) {
  }
};

// 隣接リスト表現のグラフ
using Graph = map<string, vector<string> >;
//using Graph = vector<vector<Edge> >;

int main() {
    int N;
    cin >> N;

    Graph G;
    map<string, int> outDegrees;
    for (int i = 0; i < N; i++) {
        string a, b;
        cin >> a >> b;
        G[b].push_back(a);
        outDegrees[a] = outDegrees[a] + 1;
    }

    queue<string> queue;
    vector<string> order;
    for (auto &v : G) {
        if (outDegrees[v.first] == 0) {
            queue.push(v.first);
        }
    }

    while (!queue.empty()) {
        string v = queue.front();
        queue.pop();
        order.push_back(v);

        for (const auto& s : G[v]) {
            outDegrees[s]--;
            if (outDegrees[s] == 0) {
                queue.push(s);
            }
        }
    }

    if (order.size() == G.size()) {
        cout << "Yes" << endl; // サイクルを持っていないので更新可
    } else {
        cout << "No" << endl; // サイクルを持っているので更新不可
    }

    return 0;
}