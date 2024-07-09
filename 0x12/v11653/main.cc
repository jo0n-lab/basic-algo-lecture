#include<bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

int N;
vector<int> ans;

void factors(int n){
	int tmp=n;
	for(int i=2;i<=tmp;i++){
		while(tmp%i==0) {
			ans.push_back(i);
			tmp/=i;
		}
	}
}

		

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>N;
	factors(N);

	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<"\n";
	}
}




