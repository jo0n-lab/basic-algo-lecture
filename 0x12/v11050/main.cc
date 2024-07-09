#include<bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

int N,K;
int factos[11];

void facto(){
	factos[0]=1;
	for(int i=1;i<=10;i++)
		factos[i]=i*factos[i-1];
}
	

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>N>>K;
	
	facto();
	cout<<factos[N]/(factos[K]*factos[N-K]);
}

