#include <iostream>
#include <string>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    string canvas[50];
    for (int i = 0; i < H; i++) cin >> canvas[i];

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};

    bool can = true;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (canvas[i][j] == '.') continue;

            bool flag = false;
            if (canvas[i][j] == '#') {
                for (int t = 0; t < 4; t++) {
                    int ti = i + dy[t];
                    int tj = j + dx[t];
                    if (ti < 0 | ti >= H) continue;
                    if (tj < 0 | tj >= W) continue;

                    if (canvas[ti][tj] == '#') flag = true;
                }
                if (!flag) can = false;
            }
            if (!can) break;
        }
        if (!can) break;
    }

    if (can) cout << "Yes" << endl;
    else cout << "No" << endl;
}
