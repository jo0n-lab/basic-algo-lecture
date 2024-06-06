#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int wallpaper[42][42];
queue<tuple<int, int, int[12][12]>> stickers;

void rotate_sticker() {
  int R, C;
  int prev_sticker[12][12];
  int next_sticker[12][12];
  tie(R, C, sticker) = stickers.back();
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      next_sticker[C - 1 - j][R - 1 - i] = prev_sticker[i][j];
    }
  }
  stickers.pop();
  stickers.push{C, R, next_sticker};
}
void attach_sticker(int xpos, int ypos) {
  int R, C;
  int sticker[12][12];
  tie(R, C, sticker) = stickers.back();
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      wallpaper[xpos + i][ypos + j] = sticker[i][j];
    }
  }
}
bool BFS(int xpos, int ypos) {
  int R, C;
  int sticker[12][12];
  tie(R, C, sticker) = stickers.back();
  int vis[12][12];
  fill_n(&vis[0][0], 12 * 12, 0);
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (vis[i][j]) continue;
      queue<pair<int, int>> Q;
      Q.push({i, j});
      vis[i][j] = 1;
      while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if (nx < 0 || nx >= R || ny < 0 || ny >= C || nx + xpos >= N ||
              ny + ypos >= M)
            continue;
          if (vis[nx][ny] || !sticker[nx][ny]) continue;
          if (wallpaper[nx + xpos][ny + ypos]) return false;
          vis[nx][ny] = 1;
          Q.push({nx, ny});
        }
      }
    }
  }
  return true;
}
void vacancy() {}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M, K;
  cin >> N >> M >> K;
  for (int i = 0; i < K; i++) {
    int R, C;
    cin >> R >> C;
    int input_sticker[12][12];
    for (int j = 0; j < R; j++) {
      for (int k = 0; k < C; k++) {
        cin >> input_sticker[j][k];
      }
    }
    stickers.push({R, C, input_sticker});
  }
  int ans = 0;
  while (!stickers.empty()) {
    int sticker[12][12];
    int R, C;
    tie(R, C, sticker) = stickers.back();
    bool is_attached = false;
    for (int rot = 0; rot < 4; rot++) {
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          if (is_attached) continue;
          if (wallpaper[i][j]) continue;
          if (BFS(i, j)) {
            attach_sticker(i, j);
            is_attached = true;
          }
        }
      }
      rotate_sticker();
    }
    stickers.pop();
    if (is_attached) ans++;
  }
}
