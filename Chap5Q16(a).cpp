#include <iostream>
using namespace std;

void checkPalindrome(char str[], int backItr, int halfSize, int forwardItr, bool check)
{	
	if(halfSize!=0 && check)
	{
		if(str[backItr] == str[forwardItr])
		{
			checkPalindrome(str, --backItr, --halfSize, ++forwardItr, true);
		}
		
		else
		{
			checkPalindrome(str, --backItr, --halfSize, ++forwardItr, false);
		}
	}
	
	else
	{
		if(check)
		{
			cout << "Yes it's palindrome";
		}
		
		else
		{
			cout << "No it's not a palindrome";
		}
	}
}

int main()
{
	int n;
	
	cout << "Enter size of string: ";
	
	cin >> n;
	
	char str[n];
	
	cout << "Enter string: ";
	
	for(int i = 0;i < n;i++)
	{
		cin >> str[i];
	}
	
	checkPalindrome(str, n - 1, n/2, 0, true);
}
