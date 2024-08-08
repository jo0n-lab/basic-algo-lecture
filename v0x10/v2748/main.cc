#include<bits/stdc++.h>
using namespace std;

int n;
long long cache[92];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	cache[0]=0;
	cache[1]=1;
	for(int i=2;i<=n;i++)
		cache[i]=cache[i-1]+cache[i-2];

	cout<<cache[n];
}

