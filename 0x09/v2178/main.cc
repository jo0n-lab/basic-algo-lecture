#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string board[102];
int vis[102][102];
int dist[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void print_board(int N, int M) {
  cout << "\n";
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << board[i][j] << " ";
    }
    cout << "\n";
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int N, M;
  cin >> N >> M;

  fill_n(&dist[0][0], 102 * 102, -1);

  for (int i = 0; i < N; i++)
    cin >> board[i];

  // print_board(N,M);

  pair<int, int> cur;
  queue<pair<int, int>> Q;
  Q.push({0, 0});
  vis[0][0] = 1;
  dist[0][0] = 1;

  while (!Q.empty()) {
    cur = Q.front();
    Q.pop();
    if (cur.X == N - 1 && cur.Y == M - 1)
      break;
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
        continue;
      }
      if (board[nx][ny] != '1' || vis[nx][ny]) {
        continue;
      }
      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
      Q.push({nx, ny});
      vis[nx][ny] = 1;
    }
  }
  cout << dist[N - 1][M - 1];
}
