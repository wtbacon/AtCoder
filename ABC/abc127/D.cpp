#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    vector<int> B(M);
    vector<int> C(M);

    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < M; ++i) cin >> B[i] >> C[i];

    sort(A.begin(), A.end());

    for (int i = 0; i < M; ++i) {
        for (int n = 0; n < B[i]; ++n) {
            if (A[n] < C[i]) A[n] = C[i];
            else if (C[i] <= A[n]) break;
        }
        sort(A.begin(), A.end());
    }

    long long total = 0;
    for (int i = 0; i < N; ++i) total += A[i];
    cout << total << endl;

    return 0;
}

