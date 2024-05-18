#include<bits/stdc++.h>
using namespace std;

int arr[101];

int main(){
	ios::sync_with_stdio(0),cin.tie(0);

	int N;cin>>N;
	int num[N];
	for(int i=0;i<N;i++){
		cin>>num[i];
		arr[100-num[i]]=1;
		if(arr[num[i]]){
			cout<<1;
			return 0;
		}
	}
	cout<<0;
}
