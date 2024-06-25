#include <bits/stdc++.h>
using namespace std;

// #define __DEBUG__
// #define __INPUT__
// #define __PRINT__

#define upper first
#define lower second

int N;
pair<int, int> bound[100002];

void print_config(string s) {
   cout.width(20);
   cout.fill('-');
   cout << s << "\n";
}

bool compare(pair<int, int> a, pair<int, int> b) {
   if (a.lower == b.lower) return a.upper < b.upper;
   return a.lower < b.lower;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> N;
   for (int k = 0; k < N; k++) {
      int i, j;
      cin >> i >> j;
      bound[k] = {i, j};
   }
   sort(bound, bound + N, compare);

#ifdef __PRINT__
   print_config("PRINT");
   for (int i = 0; i < N; i++) {
      cout << bound[i].upper << " " << bound[i].lower << "\n";
   }
#endif

   int ans = 0;
   int booked = -1;
   for (int i = 0; i < N; i++) {
      if (bound[i].upper < booked) continue;
#ifdef __DEBUG__
      print_config("added");
      cout << bound[i].upper << " " << bound[i].lower << "\n";
#endif
      ans++;
      booked = bound[i].lower;
   }

   cout << ans;
}
