#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);

    int N;cin>>N;
    int gap;

    for(int i=1;i<=N;i++){
        gap=N-i;
        for(int j=1;j<=gap;j++) cout<<" ";
        for(int j=gap;j<N;j++) cout<<"*";
        cout<<"\n";
    }
}