#include<iostream>

using namespace std;

int cache[100000];
int pos=1;

// int func3(int N){
//     while(cache[pos]<N) cache[++pos]=pos*pos;
//     while(cache[pos]>N) pos--;
//     if (cache[pos]==N) return 1;
//     else return 0;
// }

int func3(int N){
    for(int i=0;i*i<=N;i++){
        if(i*i==N) return 1;
    }
    return 0;
}

int main(){
    cache[0]=0;
    cache[1]=1;

    int N;
    cin>>N;
    cout<<func3(N);
}