#include<bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

int T;
int M,N;


int gcd(int x,int y){
	if(y==0) return x;
	return gcd(y,x%y);
}
int lcd(int x,int y){
	return (x*y)/gcd(x,y);
}

int what_year(int x, int y){
	int quot=0;
	int year=quot*M+x;
	int res=y%N;
	int LCD=lcd(M,N);

	while(year<=LCD){
		if(year%N==res) return year;
		year=(++quot)*M+x;
	}
	return -1;
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>T;
	for(int i=0;i<T;i++){
		int x,y;
		cin>>M>>N>>x>>y;
		cout<<what_year(x,y)<<"\n";
	}

}
