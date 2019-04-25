#include <iostream>

using namespace std;

int main() {

    int A, B, C;
    cin >> A >> B >> C;

    /**
     * k を任意の整数とした時、
     * (k + B)A % B = (kA + BA) % B = kA % B
     * より, B 以上の A の倍数は kA の時と同じ剰余となり, 周期的な値になることが分かる.
     * したがって, A から BA まで求めればよい.
     */
    bool can = false;
    for ( int i = 1;i<=B;i++) {
       if (A * i % B == C) can = true;
    }

    if (can) cout << "YES" << endl;
    else cout << "NO" << endl;
}