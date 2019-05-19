#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    string S;
    cin >> S;

    int top = stoi(S.substr(0, 2));
    int bottom = stoi(S.substr(2, 2));

    bool topFlag = false;
    bool bottomFlag = false;

    if (0 < top and top < 13) topFlag = true;
    if (0 < bottom and bottom < 13) bottomFlag = true;

    if (topFlag and bottomFlag) cout << "AMBIGUOUS" << endl;
    else if (topFlag and !bottomFlag)cout << "MMYY" << endl;
    else if (!topFlag and bottomFlag)cout << "YYMM" << endl;
    else cout << "NA" << endl;

    return 0;
}