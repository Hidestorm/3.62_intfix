#include "Stack.h"
#include <queue>
char main()
{
	char c;
	vector<char> vec;
	while (cin >> c)
		vec.push_back(c);
	chIFtoPF(vec);
	system("pause");
	return 0;
}