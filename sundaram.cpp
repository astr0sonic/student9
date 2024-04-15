#include "sundaram.h"

std::vector<int> sieve(int n) {
    std::vector<int> primes;
    primes.push_back(2);

	bool* a = new bool[n + 1];
	for (int i = 0; i <= n; i++)
		a[i] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = i; 2 * i * j + i + j <= n; j++)
		{

			a[2 * i * j + i + j] = 0;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (a[i])
			ans.push_back(2 * i + 1);
	}
    return primes;
}
