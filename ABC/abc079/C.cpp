#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    string input;
    cin >> input;

    int a[4];
    for (int i = 0; i < 4; i++) a[i] = input[i] - '0';

    /**
     * '+' と '-' の組み合わせは 8通りある.
     * '-' のとき「0」, '+' のとき「1」として, 組み合わせを2進数で表すと,
     * '-' '-' '-' は 「000」
     * '-' '-' '+' は 「001」
     * ・・・
     * '+' '+' '+' は 「111」
     * となる. それぞれ数値で示すと 0 ~ 7 となり, 下記で 「x」とおいて全探索する.
     */
    for (int x = 0; x < 8; x++) {
        int sum = a[0];
        string res;
        res += (char) ('0' + a[0]);
        for (int i = 0; i < 3; i++) {
            /**
             * 001 & 001 => 001 （ and 演算子）
             * 1 << 1 => 010 （ 1 を 2 bit 左へシフト）
             * であるから, i 番目が
             * 1 => sum + a[i+1]
             * 0 => sum - a[i+1]
             */
            if (x & (1 << i)) {
                sum += a[i + 1];
                res += '+';
                res += (char) ('0' + a[i + 1]);
            } else {
                sum -= a[i + 1];
                res += '-';
                res += (char) ('0' + a[i + 1]);
            }
        }
        if (sum == 7) {
            cout << res + "=7" << endl;
            cout << (char) ('0' + a[0]) << endl;
            return 0;
        }
    }
    return 0;
}



