#include<bits/stdc++.h>
using namespace std;


int main(){
	int a[10];
	for(int i=0;i<10;i++)
		a[i]=10-i;

	sort(a,a+10);
	for(int i=0;i<10;i++)
		cout<<a[i]<<" ";
}
