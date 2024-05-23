#include<bits/stdc++.h>
using namespace std;

//해당 문제는 함수가 아래로 볼록인가 확인하는 문제를 응용
//변곡점!
//
//하지만 여기서는 쌍이므로 해당되지는 않음

int main(){
	ios::sync_with_stdio(0),cin.tie(0);

	int N;cin>>N;
	stack<unsigned int> s;
	//usigned int : 2^32 까지
	unsigned int h;
	int pos=0;

	for(int i=0;i<N;i++)
		cin>>h; s.push(h);

	bool has_lmax=false;
	unsigned int tmp;
	
	int result=0;

	while(a


