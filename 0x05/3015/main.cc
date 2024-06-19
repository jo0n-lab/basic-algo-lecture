#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main(){
	ios::sync_with_stdio(0),cin.tie(0);

	int N;cin>>N;

	stack<pair<int,int>> s;
	long long ans=0;

	for(int i=0;i<N;i++){
		int input;cin>>input;
		int cnt=1;
		
		while(!s.empty()&&s.top().Y>=input)
			s.push({cnt,input});cnt++;
		ans+=cnt;
		
		cnt++;
		while(!s.empty()&&s.top().Y<=input)
			s.push({cnt,input});cnt


