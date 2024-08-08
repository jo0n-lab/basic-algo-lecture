#include<bits/stdc++.h>
using namespace std;

#define __INPUT__
#define __PRINT__
#define __DEBUG__

int N;
long long cache[92][2];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>N;


	cache[1][1]=1;
	cache[2][0]=1;

	for(int i=3;i<=N;i++){
		cache[i][0]=cache[i-1][0]+cache[i-1][1];
		cache[i][1]=cache[i-1][0];
	}

	cout<<cache[N][0]+cache[N][1];
}



