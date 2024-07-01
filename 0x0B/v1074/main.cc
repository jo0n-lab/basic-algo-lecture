#include<bits/stdc++.h>
using namespace std;

int N,r,c;
int ans=0;

//func def: where located
//input: 
//	dim: to divide row & col, given as N
void visit(int num,int row, int col){
	if(num==-1) return;
	int dim=1<<num;
	int loc=(row/dim)*2 + col/dim;
	ans+=dim*dim*loc;
	visit(num-1,row%dim,col%dim);
}

int main(){
	cin>>N>>r>>c;

	visit(N-1,r,c);
	cout<<ans;
}

