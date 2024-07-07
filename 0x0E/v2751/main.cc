#include<bits/stdc++.h>
using namespace std;

int N;
int is_exist[2000002];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int buffer=1000000;
	int start=1000002;
	int end=0;

	cin>>N;
	for(int i=0;i<N;i++){
		int input;cin>>input;
		input+=buffer;
		is_exist[input]=1;
		start=min(start,input);
		end=max(end,input);
	}

	for(;start<=end;start++){
		if(is_exist[start]==1)
			cout<<start-buffer<<"\n";
	}
}

