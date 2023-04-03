// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

long long exp(long long a, long long b, long long mod)
{
	if (b == 0)
	{
		return 1;
	}
	if (b % 2 == 0)
	{
		long long val = (exp(a, b/2, mod) * exp(a, b/2, mod)) % mod;
		return (val) % mod;
	}
	else 
	{
		long long val = (exp(a, b/2, mod) * exp(a, b/2, mod)) % mod;
		return (val * a) % mod;
	}
}
int main() 
{
	int n;
	cin>>n;
	for (int v = 0; v < n; v++)
	{
		long long x,y,z;
		cin>>x>>y>>z;
		long long firstdiv = 1000000006;
		long long seconddiv = 1000000007;

		long long modulo = exp(y,z,firstdiv);

		long long modulo2 = exp(x,modulo,seconddiv);
		cout<<modulo2<<endl;
	}	
}
