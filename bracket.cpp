#include "bracket.h"
#include<string>
#include<stack>

bool checkBrackets(const std::string& s) {
	std::stack<char> t;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(' || s[i] == ')' || s[i] == '{' || s[i] == '}' ||
			s[i] == '[' || s[i] == ']' || s[i] == '<' || s[i] == '>') {
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
		return true;
	}
	return false;
}
