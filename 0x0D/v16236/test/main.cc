#include<bits/stdc++.h>
using namespace std;


struct fo{
	int a;
};


void foo(fo &a){
	a.a=100;
}

int main(){
	fo a;
	a.a=3;
	foo(a);
	cout<<a.a;
}
