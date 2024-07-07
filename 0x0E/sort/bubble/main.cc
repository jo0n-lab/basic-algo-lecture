#include <bits/stdc++.h>
using namespace std;

int N;
int num[100002];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> num[i];

    cout << "INPUT\n";
    for (int i = 0; i < N; i++)
        cout << num[i] << " ";
    cout << "\n";

   for (int i = 0; i < N; i++) {
       int tmp = num[i];
       for (int j = i + 1; j < N; j++) {
           if (tmp > num[j]) {
               tmp = num[j];

               swap(num[i], num[j]);
           }
       }
   }
	

    cout << "SORTED\n";
    for (int i = 0; i < N; i++)
        cout << num[i] << " ";
    cout << "\n";
}
