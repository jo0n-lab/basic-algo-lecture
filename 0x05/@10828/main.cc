#include<bits/stdc++.h>
using namespace std;


int arr[10005];
int top=0;

void push(int num){
	arr[top++]=num;
}
int pop(){
	if(top) return arr[--top];
	return -1;
}


int main(){
	ios::sync_with_stdio(0),cin.tie(0);

	int N;cin>>N;
	string op;
	int num;
	
	for(int i=0;i<N;i++){
		cin>>op;
		if(op=="push"){
			cin>>num;
			push(num);
		}
		else if(op=="pop") cout<<pop()<<"\n";
		else if(op=="size") cout<<top<<"\n";
		else if(op=="empty"){
			if(top) cout<<0;
			else cout<<1;
			cout<<"\n";
		}
		else if(op=="top"){
			if(top) cout<<arr[top-1];
			else cout<<-1;
			cout<<"\n";
		}
	}
}
