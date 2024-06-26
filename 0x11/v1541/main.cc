#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int target = 0;
    string op = "";
    vector<int> num;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == '-' || c == '+') {
            num.push_back(target);
            op += c;
            target = 0;
        } else {
            target *= 10;
            target += int(c) - int('0');
        }
    }
    num.push_back(target);

    int sign = 1;
    int add = num[0];
    int sub = 0;

    for (int i = 0; i < op.size(); i++) {
        if (op[i] == '-')
            sign = -1;
        if (sign == 1)
            add += num[i + 1];
        else
            sub += num[i + 1];
    }

    cout << add - sub;
}
