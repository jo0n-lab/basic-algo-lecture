#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int board[202][202];
int dx[12] = {1, 0, -1, 0, 1, 2, 1, 2, -1, -2, -2, -1};
int dy[12] = {0, 1, 0, -1, 2, 1, -2, -1, -2, -1, 1, 2};
int dk[12] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1};
int dist[31][202][202];

int test_board[5][5];
void print_board() {
  cout << "\n";
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cout << test_board[i][j];
    }
    cout << "\n";
  }
}

void horse_test() {
  pair<int, int> p = {2, 2};
  for (int dir = 0; dir < 12; dir++) {
    int nx = p.X + dx[dir];
    int ny = p.Y + dy[dir];
    test_board[nx][ny] = 1;
    print_board();
  }
}

int main() {
  fill_n(&dist[0][0][0], 31 * 202 * 202, -1);

  int K, W, H;
  cin >> K >> W >> H;


  for (int i = 0; i < 31; i++) {
    dist[i][0][0] = 0;
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> board[i][j];
    }
  }

  if(W==1 && H==1){
	  if(board[0][0])
		  cout<<-1;
	  else
		  cout<<0;
	  return 0;
  }

  queue<tuple<int, int, int>> Q;
  Q.push({0, 0, 0});

  // horse_test();

  while (!Q.empty()) {
    tuple<int, int, int> cur = Q.front();
    Q.pop();
    int curK, curX, curY;
    tie(curK, curX, curY) = cur;

    for (int dir = 0; dir < 12; dir++) {
      int nx = curX + dx[dir];
      int ny = curY + dy[dir];
      int nk = curK + dk[dir];

      if (nx < 0 || nx >= H || ny < 0 || ny >= W || nk > K)
        continue;
      if (dist[nk][nx][ny] >= 0 || board[nx][ny])
        continue;
      if (nx == H - 1 && ny == W - 1) {
        cout << dist[curK][curX][curY] + 1;
        return 0;
      }

      dist[nk][nx][ny] = dist[curK][curX][curY] + 1;
      Q.push({nk, nx, ny});
    }
  }
  cout << -1;
}
