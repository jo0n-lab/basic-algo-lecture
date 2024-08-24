#include<bits/stdc++.h>
using namespace std;

int main(){
	set<int> s;

	s.erase(0);
	cout<<*s.begin()<<"\n";
	cout<<*s.end()<<"\n";

	auto it=s.end();
	advance(it,1);
	cout<<*it<<"\n";

}
