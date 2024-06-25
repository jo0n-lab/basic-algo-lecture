#include<bits/stdc++.h>
using namespace std;

#define __DEBUG__
//#define __INPUT__
#define __PRINT__

int N;
int ropes[100002];

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
		cin>>ropes[i];

#ifdef __INPUT__
	print_config("INPUT");
	for(int i=0;i<N;i++)
		cout<<ropes[i]<<"\n";
#endif

	sort(ropes,ropes+N);

	int ans=0;
	for(int i=0;i<N;i++)
		ans=max(ans,ropes[i]*(N-i));

	cout<<ans;

}

	
