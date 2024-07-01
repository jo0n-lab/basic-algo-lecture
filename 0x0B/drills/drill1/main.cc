#include<bits/stdc++.h>
using namespace std;

void sum(int i){
	static int ans=0;
	if(i>100) return;
	ans+=i;
	cout<<"current: "<<i<<" sum: "<<ans<<"\n";
	sum(i+1);
}

int main(){
	sum(0);
}

