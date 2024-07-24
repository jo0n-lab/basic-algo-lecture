#include <bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

int n;
int buf = 1000000;
long long mod = 1000000000;
long long cache[2000002];

long long fibo(int n) {
    cache[0 + buf] = 0;
    cache[1 + buf] = 1;

    for (int i = 2; i <= n; i++)
        cache[i + buf] = (cache[i - 1 + buf] + cache[i - 2 + buf]) % mod;

    for (int i = 1; i >= n; i--)
        cache[i - 2 + buf] = (cache[i + buf] - cache[i - 1 + buf]) % mod;

	return cache[n+buf];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
	
	int ans=fibo(n);
	if(ans>0) cout<<1<<"\n";
	else if(ans==0) cout<<0<<"\n";
	else cout<<-1<<"\n";
    cout << abs(ans);
}
