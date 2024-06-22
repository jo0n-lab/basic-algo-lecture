#include<bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

#define lower first
#define upper second

int N,M;

vector<int> numbers;
vector<pair<int,int>> bounds;
int cache[100002];

int main(){
	cin>>N>>M;

	for(int i=0;i<N;i++){
		int input;cin>>input;
		numbers.push_back(input);
	}

	for(int k=0;k<M;k++){
		int i,j;cin>>i>>j;
		bounds.push_back({i,j});
	}






