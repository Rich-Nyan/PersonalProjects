// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

long long fact(long long a, long long mod)
{
	if (a == 0)
	{
		return 1;
	}
	return (a * fact(a - 1, mod)) % mod;
}

long long exp(long long a, long long b, long long mod)
{
	if (b == 0)
	{
		return 1;
	}
	long long val = (exp(a, b/2, mod) * exp(a, b/2, mod)) % mod;
	if (b % 2 == 0)
	{
		return (val) % mod;
	}
	return (val * a) % mod;
}

int main() {

	long long a,b;
	cin>>a>>b;
	long long sum = a + b - 1;
	long long total = fact(sum,1000000007);

	long long val = (fact(a - 1,1000000007) * fact(b, 1000000007)) % 1000000007;
	total *= exp(val, 1000000005, 1000000007);
	total %= 1000000007;


	cout<<total<<endl;
}
