#include<bits/stdc++.h>
using namespace std;

int arr[102];
int N,target;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>arr[i];
	sort(arr+1,arr+N+1);
	cin>>target;
	

	int st=1;
	int en=N;
	int mid;
	while(st<en){
		mid=(st+en)/2;
		if(arr[mid]<target)
			st=mid+1;
		else
			en=mid;
	}
	cout<<arr[mid]<<" "<<mid;
}
		

	

