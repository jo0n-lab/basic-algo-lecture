#include<bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

#define upper second
#define lower first


int N,M;
int board[2002];
int question[1000002][2];

void print_config(string s){
	cout.width(20);
	cout.fill('-');
	cout<<s<<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>board[i];
	cin>>M;
	for(int k=0;k<M;k++){
		int i,j;
		cin>>i>>j;

