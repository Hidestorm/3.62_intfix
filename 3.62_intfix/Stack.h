#pragma once
#include <vector>
#include <stack>
#include <iostream>
#include <cstdlib>
using namespace std;

char level(char c)
{
	if (c == '+' || c == '-')
		return -2;
	else if
		(c == '*' || c == '/')
		return -1;
	else
		return c;
}
void chIFtoPF(vector<char> &vec)
{
	stack<char> st;
	vector<char> pf;
	for (vector<char>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (level(*it) == *it)
		{
			cout << *it << ' ';
			pf.push_back(*it);
		}
		else
		{
			if (st.empty())
				st.push(*it);
			else if
				(level(st.top()) < level(*it))
				st.push(*it);
			else
			{
				while (!st.empty() && level(st.top()) >= level(*it))
				{
					cout << st.top() << ' ';
					pf.push_back(st.top());
					st.pop();
				}
				st.push(*it);
			}
		}
	}
	while (!st.empty())
	{
		cout << st.top() << ' ';
		pf.push_back(st.top());
		st.pop();
	}
	// 计算后缀法的运算结果	未完成
	
	stack<char> stc;
	char a, b;
	for (vector<char>::iterator pt = pf.begin(); pt != pf.end(); ++pt)
	{
		if (level(*pt) == *pt)
			stc.push(*pt);
		else
		{
			
			switch (*pt)
			{
			case '+':
				a = stc.top();
				stc.pop();
				b = stc.top();
				stc.push(a + b);
				break;
			case'-':
				a = stc.top();
				stc.pop();
				b = stc.top();
				stc.push(a - b);
				break;
			case'*':
				a = stc.top();
				stc.pop();
				b = stc.top();
				stc.push(a * b);
				break;
			case'/':
				a = stc.top();
				stc.pop();
				b = stc.top();
				stc.push(a / b);
				break;
			}
		}
	}
	cout << "result is:" << stc.top();
}