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

long long numOfDivisors(long long a[], long long length)
{
	long long total = 1;
	for (long long i = 0; i < length; i++)
	{
		total *= (a[i] + 1) ;
		total %= (1000000007);
	}
	return total;
}

long long sumOfDivisors(long long a[], long long b[], long long length)
{
	long long total = 1;
	for (long long j = 0; j < length; j++)
	{
		long long prod = 1;
		a[j] %= 1000000007;
		b[j] %= 1000000007;
		prod *= (exp(a[j],b[j] + 1, 1000000007) - 1);
		prod %= 1000000007;

		prod *= exp(a[j] - 1,1000000005,1000000007); // dividing by p-1 is same as multiplying by (p-1)^(p-2)
		prod %= 1000000007;

		total *= prod;
		total %= (1000000007);
	}
	return total;
}

long long prodOfDivisors(long long a[], long long b[], long long length)
{
	long long product = 1;
	long long numdiv = 1;
	for (long long i = 0; i < length; i++)
	{
		product = exp(product,b[i] + 1,1000000007);
		product %= 1000000007;
		long long exponent = b[i] * (b[i] + 1) / 2; // multiply by number of divisors before a[i] was added
		exponent %= 1000000006; // FLT

		product *= exp(exp(a[i],exponent,1000000007),numdiv,1000000007);
		product %= 1000000007;

		numdiv *= (b[i] + 1); // Increase divisors
		numdiv %= 1000000006;
	}
	return product;
}
int main() 
{
	long long x;
	cin>>x;

	long long base[x], exp[x];
	for (long long i = 0; i < x; i++)
	{
		cin>>base[i]>>exp[i];
	}

	cout<<numOfDivisors(exp,x)<< " " << sumOfDivisors(base,exp,x)<<" "<<prodOfDivisors(base,exp,x);

}
