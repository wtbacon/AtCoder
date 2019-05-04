#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int gcd(int x, int y)
{
    int r;

    do {
        r = x % y;
        x = y;
        y = r;
    } while (r != 0);

    return x;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    int A[N];

    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> g(N + 1, 0);

    int mc = 0;
    for (int i = 0; i < N; i++) {
        g[i + 1] = gcd(g[i], A[i]);
    }

    cout << mc << endl;
}

