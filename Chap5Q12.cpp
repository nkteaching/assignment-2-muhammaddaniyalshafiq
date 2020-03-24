#include <iostream>
using namespace std;

void cubes(int n, int i = 1)
{
	cout << i * i * i << " ";
	
	if(i != n)
	{
		cubes(n, i+1);
	}
}

int main()
{
	int n;
	
	cout << "Enter number: ";
	cin >> n;
	
	cubes(n);
}
