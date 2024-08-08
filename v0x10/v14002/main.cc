#include <bits/stdc++.h>
using namespace std;

// #define __DEBUG__
// #define __INPUT__
// #define __PRINT__

#define len first
#define next second

int N;
int seq[1002];
pair<int, int> cache[1002];
// first=length second=index

void print_config(string s) {
   cout.width(25);
   cout.fill('-');
   cout << s << "\n";
}

void print_case(int pos) {
#ifdef __DEBUG__
   print_config(to_string(pos) + " st case begins: " + to_string(seq[pos]));
#endif
   while (pos != -1) {
      cout << seq[pos] << " ";
      pos = cache[pos].next;
   }
   cout << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> N;
   for (int i = 1; i <= N; i++) cin >> seq[i];

   cache[N].len = 1;
   cache[N].next = -1;

   for (int i = N - 1; i >= 1; i--) {
      pair<int, int> tmp = {1, -1};
      for (int j = i + 1; j <= N; j++) {
         if (seq[i] < seq[j] && tmp.len < cache[j].len + 1) {
            tmp.len = cache[j].len + 1;
            tmp.next = j;
         }
      }
      cache[i] = tmp;
#ifdef __DEBUG__
      print_case(i);
#endif
   }

   int longest = 0;
   int pos = 0;
   for (int i = 1; i <= N; i++) {
      if (longest < cache[i].len) {
         longest = cache[i].len;
         pos = i;
      }
   }

   cout << longest << "\n";
   print_case(pos);
}
