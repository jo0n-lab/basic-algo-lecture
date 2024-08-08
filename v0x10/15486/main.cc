#include<bits/stdc++.h>
using namespace std;

//#define __DEBUG__
//#define __INPUT__
//#define __PRINT__

int N;
int arr[1500001][2];
int cache[1500001][3];

void print_config(string s){
	cout.width(20);
	cout.fill('-');
	cout<<s<<"\n";
}

void INPUT(){
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>arr[i][0]>>arr[i][1];
#ifdef __INPUT__
	print_config(__func__);
	cout<<N<<"\n";
	for(int i=1;i<=N;i++)
		cout<<arr[i][0]<<" "<<arr[i][1]<<"\n";
#endif
}

void DEBUG(){
	cout<<"\n";
	print_config(__func__);
	for(int i=1;i<=N;i++){
		cout<<cache[i][0]<<" "<<cache[i][1]<<"\n";
	}
}

int solve(){
	cache[1][0]=arr[1][0]+1-1;
	cache[1][1]=arr[1][1];

	int cur_m[2]={cache[1][0],cache[1][1]};
	int avail_m[2]={0,0};
	if

	for(int i=2;i<=N;i++){
		if(
		cache[i][0]=arr[i][0]+i-1;
		cache[i][1]+=arr[i][1];
	}

	int ans=0;
	for(int i=1;i<=N;i++){
		if(cache[i][0]<=N && ans<cache[i][1])
			ans=cache[i][1];
	}

	cout<<ans;
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	INPUT();
	solve();

//	DEBUG();
}
