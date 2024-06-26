#include<bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

int N;
int ATM[1002];
int sum[1002];

void print_config(string s){
	cout.width(20);
	cout.fill('-');
	cout<<s<<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>N;
	for(int i=0;i<N;i++)
		cin>>ATM[i];

	sort(ATM,ATM+N);
	sum[0]=ATM[0];
	int ans=sum[0];
	for(int i=1;i<N;i++){
		sum[i]+=sum[i-1]+ATM[i];
		ans+=sum[i];
	}
	cout<<ans;
}
