#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin>>n;
	long long count = 0;
	for (long long i = 2; i * i <= n; i ++)
	{
		long long div = 0;
		while (n % i == 0)
		{
			div += 1;
			n /= i;
		}
		if (div > 0)
		{
			long long subcnt = 1;
			long long total = 0;
			while (div >= subcnt)
			{
				total += 1;
				subcnt += total + 1;
			}
			count += total;
		}
	}
	if (n > 1)
	{
		count += 1;
	}
	cout<<count;
}
