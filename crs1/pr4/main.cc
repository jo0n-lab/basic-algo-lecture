#include<iostream>
using namespace std;

// 문제 4
// N이하의 수 중에서 가장 큰 2의 거듭제곱수를 반환하는 함수 func4(int N)을 작성하라. N은 10억 이하의 자연수이다.

int cache[100000];
int pos=0;

// int func4(int N){
//     while(cache[pos]<N) cache[++pos]=cache[pos]*2;
//     while(cache[pos]>N) pos--;
//     return cache[pos];
// }

int func4(int N){
    int val=1;
    for(;val*2<=N;val*=2);
    return val;
}

int main(){
    cache[0]=1;
    int N;
    
    cin>>N;
    cout<<func4(N);
}