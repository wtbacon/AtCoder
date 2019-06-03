#include <iostream>
#include <vector>
#include <numeric>


using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<vector<int>> A(N, vector<int>(3));
    vector<vector<int>> G(N, vector<int>(N));
    vector<int> R(N);

    for (int i = 0; i < N; ++i) cin >> A[i][0] >> A[i][1] >> A[i][2];

    for (int i = 0; i < N; ++i) {
        G[A[i][0]][A[i][1]] = A[i][2];
    }

    for (int i = 0; i < N; ++i) {
        for (int n = 0; n < i; ++n) {
            if N()

        }
    }

    cout << N << endl;

    return 0;
}

