#include <bits/stdc++.h>
using namespace std;

// #define __DEBUG__
// #define __INPUT__
// #define __PRINT__

int T;
int cache[42][2];

void print_config(string s) {
   cout.width(20);
   cout.fill('-');
   cout << s << "\n";
}

// int fibo(int n){
//	if(n==0) return 0;
//	if(cache[n]!=0) return cache[n];
//	for(int i=2;i<=n;i++){
//		if(cache[i]!=0) continue;
//		cache[i]=cache[i-1]+cache[i-2];
//	}
//
//	return cache[n];
//}

int fibo(int n) {
   if (n == 0 || n == 1) {
      cout << n << " ";
      return n;
   }
   return fibo(n - 1) + fibo(n - 2);
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL);

#ifdef __DEBUG__
   print_config("FIBO_TEST");
   int input;
   cin >> input;
   fibo(input);
   cout << "\n";
   print_config("-");
#endif

   cache[0][0] = 1;
   cache[0][1] = 0;
   cache[1][0] = 0;
   cache[1][1] = 1;

   cin >> T;
   for (int i = 0; i < T; i++) {
      int N;
      cin >> N;

      for (int j = 2; j <= N; j++) {
         if (cache[j][0] != 0 || cache[j][1] != 0) continue;
         cache[j][0] = cache[j - 1][0] + cache[j - 2][0];
         cache[j][1] = cache[j - 1][1] + cache[j - 2][1];
      }

      cout << cache[N][0] << " " << cache[N][1] << "\n";
   }
}
