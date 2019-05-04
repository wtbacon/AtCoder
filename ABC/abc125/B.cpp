#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> V(N);
    vector<int> C(N);

    for (int i = 0; i < N; i++) cin >> V[i];
    for (int i = 0; i < N; i++) cin >> C[i];

    int diff = 0;
    for (int i = 0; i < N; i++) {
        if (V[i] - C[i] > 0) diff += V[i] - C[i];
    }

    cout << diff << endl;

    return 0;
}