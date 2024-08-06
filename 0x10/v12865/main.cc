#include <bits/stdc++.h>
using namespace std;

// #define __INPUT__
// #define __PRINT__
// #define __DEBUG__

int N, K;
int w[102];
int v[102];
int cache[102][100002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> w[i];
        cin >> v[i];
    }

    for (int i = 1; i <= N; i++) {
        int W = w[i];
        int V = v[i];
        for (int j = 1; j < W; j++)
            cache[i][j] = cache[i - 1][j];
        for (int j = W; j <= K; j++) {
            cache[i][j] = max(cache[i - 1][j], cache[i - 1][j - W] + V);
        }
    }

#ifdef __DEBUG__
    cout << "DEBUG\n";
    for (int i = 1; i <= N; i++) {
        cout << "value: " << v[i] << " | ";
        for (int j = 1; j <= K; j++) {
            cout.width(3);
            cout.fill(' ');
            cout << cache[i][j] << " ";
        }
        cout << "\n";
    }
#endif

    int ans = 0;
    for (int j = 1; j <= K; j++)
        ans = max(cache[N][j], ans);

    cout << ans;
}
