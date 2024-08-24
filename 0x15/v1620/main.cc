#include <bits/stdc++.h>
using namespace std;

int N, M;
unordered_map<string, int> name2num;
string num2name[100'002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> num2name[i];
        name2num[num2name[i]] = i;
    }

    for (int i = 1; i <= M; i++) {
        string input;
        cin >> input;
        int is_digit = int(input[0]) - int('0');
        if (is_digit >= 0 && is_digit <= 9) {
            int num = 0;
            for (int j = 0; j < input.length(); j++) {
                num *= 10;
                num += int(input[j]) - int('0');
            }
            cout << num2name[num];
        } else
            cout << name2num[input];
        cout << "\n";
    }
}
