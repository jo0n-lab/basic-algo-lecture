#include<bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

long long cache[1002][1002];
int mod=10007;

void facto(int n){
	for(int i=1;i<=n;i++){
		cache[i][0]=1;
		cache[i][i]=1;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i-1;j++){
			cache[i][j]=cache[i-1][j]+cache[i-1][j-1];
			cache[i][j]%=mod;
		}
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N,K;
	cin>>N>>K;

	facto(N);
	cout<<cache[N][K];
}

