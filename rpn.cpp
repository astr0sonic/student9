#include "rpn.h"
#include<list>

double calculateRPN(const std::string& expr) {
	list<double>lst;
	for (int i = 0; i < expr.length(); i++)
	{
		char c = expr[i];
		if (is_digit(c))
		{
			lst.push_back(c - '0');
		}

		if (c == '+')
		{
			double a = lst.back();
			lst.pop_back();
			double b = lst.back();
			lst.pop_back();
			lst.push_back(a + b);
		}
		if (c == '*')
		{
			double a = lst.back();
			lst.pop_back();
			double b = lst.back();
			lst.pop_back();
			lst.push_back(a * b);
		}
		if (c == '-')
		{
			double a = lst.back();
			lst.pop_back();
			double b = lst.back();
			lst.pop_back();
			lst.push_back(b - a);
		}
		if (c == '/')
		{
			double a = lst.back();
			lst.pop_back();
			double b = lst.back();
			lst.pop_back();
			lst.push_back(b / a);
		}
	}
    return lst.back();
}
