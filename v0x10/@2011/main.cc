#include <bits/stdc++.h>
using namespace std;

// #define __DEBUG__
// #define __INPUT__
// #define __PRINT__

string alpha = "abcdefghijklmnopqrstuvwxyz";
int alpha_len = 26;
int n;
int arr[5002];
int cache[5002];
int mod = 1000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    n = s.length();

    for (int i = 1; i <= n; i++)
        arr[i] = int(s[i - 1]) - int('0');

#ifdef __INPUT__
    cout << "INPUT\n";
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << "\n";
#endif



}
