#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(M, vector<int>(2));

    for (int i =0;i<M;++i)cin >> G[i][0] >> G[i][1];

    int start = 0;
    int end = 100001;
    for (int i = 0; i < M; ++i) {
        if (start <= G[i][0] and G[i][0]) start = G[i][0];
        if (G[i][1] <= end) end = G[i][1];
    }

    if (start <= end)cout << end - start +1<<endl;
    else cout << 0 <<endl;

    return 0;
}

