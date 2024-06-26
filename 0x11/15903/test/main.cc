#include<bits/stdc++.h>
using namespace std;



int main(){
	long long int a[10];
	for(int i=0;i<10;i++)
		a[i]=10-i;

	cout<<*min_element(a,a+10)<<"\n";
	cout<<min_element(a,a+10)-&a[0]<<"\n";
}
