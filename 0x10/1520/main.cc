#include <bits/stdc++.h>
using namespace std;

#define __INPUT__
#define __PRINT__
#define __DEBUG__

#define X first
#define Y second

int M, N;
int board[502][502];
int cache[502][502];
int vis[502][502][4];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

stack<pair<int, int>> s;
int ans = 0;

void DFS(pair<int, int> cur) {
    if (cur.X == M - 1 && cur.Y == N - 1) {
        ans++;
        return;
    }
    if (cache[cur.X][cur.Y] == 0)
        return;
    for (int dir = 0; dir < 4; dir++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if (board[cur.X][cur.Y] <= board[nx][ny]) {
            if (vis[cur.X][cur.Y][dir] == 0) {
                cache[cur.X][cur.Y]--;
                vis[cur.X][cur.Y][dir] = 1;
            }
            continue;
        }
        if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
            if (vis[cur.X][cur.Y][dir] == 0) {
                cache[cur.X][cur.Y]--;
                vis[cur.X][cur.Y][dir] = 1;
            }
            continue;
        }
        DFS({nx, ny});
        if (cache[nx][ny] == 0) {
            if (vis[cur.X][cur.Y][dir] == 0) {
                cache[cur.X][cur.Y]--;
                vis[cur.X][cur.Y][dir] = 1;
            }
            continue;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

#ifdef __INPUT__
    cout << "INPUT\n";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout.width(3);
            cout.fill(' ');
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
#endif

    fill_n(&cache[0][0], 502 * 502, 4);
    DFS({0, 0});

#ifdef __DEBUG__
    cout << "DEBUG\n";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << cache[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
#endif

    cout << ans;
}
