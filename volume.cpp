#include "volume.h"
#include<algorithm>

int getMaxVolume(int a, int b, int c, int n, int* arr) {
	int maxvol = 0, left = 0, right = n - 1;

	while (left + a < n)
	{
		int m = std::min(arr[left], arr[left + a]);
		if (m > maxvol && m <= c)
			maxvol = m;
		left++;
	}
	maxvol *= a;

	while (left < right)
	{
		int t = std::min(arr[left], arr[right]);
		if ((right - left) <= a && t <= c)
			maxvol = std::max(maxvol, t * (right - left));
		if (arr[left] < arr[right])
			left++;
		else
			right--;
	}

	return maxvol * b;
}