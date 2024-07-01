#include<bits/stdc++.h>
using namespace std;

//TODO implement func return $a^b$ mod m

int m;
int func(int a,int b){
	static int result=1;

	result*=a;
	result%=m;
	cout<<"current: "<<b<<"\n";
	
	if(b==1) return result;
	else return func(a,b-1);
}


int main(){
	cout<<"input value a, b, m\n";
	int a,b;
	cin>>a>>b>>m;

	int ans=func(a,b);
	cout<<"ans: "<<ans;
}


