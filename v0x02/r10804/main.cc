#include<bits/stdc++.h>
using namespace std;

int arr[21];

void reverse(int a, int b){
    for(int i=0;i<(b-a+1)/2;i++) swap(arr[a+i],arr[b-i]);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    
    for(int i=1;i<=20;i++) arr[i]=i;

    int a,b;
    for(int i=0;i<10;i++){
        cin>>a>>b;
        reverse(a,b);
    }

    for(int i=1;i<=20;i++) cout<<arr[i]<<" ";

}