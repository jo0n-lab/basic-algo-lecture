#include <bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

int N;
int a[22];
int s[22];
int cache[100000000];

void print_config(string s){
	cout.width(20);
	cout.fill('-');
	cout<<s<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>N;
	int ncase=(1<<N);

    for (int i = 1; i <= ncase-1; i++)
        cin >> s[i];

#ifdef __INPUT__
	print_config("INPUT");
	for(int i=1;i<=ncase-1;i++)
		cout<<s[i]<<" ";
	cout<<"\n";
#endif

    a[1] = s[1];
    a[2] = s[2];

    int pos = 2;
    for (int i = 1; i <= (1 << pos); i++) {
        int tmp = i;
        for (int j = 1; j <= pos; j++) {
            cache[i] += (tmp % 2) * a[j];
            tmp /= 2;
        }
    }

#ifdef __DEBUG__
	print_config("UNIT TEST");
    for (int i = 1; i < (1 << pos); i++) 
        cout << cache[i] << " ";
	cout<<"\n";
#endif

	for(int i=3;i<=ncase;i++){
		for(int j=1;j<(1<<pos);j++){
			if(cache[j]
		
    
}
