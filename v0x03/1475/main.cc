#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);

	string N;cin>>N;
	int arr[10];
	fill(arr,arr+10,0);
	
	for(int i=0;i<N.length();i++)
		arr[N[i]-'0']++;

	int M=(arr[6]+arr[9])/2+(arr[6]+arr[9])%2;


	for(int i=0;i<10; i++){
		if(i==6 || i==9) continue;
		M=max(arr[i],M);
	}

	cout<<M;
}
