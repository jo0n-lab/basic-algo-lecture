#include<bits/stdc++.h>
using namespace std;

int N;
int cnt[2000002];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int buffer=1000000;
	int start=2000002;
	int end=0;

	cin>>N;
	for(int i=0;i<N;i++){
		int input;cin>>input;
		input+=buffer;
		cnt[input]++;
		start=min(start,input);
		end=max(end,input);
	}

	for(;start<=end;start++){
		for(int i=0;i<cnt[start];i++)
			cout<<start-buffer<<"\n";
	}
}

