#include <iostream>
#include <string>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    string board[50];
    for (int i = 0; i < H; i++) cin >> board[i];

    int dx[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    int dy[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (board[i][j] == '#') continue;

            int num = 0;

            for (int d = 0; d < 9; d++) {
                int ti = i + dy[d];
                int tj = j + dx[d];

                if (ti < 0 or ti >= H) continue;
                if (tj < 0 or tj >= W) continue;
                if (board[ti][tj] == '#') num++;
            }

            board[i][j] = char(num + '0');

        }
    }

    for (int i = 0; i < H; i++) cout << board[i] << endl;
}
