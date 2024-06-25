#include<bits/stdc++.h>
using namespace std;


int main(){
	int a[11];
	for(int i=10;i>=1;i--){
		a[10-i]=i;
	}

	sort(a,a+3);

	for(int i=0;i<10;i++){
		cout<<a[i]<<" ";
	}
}
