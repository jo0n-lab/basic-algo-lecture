#include<bits/stdc++.h>
using namespace std;

int dat[5005];
int nxt[5005];
int pre[5005];
int length=0;

int cursor=0;

void push_back(int num){	
	dat[length]=num;
	nxt[length]=length+1;
	pre[length]=length-1;
	length++;
}

void jump(int num){ 
	for(int i=0;i<num;i++) cursor=nxt[cursor];
}

void erase(){
	int pre_addr=pre[cursor];
	int nxt_addr=nxt[cursor];
	
	cout<<dat[cursor];

	nxt[pre_addr]=nxt_addr;
	pre[nxt_addr]=pre_addr;

	cursor=nxt_addr;

}


int main(){
	ios::sync_with_stdio(0),cin.tie(0);

	int N,K;cin>>N>>K;
	
	for(int i=0;i<N;i++) push_back(i+1);
	pre[0]=length-1;
	nxt[length-1]=0;

	cout<<"<";
	for(int i=0;i<N-1;i++){
		jump(K-1);
		erase();
		cout<<", ";
	}
	jump(K-1);erase();
	cout<<">";
}	
