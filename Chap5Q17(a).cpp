#include<iostream>
using namespace std;

void check(int i, string s, char ch)
{
	if(i==s.size())
	{
		cout << "Not found";
		return;
	}
	else
	{
		if(s[i] == ch)
		{
			cout << "Found";
			return;
		}
		else
		{
			i++;
			check(i, s, ch);
		}
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
	
	check(0, s, c);
}
