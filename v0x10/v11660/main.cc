#include <bits/stdc++.h>
using namespace std;

// #define __DEBUG__
// #define __INPUT__

int N;
int M;
int board[1026][1026];
int cache[1026][1026];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    // TODO: fill cache!!
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cache[i][j] = cache[i][j - 1] + board[i][j];
        }
    }
    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= N; i++) {
            cache[i][j] += cache[i - 1][j];
        }
    }

#ifdef __INPUT__
    cout << "BOARD\n";
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
#endif

#ifdef __DEBUG__
    cout << "CACHE\n";
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout.width(4);
            cout.fill(' ');
            cout << cache[i][j];
        }
        cout << "\n";
    }
#endif

    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << cache[x2][y2] - cache[x1 - 1][y2] - cache[x2][y1 - 1] +
                    cache[x1 - 1][y1 - 1]
             << "\n";
    }
}
