#include <bits/stdc++.h>
using namespace std;

// #define __DEBUG__
// #define __INPUT__
// #define __PRINT__

int N, M;
int num1[1000002];
int num2[1000002];

void print_config(string s) {
    cout.width(20);
    cout.fill('-');
    cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> num1[i];
    for (int i = 0; i < M; i++)
        cin >> num2[i];

#ifdef __INPUT__
    print_config("INPUT");
    for (int i = 0; i < N; i++)
        cout << num1[i] << " ";
    cout << "\n";
    for (int i = 0; i < M; i++)
        cout << num2[i] << " ";
    cout << "\n";
#endif

    sort(num1, num1 + N);
    sort(num2, num2 + M);

    int apos = 0;
    int bpos = 0;

    while (apos < N && bpos < M) {
        if (num1[apos] <= num2[bpos]) {
            cout << num1[apos] << " ";
            apos++;
        } else {
            cout << num2[bpos] << " ";
            bpos++;
        }
    }
    for (int i = apos; i < N; i++)
        cout << num1[i] << " ";
    for (int i = bpos; i < M; i++)
        cout << num2[i] << " ";
}
