#include <bits/stdc++.h>
using namespace std;

//#define __DEBUG__

int N;
int price[1002];
int cache[1002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	
	cin>>N;
    for (int i = 1; i <= N; i++)
        cin >> price[i];

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        cache[i] = price[i];
        for (int j = 1; j <= i / 2; j++) {
            int tmp = cache[j] + cache[i - j];
            cache[i] = max(cache[i], tmp);
        }
    }

#ifdef __DEBUG__
	for(int i=1;i<=N;i++)
		cout<<cache[i]<<" ";
	cout<<"\n";
#endif

    cout << cache[N];

	
}
