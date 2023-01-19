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
using Graph = vector<vector<int> >;
//using Graph = vector<vector<Edge> >;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N, M; // N: Node数, M: Edge数
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v); // 有向グラフの場合これだけ
        G[v].push_back(u); // 無向グラフの場合追加
    }

    // 以下、bfsIsBipartiteGraph(const Graph &G, int s) を編集
    const int WHITE = 0;
    const int BLACK = 1;
    bool isBipartiteGraph = true;
    ll numNgEdges = 0;

    vector<int> color(N, -1);
    queue<int> queue;

    for (int s = 0; s < N; s++) {
        if (color[s] != -1) continue;

        ll numWhite = 0, numBlack = 0;

        queue.push(s);
        color[s] = WHITE;

        while (!queue.empty()) {
            int v = queue.front();
            queue.pop();

            if (color[v] == WHITE) numWhite++;
            else numBlack++;

            for (int next_v : G[v]) {
                if (color[next_v] != -1) {
                    if (color[next_v] == color[v]) isBipartiteGraph = false;
                } else {
                    color[next_v] = 1 - color[v];
                    queue.push(next_v);
                }
            }
        }
        // 同じ連結成分内の、同じ色のNode間のEdgeの数(結んでいけないEdgeの数): N*(N-1)/2
        numNgEdges += numWhite*(numWhite-1)/2 + numBlack*(numBlack-1)/2;
    }

    if (isBipartiteGraph) {
        // 結べるNode間のEdgeの数 = 全Nodeの結べるEdgeの数 - すでに結んであるEdgeの数 - 結んではいけないEdgeの数
        cout << N*(N-1)/2 - M - numNgEdges << endl;
    } else {
        cout << 0 << endl;
    }
}