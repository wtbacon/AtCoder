#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <bits/stdc++.h>
#include <atcoder/all>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;
using namespace atcoder;

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

template<class T>
bool chminBool(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    } else return false;
}

struct Edge {
  int to; // 隣接Node番号
  ll w;

  Edge(int to, ll w) : to(to), w(w) {
  }
};


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
        G[a].push_back(b);
        // G[b].push_back(a);

        /*
        重み付きグラフ
        int a, b;
        ll w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b, w));
        */
    }

    cout << N << endl;
}


vector<bool> seen; // 全要素 false で初期化されるので探索のみなら使える
// vector<int> degrees(N, 0); // ❶各ノードの次数のカウント
void dfsGraphWithRecursion(const Graph &G, int v) {
    /**
     * Node v を始点とした探索を行う。
     * 全 Node を探索する場合、全 Node を始点としてこの関数を callする必要がある。
     * Stack
     * G = (V, E) を全探索する
     */
    seen[v] = true;
    // int numDegree = 0; // ❶ノードの次数のカウント

    for (auto next_v : G[v]) {
        // numDegree++; // ❶辿ってきたノードもカウントする
        if (seen[next_v]) continue;
        dfsGraphWithRecursion(G, next_v);
    }
    // degrees[v] = numDegree; // ❶次数の更新
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
    // vector<int> degrees(N, 0); // ❶各ノードの次数のカウント
    // int connected = 0;   // ❷連結成分のカウント

    seen[s] = true;
    todo.push(s);

    while (!todo.empty()) {
        // int numDegree = 0; // ❶ノードの次数のカウント
        int v = todo.top();
        todo.pop();

        for (int x : G[v]) {
            // numDegree++; // ❶辿ってきたノードもカウントする
            if (seen[x]) continue;
            seen[x] = true;
            todo.push(x);
        }
        // degrees[v] = numDegree; // ❶次数の更新
    }
}

int findConnectedComponentByDfs(const Graph &G) { // bfsGraphWithQueue(): Stack => Queue
    /**
     * Graph の連結成分(connected Component) の数を求める
     * G: Graph
     */
    int N = (int) G.size();

    vector<bool> seen(N, false);
    int cnt = 0;

    rep (i, N) {
        if (!seen[i]) {
            seen[i] = true;
            cnt++;
            stack<int> todo;
            todo.push(i);

            while (!todo.empty()) {
                int v = todo.top();
                todo.pop();

                for (int x : G[v]) {
                    if (seen[x]) continue;
                    seen[x] = true;
                    todo.push(x);
                }
            }
        }
    }
    return cnt;
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