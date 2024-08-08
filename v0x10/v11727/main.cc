#include<bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

int cache[1002];
int N;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>N;

	cache[1]=1;
	cache[2]=3;

	for(int i=3;i<=N;i++){
		cache[i]+=cache[i-1];
		cache[i]+=cache[i-2]*2;
		cache[i]%=10007;
	}

	cout<<cache[N];
}
