#include <bits/stdc++.h>
using namespace std;

int heap[100005];
int sz = 0; // heap에 들어있는 원소의 수

void print(){
	cout<<"PTINT:: ";
	for(int i=1;i<=sz;i++)
		cout<<heap[i]<<" ";
	cout<<"\n";
}

void push(int x){
	heap[++sz]=x;
	int idx=sz;
	for(int i=sz/2;i>=1;i/=2){
		if(heap[i]>x) {
			swap(heap[i],heap[idx]);
			idx=i;
		}
		else 
			break;
	}
}

int top(){
	if(sz!=0) return heap[1];
	else{
		cout<<"heap is empty!!\n";
		return -1;
	}
}

void pop(){
	if(sz!=0){
		swap(heap[1],heap[sz--]);
		int idx=1;
		while(idx*2<=sz){
			int tar_idx;
			if(idx*2+1<=sz)
				tar_idx=min_element(heap+2*idx,heap+2*idx+2)-heap;
			else tar_idx=idx*2;
			if(heap[idx]>heap[tar_idx])
				swap(heap[idx],heap[tar_idx]);
			else
				break;
		}
	}
	else
		cout<<"heap is empty\n";
}

void test(){
  push(10); push(2); push(5); push(9); // {10, 2, 5, 9}
  
  print();

  cout << top() << '\n'; // 2
  pop(); // {10, 5, 9}
  print();
  pop(); // {10, 9}
  print();
  cout << top() << '\n'; // 9
  print();
  push(5); push(15); // {10, 9, 5, 15}
  print();
  cout << top() << '\n'; // 5
  print();
  pop(); // {10, 9, 15}
  cout << top() << '\n'; // 9
}

int main(){
  test();
}
