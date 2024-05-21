#include "kmp.h"
#include<vector>

void prefFunc(std::string P, int*& arr)
{
	int len = 0;
	arr[0] = 0;
	int c = 1;
	while (c < P.length()) {
		if (P[c] == P[len]) {
			len++;
			arr[c] = len;
			c++;
		}
		else
		{
			if (len != 0) {
				len = arr[len - 1];
			}
			else
			{
				arr[c] = 0;
				c++;
			}
		}
	}
}

std::vector<int> getIndices(const std::string& my_template, const std::string& text) {
	std::vector<int> result;
	std::string P = my_template, T = text;
	int pl = P.length(), tl = T.length();
	int* arr = new int[pl];
	prefFunc(P, arr);
	int i = 0, j = 0;
	while ((tl - i) >= (pl - j)) {
		if (P[j] == T[i]) {
			i++; j++;
		}
		if (j == pl) {
			result.push_back(i - j);
			j = arr[j - 1];
		}
		else
			if (i < tl && P[j] != T[i]) {
				if (j != 0)
					j = arr[j - 1];
				else
					i++;
			}
	}
	return result;
}
