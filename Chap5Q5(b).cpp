#include<iostream>
using namespace std;

void func_odd(int n)
{
	if(n>1)
	{
		func_odd(n-1);
	}
	if(n%2!=0)
	{
		cout << n << " ";
	}
}

int main()
{
	int n;
	cout << "Enter number: ";
	cin >> n;
	
	func_odd(n);
}
