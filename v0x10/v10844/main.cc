#include <bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

int cache[102][10];
int N;

void print_config(string s) {
   cout.width(20);
   cout.fill('-');
   cout << s << "\n";
}

// for duplicates, grant order
// rather than considering both sides, <->
// operate from unique direction ->

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> N;

   for (int i = 0; i <= 9; i++) cache[1][i] = 1;

   for (int i = 2; i <= N; i++) {
      for (int j = 1; j <= 8; j++) {
         cache[i][j] += cache[i - 1][j + 1];
         cache[i][j] += cache[i - 1][j - 1];
      }
      cache[i][0] += cache[i - 1][0 + 1];
      cache[i][9] += cache[i - 1][9 - 1];

      for (int j = 0; j <= 9; j++) {
#ifdef __DEBUG__
         if (cache[i][j] < 0)
            cout << "something wrong, length: " << i << " num: " << j << "\n";
#endif
         cache[i][j] %= 1000000000;
      }
   }

   long long int ans = 0;
   for (int i = 1; i <= 9; i++) ans += cache[N][i];
   cout << ans % 1000000000;
}
