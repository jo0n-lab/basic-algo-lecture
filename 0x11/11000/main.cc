#include <bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

#define lower first
#define upper second

int N;
pair<int, int> table[200002];

void print_config(string s) {
   cout.width(20);
   cout.fill('-');
   cout << s << "\n";
}

bool compare(pair<int, int> a, pair<int, int> b) {
   if (a.upper == b.upper) return a.lower < b.lower;
   return a.upper < b.upper;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> N;
   for (int k = 0; k < N; k++) {
      int i, j;
      cin >> i >> j;
      table[k] = {i, j};
   }
   sort(table, table + N, compare);

   int ans = 0;
   int booked = -1;
	
	for
   for (int i = 0; i < N; i++) {
      if (table[i].lower < booked) continue;
      booked = table[i].upper;
      ans += 1;
   }

   cout <<N- ans;
}
