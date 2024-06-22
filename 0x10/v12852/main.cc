#include <bits/stdc++.h>
using namespace std;

// #define __DEBUG__
// #define __INPUT__
// #define __PRINT__

#define INF 1000000

int cache[1000002][2];
int N;

void print_config(string s) {
   cout.width(20);
   cout.fill('-');
   cout << s << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> N;

   cache[1][0] = 0;
   cache[1][1] = 0;
   int start = 2;

   for (int i = 2; i <= N; i++) {
      int res1, res2, res3;
      res2 = INF;
      res3 = INF;

      res1 = cache[i - 1][0] + 1;
      if (i % 2 == 0) res2 = cache[i / 2][0] + 1;
      if (i % 3 == 0) res3 = cache[i / 3][0] + 1;

      int res = min({res1, res2, res3});
      cache[i][0] = res;

      if (res == res1)
         cache[i][1] = i - 1;
      else if (res == res2)
         cache[i][1] = i / 2;
      else
         cache[i][1] = i / 3;

#ifdef __DEBUG__
      if (res == INF) cout << "something wrong: " << i;
#endif
   }

   cout << cache[N][0] << "\n";

   int ans = N;
   while (ans != 0) {
      cout << ans << " ";
      ans = cache[ans][1];
   }
}
