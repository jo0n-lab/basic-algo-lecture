#include<bits/stdc++.h>
using namespace std;


int main(){
	ios::sync_with_stdio(0),cin.tie(0);

	int N;cin>>N;
	int arr[N];
	for(int i=0;i<N;i++) cin>>arr[i];

	int x;cin>>x;

	sort(arr,arr+N);

	int spos=0;int epos=N-1;
	int result=0;

	while(spos<epos){
		if(arr[spos]+arr[epos]<x) spos++;
		else if(arr[spos]+arr[epos]>x) epos--;
		else{
			result++;
			spos++;epos--;
		}
	}

	cout<<result;
}

