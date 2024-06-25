#include<bits/stdc++.h>
using namespace std;

#define __DEBUG__
//#define __INPUT__
#define __PRINT__

int N;
int A[52];
int B[52];

void print_config(string s){
	cout.width(20);
	cout.fill('-');
	cout<<s<<"\n";
}

bool compare(int a,int b){
	return a>b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>N;
	for(int i=0;i<N;i++) cin>>A[i];
	for(int i=0;i<N;i++) cin>>B[i];

#ifdef __INPUT__
	print_config("INPUT");
	for(int i=0;i<N;i++) cout<<A[i]<<" ";
	cout<<"\n";
	for(int i=0;i<N;i++) cout<<B[i]<<" ";
	cout<<"\n";
#endif

	sort(A,A+N);
	sort(B,B+N,compare);

	int ans=0;
	for(int i=0;i<N;i++)
		ans+=A[i]*B[i];

	cout<<ans;


}
	
	


