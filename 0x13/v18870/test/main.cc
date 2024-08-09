#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> v={1,1,1,1,2,2,2,2,3,3,3,3};
	unique(v.begin(),v.end());

	for(auto i=v.begin();i!=v.end();i++)
		cout<<*i<<" ";
}
