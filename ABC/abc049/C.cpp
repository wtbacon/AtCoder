#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string divide[4] = {"dream", "dreamer", "erase", "eraser"};

    string S;
    cin >> S;

    reverse(S.begin(), S.end());
    for (int i = 0; i < 4; i++) reverse(divide[i].begin(), divide[i].end());

    bool canFlag = true;
    for (int i = 0; i < S.size();) {
        bool divideFlag = false;
        for (int j = 0; j < 4; j++) {
            string target = divide[j];
            if (S.substr(i, target.size()) == target) {
                divideFlag = true;
                i += target.size();
            }
        }
        if (!divideFlag) {
            canFlag = false;
            break;
        }
    }
    if (canFlag) cout << "YES" << endl;
    else cout << "NO" << endl;
}