#include <bits/stdc++.h>
using namespace std;

// #define __INPUT__
// #define __DEBUG__
// #define __PRINT__
// #define __DDEBUG__

#define X first
#define Y second
#define INF 2000000000

struct fish {
   int x;
   int y;
   int size;
   int dist;
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N;
int M;

int TIME = 1;
int board[22][22];
deque<fish> fishes;
fish shark;

int cur_exp = 0;
int level[7] = {0, 0, 2, 5, 9, 14, 20};

void print_config(string s) {
   cout.width(15);
   cout.fill('-');
   cout << s << "\n";
}

void print_board() {
   print_config(__FUNCTION__);
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         if (board[i][j] == 9) {
            cout << "@ ";
            continue;
         }
         cout << board[i][j] << " ";
      }
      cout << "\n";
   }
   // print_config("-");
}

void BFS(fish &target) {
   if (target.size >= shark.size) {
      target.dist = INF;
#ifdef __DDEBUG__
      cout << "target fish is bigger than shark, dist: " << target.dist << "\n";
#endif
      return;
   }

   int dist[22][22];
   fill_n(&dist[0][0], 22 * 22, -1);

   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         if (board[i][j] > shark.size) dist[i][j] = 0;
      }
   }
   dist[shark.x][shark.y] = 0;
   // avoid shark size bigger than 9

   queue<pair<int, int>> Q;
   Q.push({shark.x, shark.y});

   while (!Q.empty()) {
      pair<int, int> cur = Q.front();
      Q.pop();

      for (int dir = 0; dir < 4; dir++) {
         int nx = cur.X + dx[dir];
         int ny = cur.Y + dy[dir];

         if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
         if (dist[nx][ny] >= 0) continue;
         if (nx == target.x && ny == target.y) {
            target.dist = dist[cur.X][cur.Y] + 1;
#ifdef __DDEBUG__
            cout << "target fish dist as: " << target.dist << "\n";
#endif
            return;
         }

         dist[nx][ny] = dist[cur.X][cur.Y] + 1;
         Q.push({nx, ny});
      }
   }
   target.dist = INF;
#ifdef __DDEBUG__
   cout << "target fish can't be reached, dist:  " << target.dist << "\n";
#endif
}

// bool compare_size(fish a, fish b){
//	return a.size<b.size;
// }

bool compare(fish a, fish b) {
   if (a.dist == b.dist) {
      if (a.x == b.x) return a.y < b.y;
      return a.x < b.x;
   }
   return a.dist < b.dist;
}

bool compare_dist(fish a, fish b) { return a.dist < b.dist; }

bool compare_pos(fish a, fish b) {
   if (a.x == b.x) return a.y < b.y;
   return a.x < b.x;
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(NULL);

   cin >> N;
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         int input;
         cin >> input;
         if (input >= 1 && input <= 6) {
            fish input_fish;
            input_fish.x = i;
            input_fish.y = j;
            input_fish.dist = 0;
            input_fish.size = input;
            fishes.push_back(input_fish);

         } else if (input == 9) {
            shark.size = 2;
            shark.x = i;
            shark.y = j;
         }
         board[i][j] = input;
      }
   }

   int ans = 0;
   int rounds = fishes.size();

   for (int rounds = 1; rounds > 0; rounds++) {
      if (fishes.empty()) break;

      for (int i = 0; i < fishes.size(); i++) BFS(fishes[i]);
      sort(fishes.begin(), fishes.end(), compare);

#ifdef __DEBUG__
      print_config(to_string(rounds) + "round");
#endif

      fish target_fish = fishes.front();
      fishes.pop_front();

#ifdef __DEBUG__
      cout << "fish infos [x: " << target_fish.x << ", y: " << target_fish.y
           << ", size: " << target_fish.size << " , dist: " << target_fish.dist
           << "]";
      cout << " shark size: " << target_fish.size << "\n";
#ifdef __DDEBUG__
      BFS(target_fish);
#endif
#endif

      if (target_fish.dist == INF) {
#ifdef __DEBUG__
         cout << "GAME OVER: CALL MAMA\n";
#endif
         cout << ans;
         return 0;
      }

      board[shark.x][shark.y] = 0;
      board[target_fish.x][target_fish.y] = 9;

#ifdef __PRINT__
      print_board();
      cout << "current time: " << ans + target_fish.dist << "\n";
#endif

      cur_exp++;
      if (cur_exp >= level[shark.size]) shark.size++;
      shark.x = target_fish.x;
      shark.y = target_fish.y;
      ans += target_fish.dist;
#ifdef __PRINT__
      cout << "current size: " << shark.size << " ate: " << cur_exp << "\n";
#endif
   }

   cout << ans;
}
