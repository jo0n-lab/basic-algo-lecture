#include<bits/stdc++.h>
using namespace std;

int N;
int cache[1002][2];
// first SK second CY
string player[2]={"SK","CY"};

int main(){
	ios::sync_with_stidio(false);
	cin.tie(NULL);

	cin>>N;

	cache[1]=0;
	cache[2]=1;
	cache[3]=0;
	for(int i=4;i<=N;i++){
		cache[i][0]=cache[i-3]*cache[i-1];
	}

		



