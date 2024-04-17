#include "volume.h"
#include<algorithm>

int getMaxVolume(int a, int b, int c, int n, int* arr) {
    int maxvol = 0;
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        int t = std::min(arr[left], arr[right]);
        if ((right - left) <= c && t <= a)
            t *= (right - left);
        else
            t = 0;

        maxvol = std::max(maxvol, t);

        if (arr[left] < arr[right])
            left++;
        else
            right--;

    }
    return maxvol * b;
}