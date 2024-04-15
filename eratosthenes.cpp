#include "eratosthenes.h"

std::vector<int> sieve(int n) {
    std::vector<int> primes;

	bool* a = new bool[n + 1];
	for (int i = 0; i < n; i++)
		a[i] = 1;

	a[0] = 0;
	a[1] = 0;

	for (int i = 0; i <= n; i++)
	{
		if (a[i])
			for (int j = 2 * i; j <= n; j += i)
				a[j] = false;
	}

	for (int i = 0; i < n; i++)
		if (a[i] == 1)
			primes.push_back(i);

    return primes;
}
