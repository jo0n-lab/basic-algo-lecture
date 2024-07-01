#include<bits/stdc++.h>
using namespace std;

#define __DEBUG__

int N,r,c;
int ans=0;

#ifdef __DEBUG__
queue<int> Q;
#endif


//func def: where located
//input: 
//	dim: to divide row & col, given as N
void visit(int num,int row, int col){
	if(num==-1) return;
	int dim=1<<num;
	int loc=(row/dim)*2 + col/dim;
#ifdef __DEBUG__
	Q.push(loc);
#endif
	ans+=dim*dim*loc;
	visit(num-1,row%dim,col%dim);
}

int main(){
	cin>>N>>r>>c;

	visit(N-1,r,c);
#ifdef __DEBUG__
	while(!Q.empty()){
		cout<<Q.front()<<" ";
		Q.pop();
	}
	cout<<"\n";
#endif
	cout<<ans;
}

