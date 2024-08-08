#include <bits/stdc++.h>
using namespace std;

// #define __INPUT__
// #define __PRINT__
// #define __DEBUG__

int T, n;
int stk[2][100002];
int cache[2][100002][2];
int dir[2] = {1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> stk[i][j];
            }
        }

        cache[0][0][1] = stk[0][0];
        cache[1][0][1] = stk[1][0];

        for (int j = 1; j < n; j++) {
            for (int i = 0; i < 2; i++) {
                int dr = dir[i];
                cache[i][j][0] =
                    max({cache[i][j - 1][0], cache[i][j - 1][1],
                         cache[i + dr][j - 1][0], cache[i + dr][j - 1][1]});
                cache[i][j][1] =
                    max({cache[i][j - 1][0], cache[i + dr][j - 1][0],
                         cache[i + dr][j - 1][1]}) +
                    stk[i][j];
            }
        }
#ifdef __DEBUG__
        cout << "DEBUG\n";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cout << cache[i][j][0] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cout << cache[i][j][1] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
#endif

        cout << max(cache[1][n - 1][0], cache[1][n - 1][1]) << "\n";
    }
}
