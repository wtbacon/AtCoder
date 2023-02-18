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

// change maximum
template<class T>
void chmax(T &a, T b) {
    if (a < b) a = b;
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


void readGraph() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M; // N: Node数, M: Edge数
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--; //  AtCoder の問題は 1 始まりであることに注意
        G[a].push_back(b); // 有向グラフの場合これだけ
        // G[b].push_back(a); // 無向グラフの場合追加

        /*
        重み付きグラフ
        int a, b;
        ll w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b, w)); // 有向グラフ
        */
    }

    cout << N << endl;
}


vector<bool> seen; // 全要素 false で初期化されるので探索のみなら使える
void dfsGraphWithRecursion(const Graph &G, int v) {
    /**
     * Node v を始点とした探索を行う。
     * 全 Node を探索する場合、全 Node を始点としてこの関数を callする必要がある。
     * Stack
     * G = (V, E) を全探索する
     */
    seen[v] = true;

    for (auto next_v : G[v]) {
        if (seen[next_v]) continue;
        dfsGraphWithRecursion(G, next_v);
    }
}

void dfsGraphWithStack(const Graph &G, int s) { // bfsGraphWithQueue(): Stack => Queue
    /**
     * Node v を始点とした探索を行う。
     * 全 Node を探索する場合、全 Node を始点としてこの関数を callする必要がある。
     * G: Graph
     * s: 始点となる Node
     */
    int N = (int) G.size();

    vector<bool> seen(N, false);
    stack<int> todo;
    // vector<int> degrees(N, 0); // 各ノードの次数のカウント

    seen[s] = true;
    todo.push(s);

    while (!todo.empty()) {
        // int numDegree = 0; // 各ノードの次数のカウント
        int v = todo.top();
        todo.pop();

        for (int x : G[v]) {
            // numDegree++; // 辿ってきたノードもカウントする
            if (seen[x]) continue;
            seen[x] = true;
            todo.push(x);
        }
    }
}

vector<int> dfsGraphForSSSP(const Graph &G, int s) { // bfsGraphWithStack(): Stack => Queue
    /**
     * Node s を始点とした　他Node との距離を探索する。
     * SSSP: Single Source Shortest Path
     * G: Graph
     * s: 始点となる Node
     */
    int N = (int) G.size();
    vector<int> distance(N, -1); // 未訪問を-1とする

    stack<int> queue;
    distance[s] = 0; // Node s を始点とする
    queue.push(s);

    while (!queue.empty()) {
        int v = queue.top();
        queue.pop();

        for (int x : G[v]) {
            if (distance[x] != -1) continue;
            distance[x] = distance[v] + 1;
            queue.push(x);
        }
    }
    return distance;
}

bool bfsIsBipartiteGraph(const Graph &G, int s) {
    /**
     * 全 Node を探索する場合、全 Node を始点としてこの関数を callする必要がある。
     * color: -1(未訪問), 0(白色), 1(黒色)
     */
    int N = (int) G.size();

    const int WHITE = 0;
    const int BLACK = 1;

    vector<int> color(N, -1);
    queue<int> queue;

    queue.push(s);
    color[s] = WHITE;

    while (!queue.empty()) {
        int v = queue.front();
        queue.pop();

        for (int next_v : G[v]) {
            if (color[next_v] != -1) {
                if (color[next_v] == color[v]) return false;
            }
            color[next_v] = 1 - color[v];
            queue.push(next_v);
        }
    }
    return true;
}

bool bfsIsDAG() { // dfsIsDAGWithStack(): Queue => Stack
    /**
     * DAG判定。有向サイクルを持たなければDAG。
     * Node が string ならば、以下を map にする必要がある。queue, order の要素は string になる。
     * Graph: map<string, vector<string> >
     * OutDegrees: map<string, int>
     */

    int N, M; // N: node数, M: edge数
    cin >> N >> M;

    Graph G(N);
    vector<int> outDegrees(N, 0);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[b].push_back(a);
        outDegrees[a]++;
    }

    queue<int> queue;
    vector<int> order;
    for (int v = 0; v < N; v++) {
        if (outDegrees[v] == 0) {
            queue.push(v);
        }
    }

    while (!queue.empty()) {
        int v = queue.front();
        queue.pop();
        order.push_back(v);

        for (int s : G[v]) {
            outDegrees[s]--;
            if (outDegrees[s] == 0) {
                queue.push(s);
            }
        }
    }

    if (order.size() == N) {
        return false;
    } else {
        return true;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    cout << N << endl;
    return 0;
}