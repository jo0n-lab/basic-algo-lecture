#include<bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

int n;
int arr[100002];
int cache[100002];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>arr[i];

	cache[1]=arr[1];
	for(int i=2;i<=n;i++){
		cache[i]=max(arr[i],cache[i-1]+arr[i]);
	}

	cout<<*max_element(cache+1,cache+n+1);
}







