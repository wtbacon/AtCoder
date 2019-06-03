#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>

using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> I(N);
    vector<string> S(N);
    vector<int> P(N);

    for (int i = 0; i < N; ++i) {
        cin >> S[i] >> P[i];
        I[i] = i + 1;
    }

    for (int n = 0; n < N - 1; ++n) {
        for (int i = 0; i < N - n - 1; ++i) {
            if (S[i] > S[i + 1]) {
                swap(S[i], S[i + 1]);
                swap(P[i], P[i + 1]);
                swap(I[i], I[i + 1]);
            } else if (S[i] == S[i + 1]) {
                if (P[i] < P[i + 1]) {
                    swap(S[i], S[i + 1]);
                    swap(P[i], P[i + 1]);
                    swap(I[i], I[i + 1]);
                }
            }
        }
    }

    for (int i = 0; i < N; ++i) cout << I[i] << endl;
    return 0;
}