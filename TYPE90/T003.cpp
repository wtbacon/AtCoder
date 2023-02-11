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

#define rep(n) for (int i = 0; i < (n); ++i)

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
    int left, right;

    while (right - left > 1) {  // P(left)=false, P(right)=true より
        int mid = (right - left) / 2;
        if (P(mid)) right = mid;
        else left = mid;
    }
    return right;
}

using Graph = vector<vector<int> >;

int N;

vector<int> dfs(Graph &G, int s) {
    vector<int> dist = vector<int>(N, -1);
    stack<int> todo;

    todo.push(s);
    dist[s] = 0;
    while (!todo.empty()) {
        int v = todo.top();
        todo.pop();
        for (int next_v : G[v]) {
            if (dist[next_v] == -1) {
                dist[next_v] = dist[v] + 1;
                todo.push(next_v);
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    Graph G = Graph(N);
    rep(N - 1) {
        int A, B;
        cin >> A >> B;
        A--, B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    vector<int> dist = dfs(G, 0);
    int start = max_element(dist.begin(), dist.end()) - dist.begin();

    dist = dfs(G, start);

    cout << *max_element(dist.begin(), dist.end()) + 1 << endl;
    return 0;
}