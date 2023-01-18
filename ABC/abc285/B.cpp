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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    string S;

    cin >> N;
    cin >> S;

    for (int i = 1; i < N; i++) {
        int L = N-i;
        int ans = 0;
        for (int l = 1; l <= L; l++) {
            if (S[l-1] != S[l+i-1]) {
                ans++;
            } else break;
        }
        cout << ans << endl;
    }

    return 0;
}