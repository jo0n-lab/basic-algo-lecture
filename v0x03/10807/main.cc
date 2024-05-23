#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);

	int arr[201];fill(arr,arr+201,0);

	int N;cin>>N;
	int num;
	for(int i=0;i<N;i++){
		cin>>num;
		arr[num+100]++;
	}

	int id;cin>>id;
	cout<<arr[id+100];
}
