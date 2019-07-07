#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;

string S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, A, B;

    cin >> N >> A >> B;

    if (B < A * N) cout << B << endl;
    else cout << A*N << endl;
    return 0;
}