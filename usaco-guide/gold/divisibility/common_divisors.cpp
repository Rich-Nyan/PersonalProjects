/* Online C++ Compiler and Editor */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin>>n;
   
   int a[n];
   for (int i = 0; i < n; i++)
   {
       cin >> a[i];
   }
   
   int total[1000001] = {0};
   
   for (int i = 0; i < n; i++)
   {
       for (int j = 1; j * j <= a[i]; j++)
       {
           if (a[i] % j == 0)
           {
                total[j] += 1;
                if (j * j != a[i])
                {
                    total[a[i]/j] += 1;
                }
           }
       }
   }
   
   for (int i = 1000001; i > 0; i--)
   {
       if (total[i] >= 2)
       {
           cout<<i;
           break;
       }
   }
}
