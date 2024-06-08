#include <bits/stdc++.h>
using namespace std;

// #define __INPUT__
// #define __DEBUG__
// #define __PRINT__

#define X first
#define Y second

int N;

int const_board[22][22];
int board[22][22];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
string dirs[4] = {"left", "right", "up", "down"};

void print_board() {
   cout << "--------board---------" << "\n";
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         cout.width(3);
         cout << left << board[i][j];
      }
      cout << "\n";
   }
   cout << "----------------------" << "\n";
}

void reset_board() {
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         board[i][j] = const_board[i][j];
      }
   }
}

int find_max() {
   int M = 0;
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         M = max(board[i][j], M);
      }
   }
   return M;
}

void move(int dir) {
   // dir	arrow	init	inc
   // 0		left	0		+1
   // 1		right	N-1	-1
   // 2		up		0		+1
   // 3		down	N-1	-1

   // update configs
   int inc, init;
   if (dir == 0 || dir == 2) {
      init = 0;
      inc = 1;
   } else {
      init = N - 1;
      inc = -1;
   }
   int cnt = 0;

#ifdef __DEBUG__
   cout << "-----" << __FUNCTION__ << " " << dirs[dir] << "-----\n";
   cout << "initial pos: " << init << " inc: " << inc << "\n";
#endif

   // move left or right
   if (dir == 0 || dir == 1) {
      for (int i = 0; i < N; i++) {
         int tmp = board[i][init];
         int pos = init;
         // consider if starts with 0
         for (int j = init + inc; j < N && j >= 0; j += inc) {
            if (!board[i][j])  // ignore when 0
               continue;
            if (!tmp)
               tmp = board[i][j];
            else if (tmp == board[i][j]) {
               board[i][pos] = tmp * 2;
               pos += inc;
               tmp = 0;
            } else if (tmp != board[i][j]) {
               if (tmp) {
                  board[i][pos] = tmp;
                  pos += inc;
               }
               tmp = board[i][j];
            }
         }
         if (tmp) {
            board[i][pos] = tmp;
            pos += inc;
         }
         for (; pos < N && pos >= 0; pos += inc) board[i][pos] = 0;
#ifdef __DEBUG__
         cout << " board updated ";
         cout << "row: " << i << "\n";
#endif
      }
   }

   // move up or down
   else if (dir == 2 || dir == 3) {
      for (int j = 0; j < N; j++) {
         int tmp = board[init][j];
         int pos = init;
         // consider if starts with 0
         for (int i = init + inc; i < N && i >= 0; i += inc) {
            if (!board[i][j])  // ignore when 0
               continue;
            if (!tmp)
               tmp = board[i][j];
            else if (tmp == board[i][j]) {
               board[pos][j] = tmp * 2;
               pos += inc;
               tmp = 0;
            } else if (tmp != board[i][j]) {
               if (tmp) {
                  board[pos][j] = tmp;
                  pos += inc;
               }
               tmp = board[i][j];
            }
         }
         if (tmp) {
            board[pos][j] = tmp;
            pos += inc;
         }
         // update remainders with 0
         for (; pos < N && pos >= 0; pos += inc) board[pos][j] = 0;
#ifdef __DEBUG__
         cout << " updating board ";
         cout << "col: " << j << "\n";
#endif
      }
   }

#ifdef __DEBUG__
   cout << "--------------------\n";
#endif
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   //	exc: 보드 1칸짜리일때

   // receiving inputs
   cin >> N;
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         cin >> const_board[i][j];
      }
   }
#ifdef __INPUT__
   print_board();
#endif

   if (N == 1) {
      cout << const_board[0][0];
      return 0;
   }

   int n_cases = 1 << (2 * 5);  // 경우의 수: 4^5
   int ans = 0;

   for (int cas = 0; cas < n_cases; cas++) {
      reset_board();
#ifdef __PRINT__
      cout << ">>>>>>>" << "case starts" << "<<<<<<<\n";
      print_board();
#endif
      int tmp = cas;
      for (int page = 0; page < 5; page++) {
         int dir = tmp % 4;
         tmp /= 4;
         move(dir);
#ifdef __PRINT__
         print_board();
#endif
      }
      ans = max(ans, find_max());
#ifdef __PRINT__
      cout << ">>>>>>>" << "case ended." << "<<<<<<<\n";
#endif
   }
   cout << ans;
}
