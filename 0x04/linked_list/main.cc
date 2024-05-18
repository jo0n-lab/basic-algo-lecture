#include<bits/stdc++.h>
using namespace std;

cons int MX=1000005;
int dt[MX], pre[MX], nxt[MX];
int unused =1;

fill(pre,pre+MX,-1);
fill(nxt,nxt+MX,-1);

void traverse(){
	int pos;
	while(pos>0){
		pos=nxt[pos];
		cout<<dt[pos]<<" ";
	}
	cout<<"\n";
}
int main(){}

