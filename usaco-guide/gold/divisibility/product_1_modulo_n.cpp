// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll x;
	cin>>x;

	vector<ll> coprime;
	for (ll i = 1; i < x; i++)
	{
		if (gcd(i,x) == 1)
		{
			coprime.push_back(i);
		}
	}

	ll prefixsum[x];

	prefixsum[0] = 1;
	ll max = 1;
	for (ll i = 1; i < coprime.size(); i++)
	{
		prefixsum[i] = (prefixsum[i - 1] * coprime[i]) % x;
		if (prefixsum[i] == 1)
		{
			max = i + 1;
		}
	}
	cout<<max<<endl;
	for (ll i = 0; i <= max - 1; i++)
	{
		cout<<coprime[i]<<" ";
	}
}
