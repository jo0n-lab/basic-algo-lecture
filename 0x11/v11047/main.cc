#include <bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

int N, K;
int coins[11];

void print_config(string s) {
   cout.width(20);
   cout.fill('-');
   cout << s << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> N >> K;
   for (int i = 1; i <= N; i++) cin >> coins[i];

   int cnt = 0;
   int amount = 0;
   int target = K;
   for (int i = N; i >= 1; i--) {
      if (target / coins[i] > 0) {
         cnt += target / coins[i];
         target %= coins[i];
      }
   }

   cout << cnt;
}
