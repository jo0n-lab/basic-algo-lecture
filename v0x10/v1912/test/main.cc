#include<bits/stdc++.h>
using namespace std;


int main(){
	int num=100;
	int arr[100];

	for(int i=0;i<num;i++)
		arr[i]=i;

	cout<<*min_element(arr+10,arr+100)<<"\n";
	cout<<min_element(arr+10,arr+100)-&arr[0]<<"\n";
	cout<<*max_element(arr+10,arr+100)<<"\n";
	cout<<max_element(arr+10,arr+100)-&arr[0]<<"\n";

}

