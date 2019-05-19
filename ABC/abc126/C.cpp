#include <iostream>
#include <vector>
#include <numeric>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    double N;
    double K;
    double integer;
    cin >> N >> K;

    double rate = 0.0;

    for (double i = 1; i <= N; i++) {
        if (i >= K) {
            rate = rate + (double) 1.0 / N;
            continue;
        }
        int bo = log2(K / i);
        if (modf(log2(K / i), &integer) > 0) bo += 1;
        rate =rate + (double) 1.0/N * pow((double) 0.5, (double)bo);
    }

    cout << fixed<< setprecision(12) << rate << endl;

    return 0;
}

