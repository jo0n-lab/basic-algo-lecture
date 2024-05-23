#include<bits/stdc++.h>
using namespace std;


int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	
	stack<int> ans;

	//재현-잘못 0 외침, 재민 받아씀 
	int K;cin>>K;
	
	int num;
	int result=0;

	for(int i=0;i<K;i++){
		cin>>num;
		if(!num) ans.pop();
		else ans.push(num);
	}

	while(!ans.empty()){
		result+=ans.top();
		ans.pop();
	}

	cout<<result;
}
