#include <bits/stdc++.h>
using namespace std;

// #define __DEBUG__
// #define __INPUT__
// #define __PRINT__

#define X first
#define Y second

int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {0, 0, 1, 0, -1};
int wallpaper[42][42];

int N;
int M;
int K;

struct sticker {
   int R;
   int C;
   int shape[12][12];
};

deque<sticker> stickers;

void print_wallpaper() {
   cout << "\n";
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
         cout << wallpaper[i][j] << " ";
      }
      cout << "\n";
   }
}

void print_sticker(bool front) {
   sticker target_sticker;
   if (front)
      target_sticker = stickers.front();
   else
      target_sticker = stickers.back();

   int R = target_sticker.R;
   int C = target_sticker.C;

   cout << "\nR " << R << " C " << C << "\n";
   for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
         cout << target_sticker.shape[i][j];
      }
      cout << "\n";
   }
}

void rotate_sticker() {
   sticker prev_sticker = stickers.front();
   sticker next_sticker;

   int R = prev_sticker.R;
   int C = prev_sticker.C;
   next_sticker.R = C;
   next_sticker.C = R;

   for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
         next_sticker.shape[j][R - 1 - i] = prev_sticker.shape[i][j];
      }
   }
   stickers.pop_front();
   stickers.push_front(next_sticker);
}

void attach_sticker(int xpos, int ypos) {
   sticker target_sticker = stickers.front();
   int R = target_sticker.R;
   int C = target_sticker.C;

   for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
         wallpaper[xpos + i][ypos + j] += target_sticker.shape[i][j];
      }
   }
#ifdef __DEBUG__
   print_wallpaper();
#endif
}

bool BFS(int xpos, int ypos) {
   sticker target_sticker = stickers.front();
   int R = target_sticker.R;
   int C = target_sticker.C;

   if (xpos + R > N || ypos + C > M) {
#ifdef __DEBUG__
      cout << "target sticker out of wallpaper";
      cout << " R: " << R << " C: " << C;
      cout << " xpos " << xpos << " ypos " << ypos << "\n";
#endif
      return false;
   }

   int vis[12][12];

   fill_n(&vis[0][0], 12 * 12, 0);

   for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
         if (vis[i][j]) continue;
         queue<pair<int, int>> Q;
         Q.push({i, j});

         while (!Q.empty()) {
            pair<int, int> cur = Q.front();
            Q.pop();
            for (int dir = 0; dir < 5; dir++) {
               int nx = cur.X + dx[dir];
               int ny = cur.Y + dy[dir];
               if (nx < 0 || nx >= R || ny < 0 || ny >= C || nx + xpos >= N ||
                   ny + ypos >= M)
                  continue;
               if (vis[nx][ny] || !target_sticker.shape[nx][ny]) continue;

               if (wallpaper[nx + xpos][ny + ypos]) {
#ifdef __DEBUG__
                  cout << "target sticker doesnt fit with current position";
                  cout << " xpos " << xpos << " ypos " << ypos << "\n";
#endif
                  return false;
               }

               vis[nx][ny] = 1;
               Q.push({nx, ny});
            }
         }
      }
   }
#ifdef __DEBUG__
   cout << "target sticker fits with current position";
   cout << " xpos " << xpos << " ypos " << ypos << "\n";
#endif
   return true;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> N >> M >> K;

#ifdef __INPUT__
   cout << "\ninput starts...\n";
#endif
   for (int k = 0; k < K; k++) {
      sticker input_sticker;
      int R, C;
      cin >> R >> C;
      input_sticker.R = R;
      input_sticker.C = C;

      for (int i = 0; i < R; i++) {
         for (int j = 0; j < C; j++) {
            cin >> input_sticker.shape[i][j];
         }
      }
      stickers.push_back(input_sticker);
#ifdef __INPUT__
      print_sticker(false);
#endif
   }
#ifdef __INPUT__
   cout << "\nend of input...\n";
#endif

   while (!stickers.empty()) {
      bool is_attached = false;
      for (int rot = 0; rot < 4; rot++) {
         for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
               if (is_attached) continue;
               if (BFS(i, j)) {
                  attach_sticker(i, j);
                  is_attached = true;
               }
            }
         }
         if (is_attached) break;
         rotate_sticker();
#ifdef __DEBUG__
         cout << "rot " << rot + 1 << "\n";
         print_sticker(true);
#endif
      }
      stickers.pop_front();

#ifdef __PRINT__
      print_wallpaper();
#endif
   }

   int ans = 0;
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
         ans += wallpaper[i][j];
      }
   }
   cout << ans;
}
