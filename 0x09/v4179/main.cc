#include <bits/stdc++.h>
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int board[1002][1002];
int dist_p[1002][1002];
int dist_f[1002][1002];

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int R, C;
  cin >> R >> C;
  queue<pair<int, int>> Q_p;
  queue<pair<int, int>> Q_f;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      char input;
      cin >> input;
      board[i][j] = input;
      if (input == '.') {
        dist_p[i][j] = -1;
        dist_f[i][j] = -1;
      } else if (input == 'J') {
        Q_p.push({i, j});
      } else if (input == 'F') {
        Q_f.push({i, j});
      } else
        continue;
    }
  }

  while (!Q_f.empty()) {
    pair<int, int> cur = Q_f.front();
    Q_f.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if (nx < 0 || nx >= R || ny < 0 || ny >= C)
        continue;
      if (dist_f[nx][ny] >= 0)
        continue;

      dist_f[nx][ny] = dist_f[cur.X][cur.Y] + 1;

      Q_f.push({nx, ny});
    }
  }

  while (!Q_p.empty()) {
    pair<int, int> cur = Q_p.front();
    Q_p.pop();

    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
        cout << dist_p[cur.X][cur.Y] + 1;
        return 0;
      }
      if (dist_p[nx][ny] >= 0)
        continue;

      dist_p[nx][ny] = dist_p[cur.X][cur.Y] + 1;
      if (dist_p[nx][ny] >= dist_f[nx][ny] && dist_f[nx][ny]!=-1) 
        continue;
		  // !!둘다 방문 안한경우,,, -1 인 경우,,,

      Q_p.push({nx, ny});
    }
  }

  cout << "IMPOSSIBLE";
}
