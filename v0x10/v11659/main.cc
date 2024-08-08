#include <bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

int numbers[100002];
int cache[100002];

int N, M;

void print_config(string s) {
   cout.width(20);
   cout.fill('-');
   cout << s << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> N >> M;

   cache[0] = 0;
   for (int i = 1; i <= N; i++) {
      cin >> numbers[i];
      cache[i] += cache[i - 1] + numbers[i];
   }
   for (int k = 1; k <= M; k++) {
      int i, j;
      cin >> i >> j;
      cout << cache[j] - cache[i - 1] << "\n";
   }
}
