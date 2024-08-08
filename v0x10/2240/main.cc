#include<bits/stdc++.h>
using namespace std;

#define __INPUT__
#define __DEBUG__
#define __PRINT__

int T,W;
int time[1002];
int cache[32][1002][1002];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>T>>W;
	for(int i=1;i<=T;i++)
		cin>>time[i];
	time[0]=2;

	int dir=1;
	for(int j=1;j<=T;j++){
		int prev=cache[i][0][j-1];
		if(dir==time[j-1]) prev--;
		if(dir==time[j]) prev++;
		cache[i][j][0]=prev;
	}
	for(int i=1;i<=W;i++){
		for(int j=1;j<=T;j++){
			int prev=cache[i][j-1];
			if(dir==time[j-1]) prev--;
			if(dir==time[j]) prev++;
			cache[i][j]=prev;
		}




