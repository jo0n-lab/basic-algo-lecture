#include <bits/stdc++.h>
#define X first
#define Y second

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int board[102][102][102];
int dist[102][102][102];

using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int N, M, H;
  cin >> M >> N >> H;

  queue<tuple<int, int, int>> Q;

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < M; k++) {
        int input;
        cin >> input;
        board[i][j][k] = input;
        if (input == 0)
          dist[i][j][k] = -1;
        else if (input == 1)
          Q.push({i, j, k});
      }
    }
  }

  while (!Q.empty()) {
    //	tuple<int,int,int> cur=Q.front(); Q.pop();
    auto cur = Q.front();
    Q.pop();
    int curX, curY, curZ;
    tie(curZ, curX, curY) =
        cur; //중요!! 왼쪽에 변수를 tie로 묶고 오른쪽에 tuple
    for (int dir = 0; dir < 6; dir++) {
      int nx = curX + dx[dir];
      int ny = curY + dy[dir];
      int nz = curZ + dz[dir];

      if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H)
        continue;
      else if (dist[nz][nx][ny] >= 0)
        continue;
      // 물론 두가지 경우를 합칠 수 있으나,, 디버깅 힘들어진다.

      dist[nz][nx][ny] = dist[curZ][curX][curY] + 1;
      Q.push({nz, nx, ny});
    }
  }

  int ans = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < M; k++) {
        int tmp = dist[i][j][k];
        if (tmp == -1) {
          cout << -1;
          return 0;
        }
        ans = max(tmp, ans);
      }
    }
  }

  cout << ans;
}
