#include "eratosthenes.h"

std::vector<int> sieve(int n) {
    std::vector<int> primes;
    primes.push_back(2);

	bool* a = new bool[n];
	for (int i = 0; i < n; i++)
		a[i] = 1;

	for (int p = 0; (p + 2) * (p + 2) <= n; p++)
	{
		for (int i = p + 1; i < n; i++)
		{
			if ((i + 2) % (p + 2) == 0)
				a[i] = 0;
		}
	}

	for (int i = 0; i < n; i++)
		if (a[i] == 1)
			primes.push_back(i + 2);

    return primes;
}
