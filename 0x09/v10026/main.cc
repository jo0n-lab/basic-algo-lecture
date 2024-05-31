#include <bits/stdc++.h>

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char board[102][102];
int vis[102][102];

int N;

using namespace std;

void print_vis() {
  cout << "\n";
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << vis[i][j] << " ";
    }
    cout << "\n";
  }
}

void bfs(int i, int j, char c) {

  queue<pair<int, int>> Q;
  Q.push({i, j});

  vis[i][j] = 1;

  while (!Q.empty()) {
    pair<int, int> cur = Q.front();
    Q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if (vis[nx][ny] || board[nx][ny] != c)
        continue;
      if (nx < 0 || nx >= N || ny < 0 || ny >= N)
        continue;

      vis[nx][ny] = 1;
      Q.push({nx, ny});
    }
  }
}

int area(char c) {
  fill_n(&vis[0][0], 102 * 102, 0);
  int cnt = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] == c && !vis[i][j]) {
        bfs(i, j, c);
        cnt++;
        //		print_vis();
      }
    }
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  int ans1 = 0;
  int ans2 = 0;

  ans1 += area('B');
  ans2 = ans1;

  // cout<<ans1<<"\n";
  ans1 += area('R');
  // cout<<ans1<<"\n";
  ans1 += area('G');

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] == 'G')
        board[i][j] = 'R';
    }
  }
  ans2 += area('R');

  cout << ans1 << " " << ans2;
}
