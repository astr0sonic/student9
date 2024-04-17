#include "max_value.h"

double calculateMaxValue(double* nums, int n) {

	double vmax = nums[0], vmin = nums[0];
	for (int i = 1; i < n; i++)
	{
		if (nums[i] > 0)
		{
			vmax = std::max({ vmax + nums[i], vmax * nums[i], vmax / nums[i] });
			vmin = std::min({ vmin - nums[i], vmin * nums[i], vmin / nums[i] });
		}
		else
			if (nums[i] < 0)
			{
				double m = vmax;
				vmax = std::max({ vmax - nums[i], vmin * nums[i], vmin / nums[i] });
				vmin = std::min({ vmin + nums[i], m * nums[i], m / nums[i] });
			}
			else
			{
				vmax = std::max(0.0, vmax);
				vmin = std::min(0.0, vmin);
			}
	}

	return vmax;
}
