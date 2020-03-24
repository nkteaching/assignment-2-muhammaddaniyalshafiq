#include <iostream>
using namespace std;

void recurse(int n)
{
	cout << n << " ";
	
	if(n > 1)
	{
		recurse(n-1);
	}
}

int main()
{
	recurse(10);
}
