#include<bits/stdc++.h>
using namespace std;

int N,K;
int arr[102];

int main(){
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>arr[i];
	cin>>K;

	int st=1;
	int en=N;
	int mid;
	while(st<en){
		mid=(st+en)/2;
		if(K<=arr[mid])
			en=mid;
		else
			st=mid+1;
	}

	cout<<st;
}


		


