#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    S[K-1] = S[K-1] + 0x20;

    cout << S << endl;

    return 0;
}