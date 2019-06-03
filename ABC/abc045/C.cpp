#include <iostream>
#include <string>

using namespace std;

int main() {

    string S;
    cin >> S;

    int n = S.size();

    long long res = 0;

    /**
     * 考えられる数式は, 2 ^ (N-1) 通りある.
     */
    for (int mask = 0; mask < (1 << (n - 1)); mask++) {

        int idx = 0;
        int rng = 1;

        /**
         * bit 列を数式に変換するために, 各 bit に対して走査する.
         */
        for (int i = 0; i < n - 1; i++) {
            if (mask & (1 << i)) {
                res += stoll(S.substr(idx, rng));
                idx = i+1;
                rng = 1;
            }
            else rng += 1;
        }
        res += stoll(S.substr(idx, rng));
    }
    cout << res << endl;
}