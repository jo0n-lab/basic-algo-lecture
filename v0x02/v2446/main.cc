#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);

    int N;cin>>N;
    int size=2*N-1;
    int b_times;
    int s_times;

    for(int i=0;i<size;i++){
        s_times=2*abs(N-i-1)+1;
        b_times=-abs(N-i-1)+N-1;
        for(int j=0;j<b_times;j++) cout<<" ";
        for(int j=0;j<s_times;j++) cout<<"*";
        cout<<"\n";
    }
}