#include <bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

int N, M;
int board[2002];
int cache[2002][2002];

void print_config(string s) {
    cout.width(20);
    cout.fill('-');
    cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> board[i];

    for (int i = 1; i <= N; i++) {
        cache[i][i] = 1;
        if (board[i] == board[i - 1])
            cache[i - 1][i] = 1;
    }

    for (int gap = 2; gap <= N; gap++) {
        for (int i = 1; i <= N - gap; i++) {
            int j = i + gap;
            if (board[i] == board[j] && cache[i + 1][j - 1] == 1)
                cache[i][j] = 1;
        }
    }

    cin >> M;
    for (int T = 0; T < M; T++) {
        int i, j;
        cin >> i >> j;
        cout << cache[i][j] << "\n";
    }
}
