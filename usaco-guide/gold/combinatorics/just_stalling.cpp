#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int k;
    cin>> k;
    int a[k], b[k];
    
    for (int i = 0; i < k; i++){
      cin>>a[i];
    }
    for (int i = 0; i < k; i++){
      cin>>b[i];
    }
    sort(a,a+k);
    int valid[k];
    for (int i = 0; i < k; i++){
        valid[i] = 0;
    }
    for (int i = 0; i < k;  i++){
        for (int j = 0; j < k ; j++) {
                 if (a[i] <= b[j]){
                     valid[i] += 1;
                 } 
        }
    }
    int count = 0;
    long long total = 1;
    for (int i = k - 1; i >= 0; i--){
        total *= (valid[i] - count);
        count += 1;
    }
    cout<< total;
}
