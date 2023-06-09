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
	string s;
	cin>>s;

	long long ch[26] = {0};
	for (long long i = 0; i < s.length(); i++)
	{
		ch[((int) s[i]) - 97] += 1;
	}
	long long total = fact(s.length(),1000000007);

	for (int i = 0; i < 26; i++)
	{
		long long val = fact(ch[i],1000000007);
		total *= exp(val, 1000000005, 1000000007);
		total %= 1000000007;
	}
	cout<< total<<endl;
}
