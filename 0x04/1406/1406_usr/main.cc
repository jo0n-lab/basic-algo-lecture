#include<bits/stdc++.h>

using namespace std;

char dat[100005];
int pre[100005];
int nxt[100005];
int unused=1;


void insert(int addr, char c){
	if(!nxt[addr]){
		dat[unused]=c;
		nxt[addr]=unused;
		pre[unused]=addr;
	}
	else{
		int pre_addr=addr;
		int nxt_addr=nxt[addr];
		dat[unused]=c;
		nxt[addr]=unused;
		pre[unused]=pre_addr;
		nxt[addr]=nxt_addr;
		pre[nxt_addr]=unused;
	}
	unused++;
}

void del(int addr){
	if(dat[addr]){
		int pre_addr=pre[addr];
		int nxt_addr=nxt[addr];
		
		nxt[pre_addr]=nxt_addr;
		pre[nxt_addr]=pre_addr;
	}
}

void traverse(){
	int cursor=1;

	while(dat[cursor]){
		cout<<dat[cursor];
		cursor=nxt[cursor];
	}
}
		



int main(){
	ios::sync_with_stdio(0),cin.tie(0);

	string s;getline(cin,s);
	int M;cin>>M;
	string op;
	int cursor=

	for(int i=0;i<s.length();i++) insert(i,s[i]);

	cin.ignore();
	for(int i=0;i<M;i++){
		getline(cin,op);
		if(op=="L")


