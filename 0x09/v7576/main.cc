#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int board[1002][1002];
int dist[1002][1002];

void print_board(int N, int M, bool flag) {
  cout << "\n";
  if (flag) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cout << board[i][j] << " ";
      }
      cout << "\n";
    }
  } else {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cout << dist[i][j] << " ";
      }
      cout << "\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int N, M;
  cin >> M >> N;

  queue<pair<int, int>> Q;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      if (board[i][j] == 0) {
        // dist의 개념을 잘 이해할 것.
        // dist<0 (==-1) 은 초기화 상태로서 미방문 노드
        dist[i][j] = -1;
      }
      // Q 에 초기값을 미리 넣어둔다.
      else if (board[i][j] == 1)
        Q.push({i, j});
    }
  }

  // print_board(N, M);

  while (!Q.empty()) {
    pair<int, int> cur = Q.front();
    Q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if (nx < 0 || nx >= N || ny < 0 || ny >= M)
        continue;
      if (dist[nx][ny] >= 0)
        continue;

      //미방문 노드라면 여기서 재초기화 됌.
      //기존값과 상관없이 덮어쓰기임.
      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
      Q.push({nx, ny});
    }
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {

      if (dist[i][j] == -1) {
        cout << -1;
        return 0;
      } else {
        ans = max(ans, dist[i][j]);
      }
    }
  }
 // print_board(N, M, false);
  cout << ans;
}

