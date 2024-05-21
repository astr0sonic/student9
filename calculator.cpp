#include "calculator.h"
#include<cstring>
#include<stack>
#include<map>
#include<list>

bool checkExpression(const std::string& s)
{
	char arr[] = "1234567890.()+-*/^ ";
	std::stack<char> t;
	bool f = true;
	for (int i = 0; i < s.length() && f; i++) {
		if (!strchr(arr, s[i]))
			f = false;
		if (s[i] == '(' || s[i] == ')') {
			if (t.empty()) {
				t.push(s[i]);
			}
			else
				if ((t.top() == '(' && s[i] == ')') || (t.top() == '{' && s[i] == '}')
					|| (t.top() == '[' && s[i] == ']') || (t.top() == '<' && s[i] == '>')) {
					t.pop();
				}
				else {
					t.push(s[i]);
				}
		}
	}

	if (t.empty()) {
		return f * true;
	}
	return false;
}

std::string postfixExp(std::string exp)
{	std::string s;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '-' && exp[i - 1] == '(')
		{
			exp = exp.substr(0, i) + "0 " + exp.substr(i, exp.length() - i);
		}
	}
	std::stack<char> opst;
	std::map<char, int> prio{ {'+',6}, {'-', 6}, {'*',8}, {'/', 8}, {'^', 9}, {'(', -1} };
	for (int i = 0; i < exp.length(); i++)
	{
		char c = exp[i];
		if (c >= 48 && c <= 57 || c == '.' || c == ' ')
		{
			s = s + c;
		}
		else
			if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
				while (!opst.empty() && prio[opst.top()] >= prio[c])
				{
					s = s + opst.top() + ' ';
					opst.pop();
				}
				opst.push(c);
			}
			else
				if (c == '(')
					opst.push(c);
				else
					if (c == ')') {
						while (opst.top() != '(')
						{
							s = s + opst.top() + ' ';
							opst.pop();
						}
						opst.pop();
					}
	}
	while (!opst.empty())
	{
		if (opst.top() == '(')
			exit(1);
		else
			if (opst.top() != '(')
				s = s + opst.top() + ' ';
		opst.pop();
	}
	return s;
}

double st(double a, int b)
{
	double k = a;
	for (int i = 1; i < b; i++)
		k *= a;
	return k;
}

double calculate(const std::string& expr) 
{
	if (!checkExpression(expr)) {
		throw std::exception();
	}
	std::string exp = postfixExp(expr);
	std::list<double>lst;
	std::string num;
	for (int i = 0; i < exp.length(); i++)
	{
		char c = expr[i];
		if (c >= 48 && c <= 57 || c == '.')
		{
			num += c;
		}
		else
		{
			if (num != "") {
				lst.push_back(atof(num.c_str()));
				num = "";
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
			if (c == '^')
			{
				int a = lst.back();
				lst.pop_back();
				double b = lst.back();
				lst.pop_back();
				lst.push_back(st(b, a));
			}
		}
	}
	return lst.back();
}
