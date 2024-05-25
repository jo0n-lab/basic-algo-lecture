#include <bits/stdc++.h>
using namespace std;

int main(void) {
  list<int> L = {1,2}; // 1 2
  list<int>::iterator t = L.end(); // t는 1을 가리키는 중
  t = L.erase(t); // t가 가리키는 값을 제거, 그 다음 원소인 5의 위치를 반환
                  // 10 6 1 5, t가 가리키는 값은 5
  cout << *t << '\n'; // 5
  for(auto i : L) cout << i << ' ';
  cout << '\n';
  for(list<int>::iterator it = L.begin(); it != L.end(); it++)
    cout << *it << ' ';
}
