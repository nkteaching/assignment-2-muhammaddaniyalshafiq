#include<iostream>
using namespace std;

int check(int i, string s, char ch)
{
	static int count = 0;
	if(i == s.size())
	{
		if(i == 0)
		{
			cout << "Not found";
			return count;
		}
	}
	else
	{
		if(s[i] == ch)
		{
			count++;
			i++;
		}
		
		else
		{
			i++;
			
		}
		
		return check(i, s, ch);
	}
}

int main()
{
	string s;
	char c;
	
	cout << "Enter word:";
	cin >> s;
	cout << "Enter character which you want to search:";
	cin >> c;
	
	int count = check(0, s, c);
	
	cout << "Total amount of character present in word:" << count;
}
