#include <iostream>

using namespace std;

int main() {
    int N;
    int d[100];
    int e[101] = {};
    int counter = 0;

    cin >> N;

    for (int i = 0; i < N; i++) cin >> d[i];

    for (int i = 0; i < N; i++) {
        e[d[i]] += 1;
    }

    for (int i = 0; i <= 100; i++) {
        if (e[i] > 0) counter++;
    }

    cout << counter << endl;
}


/***
 * std::set を用いた解
 * #include <iostream>
 * #include <set>
 * using namespace std;
 *
 * int main() {
 *  int N;
 *  int d[110];
 *  cin >> N;
 *  for (int i = 0; i < N; ++i) cin >> d[i];
 *
 *  set<int> values;
 *  for (int i = 0; i < N; ++i) {
 *      values.insert(d[i]);
 *  }
 *
 *   cout << values.size() << endl;
 * }
 */
