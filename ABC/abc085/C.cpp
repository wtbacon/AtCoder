#include <iostream>

using namespace std;

int main() {
    int N, Y;

    cin >> N >> Y;

    int xRes = -1;
    int yRes = -1;
    int zRes = -1;

    for (int x = 0; x <= N; x++) {
        for (int y = 0; y <= N; y++) {
            int z = N - x - y;
            int total = 10000 * x + 5000 * y + 1000 * z;
            if (total == Y & z > 0) {
                xRes = x;
                yRes = y;
                zRes = z;
            }
        }
    }
    cout << xRes << " " << yRes << " " << zRes << endl;
}
