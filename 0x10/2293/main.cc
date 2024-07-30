#include<bits/stdc++.h>
using namespace std;

#define __INPUT__
#define __PRINT__
#define __DEBUG__

int n,k;
int arr[102];
int cache[10002];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	sort(arr,arr+n);
	
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){


			

#ifdef __DEBUG__
	cout<<"DEBUG\n";
	for(int i=1;i<=k;i++)
		cout<<cache[i]<<"\n";
	cout<<"\n";
#endif

	cout<<cache[k];
}

	

	 


