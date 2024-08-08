#include <iostream>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>

using namespace std;

int arr[22];

int main()
{
	int T=10;
	cout<<T<<"\n";

	for(int t=0;t<T;t++){
		int n=rand()%20+1;
		cout<<n<<"\n";
		for (int i = 0; i < n; ++i)
			arr[i]=rand()%10000+1;
		sort(arr,arr+n);
		for (int i = 0; i < n; ++i)
			cout<<arr[i]<<" ";
		cout<<"\n";
		cout<<rand()%10000+1<<"\n";
	}
	

}
