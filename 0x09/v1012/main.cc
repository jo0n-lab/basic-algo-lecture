#include <bits/stdc++.h>

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[52][52];
int vis[52][52];

using namespace std;

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
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T, M, N, K;
  cin >> T;

  for (int t = 0; t < T; t++) {
    int ans = 0;
    cin >> M >> N >> K;

    fill_n(&vis[0][0], 52 * 52, 0);
    fill_n(&board[0][0], 52 * 52, 0);

    for (int i = 0; i < K; i++) {
      int x, y;
      cin >> y >> x;
      board[x][y] = 1;
    }
	//print_board(N,M);

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (!board[i][j] || vis[i][j])
          continue;
        queue<pair<int, int>> Q;
        Q.push({i, j});
        vis[i][j] = 1;

        while (!Q.empty()) {

          pair<int, int> cur = Q.front();
          Q.pop();

          for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
              continue;
            if (vis[nx][ny] || !board[nx][ny])
              continue;

            vis[nx][ny] = 1;
            Q.push({nx, ny});
          }
        }
 //       print_board(N, M);
        ans++;
      }
    }
    cout << ans << "\n";
  }
}
