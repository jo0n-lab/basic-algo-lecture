#include<bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

int n,m;
long long int card[1000002];

int min_i(int 


void print_config(string s){
	cout.width(20);
	cout.fill('-');
	cout<<s<<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>card[i];

	
	//tmp & ans: long long int 
	//avoid out of range
	
	for(int i=0;i<m;i++){
		int m_idx1=min_element(num.begin(),num.end()

