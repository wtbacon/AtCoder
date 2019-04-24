#include <iostream>

using namespace std;

int main() {

    long a, b, x;
    cin >> a >> b >> x;


    long fa;

    /**
     * f(n) := 0 以上 n 以下の整数のうち条件を満たすものの個数.
     * a = 0 の時に f(-1) が呼ばれることに注意.
     */

    // 0 は割り切れる非負の整数であるから a = 0 の時を考慮する.
    if ( a == 0) fa = 0;
    else fa = (a - 1) / x + 1;

    long fb = b / x + 1;

    cout << fb - fa << endl;
}