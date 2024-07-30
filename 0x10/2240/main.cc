#include<bits/stdc++.h>
using namespace std;

#define __INPUT__
#define __PRINT__
#define __DEBUG__

int T,W;
int arr[1002];
int cache1[1002][3];
int cache2[32][1002];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>T>>W;
	for(int i=1;i<=T;i++)
		cin>>arr[i];

	cache[1][1]=1;
	for(int i=2;i<=W;i++){
		for(int j=1;j<=T;j++){



