#include<bits/stdc++.h>
using namespace std;

bool test[100];
int main(){
	for(int i=1;i<100;i++){
		if(!test[i])
			cout<<"false\n";
		else
			cout<<"true\n";
	}
}
