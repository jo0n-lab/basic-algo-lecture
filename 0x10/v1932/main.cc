#include<bits/stdc++.h>
using namespace std;

//#define __INPUT__
//#define __PRINT__
//#define __DEBUG__

int n;
int tri[502][502];
int cache[502][502];

void print_config(string s){
	cout.width(20);
	cout.fill('-');
	cout<<s<<"\n";
}

void print_tri(){
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			cout<<tri[i][j]<<" ";
		}
		cout<<"\n";
	}
}
void print_cache(){
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			cout<<cache[i][j]<<" ";
		}
		cout<<"\n";
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			cin>>tri[i][j];
		}
	}

#ifdef __INPUT__
	print_config("INPUT");
	print_tri();
#endif

	cache[0][0]=tri[0][0];
	for(int i=1;i<n;i++){
		for(int j=0;j<=i;j++){
			cache[i][j]=max(cache[i-1][j],cache[i-1][j-1])+tri[i][j];
		}
	}
	int ans=0;
	for(int j=0;j<n;j++)
		ans=max(ans,cache[n-1][j]);

#ifdef __DEBUG__
	print_config("DEBUG");
	print_cache();
#endif


	cout<<ans;
}

