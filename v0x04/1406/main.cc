#include<bits/stdc++.h>

using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num){
	dat[unused]=num;
	if(!nxt[addr]){
		nxt[addr]=unused;
		pre[unused]=addr;
	}
	else{
		nxt[unused]=nxt[addr];
		pre[nxt[addr]]=unused;
		nxt[addr]=unused;
		pre[unused]=addr;
	}
	unused++;
}

void erase(int addr){
	int pre_addr=pre[addr];
	int nxt_addr=nxt[addr];

	nxt[pre_addr]=nxt_addr;
	pre[nxt_addr]=pre_addr;
}

void traverse(){
  int cur = nxt[0];
  while(cur != -1){
    cout << dat[cur] << ' ';
    cur = nxt[cur];
  }
  cout << "\n\n";
}



int main(){
	string input;cin>>input;
	int M;cin>>M;
	string s;

	int cur=unused;

	for(int i=0;i<M;i++) {
		cin>>s;
		if(s=="L"&&cursor>0) cursor--;
		else if(s=="D"
}


