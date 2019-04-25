#include <iostream>

using namespace std;

int main() {

    int N;
    cin >> N;

    int b[N];
    for (int i = 0; i < N; i++) cin >> b[i];

    /**
     * N 回押してもボタン 2 が光らなければ, 2 を通らずにループしているので, -1 を出力する.
     */
    int now = 0;
    int count = 0;
    bool can = false;
    for ( int i = 0;i<N;i++) {
        count += 1;
        if (b[now] == 2){
            can = true;
            break;
        }
        else now = b[now] -1;
    }

    if (can) cout << count << endl;
    else cout << -1 << endl;
}