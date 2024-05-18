#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);

    long long n1,n2;
    cin>>n1>>n2;

    if(n1>n2){
        long long tmp=n2;
        n2=n1;
        n1=tmp;
    }
    else if(n1==n2){
        cout<<0;
        return 0;
    }

    cout<<n2-n1-1<<"\n";
    for(long long i=n1+1;i<n2;i++) cout<<i<<" ";
}