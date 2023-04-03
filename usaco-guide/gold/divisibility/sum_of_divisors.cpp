#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll n;
	cin>>n;

	ll index = 1;
	ll sum = 0;
	while (index <= n)
	{
		ll val = n / index;
		ll maxindex =  n / val;

		ll innersum = (((((index + maxindex)%1000000007) * ((maxindex - index + 1)%1000000007))%1000000007) * (val%1000000007));
		innersum %= 1000000007;
		if (innersum % 2 == 1)
		{
			innersum += 1000000007;
		}
		innersum /= 2;
		index = maxindex + 1;
		sum += innersum;
		sum %= 1000000007;
	}
	cout<<sum;
}
